#include "vtm_render.h"

static void init(struct vtm_menu *menu)
{
        // TODO
}

static void print_item(struct vtm_menu *menu, const char *name, int index, bool selected, bool enabled)
{
        if (selected == false)
                return;

        // TODO
}

static void print_scrollbars(struct vtm_menu *menu, bool prev, bool next)
{
        // TODO
}

const struct vtm_render_iface vtm_render_lcd_1x16 = {
        .init = init,
        .print_path = NULL,
        .print_separator = NULL,
        .print_item = print_item,
        .print_scrollbars = print_scrollbars,
};
