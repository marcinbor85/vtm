#include "vtm_render.h"

static void print_path(struct vtm_menu *menu, const char *path)
{
        // TODO
}

static void print_separator(struct vtm_menu *menu)
{
        // TODO
}

static void print_item(struct vtm_menu *menu, const char *name, int index, bool selected, bool enabled)
{
        // TODO
}

static void print_scrollbars(struct vtm_menu *menu, bool up, bool down)
{
        // TODO
}

struct vtm_render_iface vtm_render_lcd_4x20 = {
        .print_path = print_path,
        .print_separator = print_separator,
        .print_item = print_item,
        .print_scrollbars = print_scrollbars,
};
