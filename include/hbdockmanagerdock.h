#ifndef HBDOCKMANAGERDOCK_H
#define HBDOCKMANAGERDOCK_H

#include <windows.h>

#include "hbdockmanager.h"
#include "hbdockguidemanager.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockManagerDockPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_GUIDE_TYPE Guide );

/*
 * Etapa 20: acopla relativo a un nodo especifico del arbol (el panel
 * bajo el cursor durante un arrastre), no a la ventana completa.
 */
BOOL hbDockManagerDockRelative(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_LAYOUT_NODE * pTargetNode,
   HB_DOCK_GUIDE_TYPE Guide );
   


#ifdef __cplusplus
}
#endif

#endif /* HBDOCKMANAGERDOCK_H */