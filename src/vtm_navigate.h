#ifndef VTM_NAVIGATE_H
#define VTM_NAVIGATE_H

#include "vtm_types.h"

void vtm_navigate_prev(const struct vtm_menu *menu);
void vtm_navigate_next(const struct vtm_menu *menu);
void vtm_navigate_select(const struct vtm_menu *menu);
void vtm_navigate_back(const struct vtm_menu *menu);

#endif /* VTM_NAVIGATE_H */
