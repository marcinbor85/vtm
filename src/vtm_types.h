#ifndef VTM_TYPES_H
#define VTM_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

struct vtm_menu;
struct vtm_item;

typedef enum {
        VTM_ITEM_TYPE_ACTION,        
        VTM_ITEM_TYPE_SUBMENU,
        VTM_ITEM_TYPE_SUBMENU_END,
        VTM_ITEM_TYPE_BACK,
        VTM_ITEM_TYPE__TOTAL_NUM
} vtm_item_type_t;

typedef enum {
        VTM_ITEM_PROPERTY_ENABLED,
        VTM_ITEM_PROPERTY_VISIBLE,
        VTM_ITEM_PROPERTY_NAME,
        VTM_ITEM_PROPERTY_ACTION,
        VTM_ITEM_PROPERTY_CONTEXT,
        VTM_ITEM_PROPERTY__TOTAL_NUM
} vtm_item_property_t;

typedef int (*vtm_item_action_callback_t)(const struct vtm_menu *menu, const struct vtm_item *item);
typedef int (*vtm_item_property_getter_t)(const struct vtm_menu *menu, const struct vtm_item *item, vtm_item_property_t prop, void *value);

struct vtm_render_iface {
        void (*init)(const struct vtm_menu *menu);
        void (*print_path)(const struct vtm_menu *menu, const char *path);
        void (*print_separator)(const struct vtm_menu *menu);
        void (*print_item)(const struct vtm_menu *menu, const char *name, int index, bool selected, bool enabled);
        void (*print_scrollbars)(const struct vtm_menu *menu, bool prev, bool next);
};

struct vtm_item {
        vtm_item_type_t type;
        const char *name;
        vtm_item_action_callback_t action;
        uint32_t id;
};

struct vtm_manager {
        int selected_item_index;
};

struct vtm_render {
        void *ctx;
        struct vtm_render_iface const *iface;
};

struct vtm_menu {
        const char* name;
        struct vtm_manager *manager;
        struct vtm_render *render;
        vtm_item_property_getter_t get_property;
        struct vtm_item items[];
};

#endif /* VTM_TYPES_H */
