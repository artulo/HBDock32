#ifndef HBDOCKCONTAINER_H
#define HBDOCKCONTAINER_H

#include <windows.h>

#include "hbdocktabgroup.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
   HB_CONTAINER_EMPTY = 0,
   HB_CONTAINER_TABS,
   HB_CONTAINER_SPLIT

} HB_DOCK_CONTAINER_TYPE;

typedef struct _HB_DOCK_CONTAINER
{
   HWND hWnd;

   RECT Rect;

   HB_DOCK_CONTAINER_TYPE Type;

   HB_DOCK_TAB_GROUP TabGroup;

   struct _HB_DOCK_CONTAINER * Parent;

   struct _HB_DOCK_CONTAINER * First;

   struct _HB_DOCK_CONTAINER * Second;

   float Ratio;

} HB_DOCK_CONTAINER;

BOOL hbDockContainerCreate(
      HB_DOCK_CONTAINER * pContainer,
      HWND hParent );

void hbDockContainerDestroy(
      HB_DOCK_CONTAINER * pContainer );

#ifdef __cplusplus
}
#endif

#endif