#ifndef HBDOCKAUTOHIDEPANE_H
#define HBDOCKAUTOHIDEPANE_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_AUTOHIDE_PANE
{
   HWND hWnd;

   HB_DOCK_PANEL * Panel;

   RECT Rect;          /* Rectángulo lógico */
   RECT WindowRect;    /* Rectángulo físico durante la animación */

   DWORD Side;
   DWORD State;

   int Visible;
   
   int Active;
   int Enabled;
   int Expanded;
   int Hover;
   int HotTrack;
   int Locked;
   int WaitingMouseLeave;
   int Pressed;
   int Tracking;
   int Selected;

   int Animation;
   int Delay;
   
   int Pinned;
   
   int Sliding;
   int SlidePosition;
   int SlideDirection;
   int SlideStep;
   int SlideSize;
   int SlideAcceleration;
 

} HB_DOCK_AUTOHIDE_PANE;

void hbDockAutoHidePaneInit(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif