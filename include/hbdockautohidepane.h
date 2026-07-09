#ifndef HBDOCKAUTOHIDEPANE_H
#define HBDOCKAUTOHIDEPANE_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HWND hWnd;

   HB_DOCK_PANEL * Panel;

   RECT Rect;

   DWORD Side;

   int Visible;

} HB_DOCK_AUTOHIDE_PANE;

void hbDockAutoHidePaneInit(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif