#ifndef HBDOCKTABCONTROL_H
#define HBDOCKTABCONTROL_H

#include <windows.h>

#include "hbdocktabgroup.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HBDOCK_TAB_HEIGHT      24
#define HBDOCK_TAB_MARGIN       4
#define HBDOCK_MAX_TAB_RECTS   64

typedef struct _HB_DOCK_TAB_CONTROL
{
   HB_DOCK_TAB_GROUP * Group;

   RECT Rect;

   RECT TabRects[ HBDOCK_MAX_TAB_RECTS ];

} HB_DOCK_TAB_CONTROL;

void hbDockTabControlInit(
   HB_DOCK_TAB_CONTROL * pControl,
   HB_DOCK_TAB_GROUP * pGroup );

void hbDockTabControlLayout(
   HB_DOCK_TAB_CONTROL * pControl,
   const RECT * pRect );

void hbDockTabControlDraw(
   HDC hDC,
   HB_DOCK_TAB_CONTROL * pControl );

int hbDockTabControlHitTest(
   HB_DOCK_TAB_CONTROL * pControl,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif