#ifndef HBDOCKTABGROUP_H
#define HBDOCKTABGROUP_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HB_DOCK_MAX_TABS 64

typedef struct _HB_DOCK_TAB_GROUP
{
   HB_DOCK_PANEL * Panels[ HB_DOCK_MAX_TABS ];

   int Count;
   int Active;

   RECT TabRect;

} HB_DOCK_TAB_GROUP;

void hbDockTabGroupInit(
   HB_DOCK_TAB_GROUP * pGroup );

int hbDockTabGroupAdd(
   HB_DOCK_TAB_GROUP * pGroup,
   HB_DOCK_PANEL * pPanel );

int hbDockTabGroupRemove(
   HB_DOCK_TAB_GROUP * pGroup,
   HB_DOCK_PANEL * pPanel );

HB_DOCK_PANEL * hbDockTabGroupGetActive(
   HB_DOCK_TAB_GROUP * pGroup );

void hbDockTabGroupSetActive(
   HB_DOCK_TAB_GROUP * pGroup,
   int Index );

#ifdef __cplusplus
}
#endif

#endif