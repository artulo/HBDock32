#ifndef HBDOCKAUTOHIDEBUTTON_H
#define HBDOCKAUTOHIDEBUTTON_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif
#define HB_DOCK_AUTOHIDE_TEXT_MAX 128
typedef struct
{
   RECT Rect;

   HB_DOCK_PANEL * Panel;

   int Hot;
   int Pressed;
   int Checked;
   HFONT hFont;
   HICON hIcon;
   TCHAR Text[ HB_DOCK_AUTOHIDE_TEXT_MAX ];
   void * pUserData;
   BOOL Visible;
   BOOL Enabled;      
   int WindowId;

} HB_DOCK_AUTOHIDE_BUTTON;

void hbDockAutoHideButtonInit(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

#ifdef __cplusplus
}
#endif

#endif