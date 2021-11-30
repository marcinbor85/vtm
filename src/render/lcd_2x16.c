#include "vtm_render.h"

static void print_path(struct vtm_menu *menu, const char *path)
{
        // TODO
}

static void print_item(struct vtm_menu *menu, const char *name, int index, bool selected, bool enabled)
{
        if (selected == false)
                return;

        // TODO
}

static void print_scrollbars(struct vtm_menu *menu, bool up, bool down)
{
        // TODO
}

struct vtm_render_iface vtm_render_lcd_2x16 = {
        .print_path = print_path,
        .print_separator = NULL,
        .print_item = print_item,
        .print_scrollbars = print_scrollbars,
};
