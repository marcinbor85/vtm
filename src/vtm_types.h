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
        VTM_ITEM_TYPE__TOTAL_NUM
} vtm_item_type_t;

typedef enum {
        VTM_ITEM_PROPERTY_ENABLED,
        VTM_ITEM_PROPERTY_VISIBLE,
        VTM_ITEM_PROPERTY_NAME,
        VTM_ITEM_PROPERTY_ACTION,
        VTM_ITEM_PROPERTY__TOTAL_NUM
} vtm_item_property_t;

typedef int (*vtm_item_action_callback_t)(struct vtm_menu *menu, struct vtm_item *item);
typedef int (*vtm_item_property_getter_t)(struct vtm_menu *menu, struct vtm_item *item, vtm_item_property_t prop, void *value);

struct vtm_render_iface {
        void (*print_path)(struct vtm_menu *menu, const char *path);
        void (*print_separator)(struct vtm_menu *menu);
        void (*print_item)(struct vtm_menu *menu, const char *name, int index, bool selected, bool enabled);
        void (*print_scrollbars)(struct vtm_menu *menu, bool up, bool down);
};

struct vtm_interface {
        vtm_item_property_getter_t get_property;
};

struct vtm_item {
        vtm_item_type_t type;
        const char *name;
        vtm_item_action_callback_t action;
        uint32_t id;
};

struct vtm_manager {
        int current_index;
};

struct vtm_menu {
        const char* name;
        struct vtm_manager *manager;
        struct vtm_interface const *iface;
        struct vtm_item items[];
};

#endif /* VTM_TYPES_H */
