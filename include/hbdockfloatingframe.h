#ifndef HBDOCKFLOATINGFRAME_H
#define HBDOCKFLOATINGFRAME_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_FLOATING_FRAME
{
   HWND hWnd;

   HB_DOCK_PANEL * Panel;

   RECT Rect;

   DWORD Style;

   DWORD ExStyle;

} HB_DOCK_FLOATING_FRAME;

void hbDockFloatingFrameInit(
   HB_DOCK_FLOATING_FRAME * pFrame );

int hbDockFloatingFrameCreate(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HWND hOwner );

void hbDockFloatingFrameDestroy(
   HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif