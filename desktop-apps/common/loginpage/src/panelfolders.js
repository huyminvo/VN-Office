/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/


/*
*   new inherited controller declaration
*/

+function(){ 'use strict'
    var ControllerFolders = function(args={}) {
        args.caption = 'Recent folders';
        args.action =
        this.action = "open";
        this.view = new ViewFolders(args);
    };

    ControllerFolders.prototype = Object.create(baseController.prototype);
    ControllerFolders.prototype.constructor = ControllerFolders;

    const isSvgIcons = window.devicePixelRatio >= 2 || window.devicePixelRatio === 1;
    var ViewFolders = function(args) {
        var _lang = utils.Lang;

        args.id&&(args.id=`"id=${args.id}"`)||(args.id='');

        //language=HTML
        args.tplPage = `
            <div ${args.id} class="action-panel ${args.action}">
                <div class="open-panel-container">
                    <div class="file-list-title">
                        <h3 l10n>${_lang.listRecentDirTitle}</h3>
                    </div>
                    <section id="area-dnd-file"></section>
                    <div class="file-list-body"></div>
                    <div id="box-open-acts">
                        <button id="btn-openlocal" class="btn btn--primary" l10n>${_lang.btnBrowse}</button>
                    </div>
                </div>
            </div>`;
        args.menu = '.main-column.tool-menu';
        args.field = '.main-column.col-center';
        args.itemindex = 1;
        // args.itemtext = _lang.actOpenLocal
        args.tplItem = 'nomenuitem';

        baseView.prototype.constructor.call(this, args);
    };

    ViewFolders.prototype = Object.create(baseView.prototype);
    ViewFolders.prototype.constructor = ViewFolders;

    window.ControllerFolders = ControllerFolders;

    utils.fn.extend(ControllerFolders.prototype, (function() {
        var _on_update = function(params) {
            var _dirs = utils.fn.parseRecent(params, 'folders'), $item;
            _dirs.sort((a, b) => {
                if (a.pinned && !b.pinned) return -1;
                if (!a.pinned && b.pinned) return 1;
                return 0;
            });

            const $listRecentDirs = this.view.$panel.find('.file-list-body');

            $listRecentDirs.empty();

            for (let dir of _dirs) {
                if (!utils.getUrlProtocol(dir.full)) {
                    $item = $(app.controller.recent.view.listitemtemplate(dir));

                if (dir.pinned) {
                    $item.addClass('pinned');
                }

                $item.find('.col-pin .btn-quick').click(function (e) {
                    
                    const folderPath = dir.full;
                    const newPinState = utils.fn.pinnedFolders(folderPath, 'toggle');
                    
                    $item.toggleClass('pinned', newPinState);
                    
                    _on_update.call(this, params);
                }.bind(this));

                $item.click({path: dir.full}, e=>{
                        openFile(OPEN_FILE_FOLDER, e.data.path);

                        e.preventDefault();
                        return false;
                });

                    $listRecentDirs.append($item);
                }
            }

            if ($listRecentDirs.length) {
                this.dndZone.hide();
                $('#btn-openlocal').show();
            }
        };

        return {
            init: function() {
                baseController.prototype.init.apply(this, arguments);

                this.view.render();

                this.dndZone = new DnDFileZone();
                this.dndZone.render(this.view.$panel.find("#area-dnd-file"));

                $('#btn-openlocal').hide();

                this.view.$panel.find('#btn-openlocal').click(()=>{
                    openFile(OPEN_FILE_FOLDER, '');
                });

                // window.CommonEvents.on("icons:svg", (pasteSvg)=>{
                //     let emptylist = $('[class*="text-emptylist"]', '#box-recent-folders');
                //     emptylist.toggleClass('text-emptylist text-emptylist-svg');
                //     if(pasteSvg && !emptylist.find('svg').length)
                //         emptylist.prepend($('<svg class = "empty-folder"><use xlink:href="#folder-big"></use></svg>'));
                // });

                window.sdk.on('onupdaterecents', _on_update.bind(this));

                return this;
            }
        };
    })());
}();

/*
*   controller definition
*/

// window.CommonEvents.on('main:ready', function(){
//     var p = new ControllerFolders({});
//     p.init();
// });