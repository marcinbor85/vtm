#include "vtm.h"

void vtm_init(const struct vtm_menu *menu, const struct vtm_render_iface *render_iface, void *ctx)
{
        // TODO

        menu->render->iface = render_iface;
        menu->render->ctx = ctx;

        menu->render->iface->init(menu);
}

void vtm_service(const struct vtm_menu *menu)
{
        // TODO
}
