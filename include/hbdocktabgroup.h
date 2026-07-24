#ifndef HBDOCKTABGROUP_H
#define HBDOCKTABGROUP_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Declaración adelantada */
typedef struct _HB_DOCK_PANEL HB_DOCK_PANEL;

typedef struct _HB_DOCK_TAB
{
   HB_DOCK_PANEL * pPanel;

   TCHAR Caption[128];

   LPARAM UserData;

} HB_DOCK_TAB;

typedef struct _HB_DOCK_TAB_GROUP
{
   HWND hWnd;

   HWND hActiveDock;

   HB_DOCK_PANEL * pPanel;

   HB_DOCK_TAB * Tabs;

   UINT Count;

   UINT Capacity;

   UINT ActiveIndex;

} HB_DOCK_TAB_GROUP;

BOOL hbDockTabGroupInit(
   HB_DOCK_TAB_GROUP * pGroup );

void hbDockTabGroupDone(
   HB_DOCK_TAB_GROUP * pGroup );
   
BOOL hbDockTabGroupAddPanel(
   HB_DOCK_TAB_GROUP * pGroup,
   HB_DOCK_PANEL * pPanel );

BOOL hbDockTabGroupRemovePanel(
   HB_DOCK_TAB_GROUP * pGroup,
   HB_DOCK_PANEL * pPanel );

HB_DOCK_PANEL * hbDockTabGroupGetActivePanel(
   const HB_DOCK_TAB_GROUP * pGroup );


HB_DOCK_PANEL * hbDockTabGroupGetActive(
   HB_DOCK_TAB_GROUP * pGroup );

BOOL hbDockTabGroupSetActive(
   HB_DOCK_TAB_GROUP * pGroup,
   UINT Index );
   
#ifdef __cplusplus
}
#endif

#endif /* HBDOCKTABGROUP_H */