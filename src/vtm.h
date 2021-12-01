#ifndef VTM_H
#define VTM_H

#include "vtm_types.h"

#include "vtm_define.h"
#include "vtm_navigate.h"
#include "vtm_render.h"

void vtm_init(const struct vtm_menu *menu, const struct vtm_render_iface *render_iface, void *ctx);
void vtm_service(const struct vtm_menu *menu);

#endif /* VTM_H */
