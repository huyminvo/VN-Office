/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

/*
    'welcome' panel 
    controller + view
*/

+function(){ 'use strict'
    var ControllerWelcome = function(args={}) {
        args.caption = 'Welcome panel';
        args.action = 
        this.action = "welcome";

        this.view = new ViewWelcome(args);
    };

    ControllerWelcome.prototype = Object.create(baseController.prototype);
    ControllerWelcome.prototype.constructor = ControllerWelcome;

    var ViewWelcome = function(args) {
        var _lang = utils.Lang;

        var _html = `<div class="action-panel ${args.action}">
                      <div class="flex-center">
                        <section class="center-box">
                          <h3 style="margin-top:0;" l10n>${_lang.welWelcome}</h3>
                          <h4 class="text-description" l10n>${_lang.welDescr}</h4>
                          <imagewelcome>
                          <div class="tools-connect">
                            <button class="btn btn--landing newportal" l10n>${_lang.btnCreatePortal}</button>
                            <section class="link-connect">
                              <label l10n>${_lang.textHavePortal}</label>
                              <a class="login link" href="#" l10n>${_lang.btnConnect}</a>
                            </section>
                          </div>
                        </section>
                      </div>
                    </div>`;

        args.tplPage = _html;
        args.tplItem = 'nomenuitem';
        args.menu = '.main-column.tool-menu';
        args.field = '.main-column.col-center';

        baseView.prototype.constructor.call(this, args);
    };

    ViewWelcome.prototype = Object.create(baseView.prototype);
    ViewWelcome.prototype.constructor = ViewWelcome;

    window.ControllerWelcome = ControllerWelcome;

    utils.fn.extend(ControllerWelcome.prototype, {
        init: function() {
            baseController.prototype.init.apply(this, arguments);

            const ui_theme = localStorage.getItem('ui-theme');
            const is_dark_theme = ui_theme == 'theme-dark' || ui_theme == 'theme-contrast-dark';
            let img = `<svg class='img-welcome'><use href=${!is_dark_theme ? '#welcome-light' : '#welcome-dark'}></svg>`;

            if ( utils.isWinXp ) {
                img = img.replace(' href=', ' xlink:href=');
            }

            this.view.tplPage = this.view.tplPage.replace(/<imagewelcome>/, img);
            this.view.render();

            if ( utils.isWinXp ) {
                $('h4.text-description, .tools-connect', this.view.$panel).hide();
            }

            window.CommonEvents.on('theme:changed', name => {
                const is_dark_theme = name == 'theme-dark';
                $('svg.img-welcome use', this.view.$panel).attr('href', !is_dark_theme ? '#welcome-light' : '#welcome-dark');
            });

            return this;
        }
    });
}();

/*
*   controller definition
*/

// window.CommonEvents.on('main:ready', function(){
//     var p = new ControllerWelcome({});
//     p.init();
// });