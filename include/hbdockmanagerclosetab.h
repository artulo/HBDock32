#ifndef HBDOCKMANAGERCLOSETAB_H
#define HBDOCKMANAGERCLOSETAB_H

#include "hbdockmanager.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Etapa 51: cierra (oculta y saca del arbol) una pestana/panel
 * puntual -- si comparte contenedor con otros paneles tabificados,
 * solo sale esa pestana (el contenedor se queda con el resto); si
 * era la unica, el contenedor entero sale del arbol. Ver
 * src/tabs/hbdockmanagerclosetab.c.
 */
void hbDockManagerCloseTab(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif
