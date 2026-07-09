#ifndef HBDOCKAUTOHIDEBUTTON_H
#define HBDOCKAUTOHIDEBUTTON_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   RECT Rect;

   HB_DOCK_PANEL * Panel;

   int Hot;

   int Pressed;

} HB_DOCK_AUTOHIDE_BUTTON;

void hbDockAutoHideButtonInit(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

#ifdef __cplusplus
}
#endif

#endif