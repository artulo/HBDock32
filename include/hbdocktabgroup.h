#ifndef HBDOCKTABGROUP_H
#define HBDOCKTABGROUP_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_TAB
{
   HWND hDock;

   TCHAR Caption[128];

   LPARAM UserData;

} HB_DOCK_TAB;

typedef struct _HB_DOCK_TAB_GROUP
{
   HWND hWnd;

   HWND hActiveDock;

   HB_DOCK_TAB * Tabs;

   UINT Count;

   UINT Capacity;

   UINT ActiveIndex;

} HB_DOCK_TAB_GROUP;

BOOL hbDockTabGroupInit(
      HB_DOCK_TAB_GROUP * pGroup );

void hbDockTabGroupDone(
      HB_DOCK_TAB_GROUP * pGroup );

#ifdef __cplusplus
}
#endif

#endif