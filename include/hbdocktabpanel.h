#ifndef HBDOCKTABPANEL_H
#define HBDOCKTABPANEL_H

#include <windows.h>

#include "hbdocktabgroup.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_TAB_PANEL
{
   HB_DOCK_TAB_GROUP * Group;

   RECT ClientRect;
   RECT HeaderRect;

   int HeaderHeight;

} HB_DOCK_TAB_PANEL;

void hbDockTabPanelInit(
   HB_DOCK_TAB_PANEL * pPanel,
   HB_DOCK_TAB_GROUP * pGroup );

void hbDockTabPanelSetRect(
   HB_DOCK_TAB_PANEL * pPanel,
   const RECT * pRect );

HB_DOCK_PANEL * hbDockTabPanelGetActive(
   HB_DOCK_TAB_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif