#ifndef HBDOCKPANELENUM_H
#define HBDOCKPANELENUM_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int ( * HB_DOCK_PANEL_ENUMPROC )(
   HB_DOCK_PANEL * pPanel,
   void * Cargo );

void hbDockPanelEnum(
   HB_DOCK_NODE * pRoot,
   HB_DOCK_PANEL_ENUMPROC pProc,
   void * Cargo );

#ifdef __cplusplus
}
#endif

#endif