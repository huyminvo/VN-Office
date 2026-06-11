/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

+function() {
    'use strict';

    function createDonateBody() {
        const lang = utils.Lang;
        return `
            <div class="donate-dialog">
                <h3>${lang.donateTitle}</h3>
                <p class="text-normal">${lang.donateLead}</p>
                <p class="text-normal">${lang.donateBody}</p>
                <div class="donate-dialog__actions">
                    <form action="${utils.defines.links.donate}" method="post" target="_blank" class="donate-dialog__form">
                        <button type="submit" class="btn btn--landing">${lang.donateAction}</button>
                    </form>
                    <a class="btn donate-dialog__repo" target="_blank" href="${utils.defines.links.helpcenter}">${lang.donateRepo}</a>
                </div>
                <p class="donate-dialog__note">${lang.donateThanks}</p>
            </div>
        `;
    }

    window.openDonateDialog = function() {
        const dialog = new Dialog({
            dialogClass: 'dlg-donate',
            titleText: utils.Lang.actDonate,
            bodyTemplate: createDonateBody(),
            defaultWidth: 560
        });

        dialog.show();
        return dialog;
    };
}();
