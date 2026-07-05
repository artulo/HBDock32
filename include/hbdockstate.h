#ifndef HBDOCKSTATE_H
#define HBDOCKSTATE_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_STATE
{
   RECT Rect;

   int DockSide;
   int Visible;
   int Floating;

} HB_DOCK_STATE;

void hbDockStateInit(
   HB_DOCK_STATE * pState );

#ifdef __cplusplus
}
#endif

#endif