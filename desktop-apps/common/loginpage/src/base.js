/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

/*
*   base controller declaration
*/

+function() {
    var controller = function(args) {
        this.$menuitem = this.$panel = undefined;
    };

    controller.prototype.view = undefined;
    controller.prototype.init = function() {
        this.view && this.view.init();
    };

    var view = function(args) {
        this.rendered = false;

        var _action = args.action ? `action="${args.action}"` : '';
        var _itemcls = 'menu-item' + (args.itemcls?` ${args.itemcls}`:'');

        this.tplPage = args.tplPage || '<div class="center-panel">Hello, Word!</div>';
        this.tplItem = args.tplItem || `<li class="${_itemcls}"><a l10n ${_action}>${args.itemtext}</a></li>`;
        this.menuContainer = args.menu || '';
        this.panelContainer = args.field || '';
        this.opts = args;
    };

    view.prototype.init = function() {
    };

    view.prototype.render = function() {
        if (!this.rendered) {
            this.rendered = true;

            let _index = this.opts.itemindex;
            this.$menuitem = this.renderMenuItem.call(this, this.tplItem, _index);

            if (this.tplPage != 'empty') {
                let $parentview = $(this.panelContainer);
                if (_index >= 0) {
                    let $panels = $parentview.children();
                    this.$panel = $panels.size() > _index ?
                        $(this.tplPage).insertBefore($panels.eq(_index)) : $(this.tplPage).appendTo($parentview);

                        let a = $panels.eq(_index);
                        let b = 1;
                } else {
                    this.$panel = $(this.tplPage).appendTo($parentview);
                }
            }
        }
    };

    view.prototype.renderMenuItem = function(node, index) {
        let $itemout;
        if (node != 'nomenuitem') {
            $itemout = $(node);

            let _ib = utils.fn.getToolMenuItemOrder($itemout);
            if ( !_ib.item ) {
                let $menu = $(this.menuContainer);
                $itemout.appendTo($menu);
            } else {
                _ib.after ? $itemout.insertAfter(_ib.item) : $itemout.insertBefore(_ib.item);
            }
        }

        return $itemout;
    };

    window.baseView = view;
    window.baseController = controller;
}();

