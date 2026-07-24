#ifndef HBDOCKAUTOHIDE_H
#define HBDOCKAUTOHIDE_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_AUTOHIDE
{
   HB_DOCK_PANEL * Panel;

   RECT HiddenRect;
   RECT VisibleRect;

   int Enabled;
   int Visible;
   int Expanded;

   int Active;

   int Animation;

   UINT Delay;

   int SlideSpeed;
   int SlideAcceleration;

   int HotTrack;
   int Hover;
   int Locked;
   int WaitingMouseLeave;

   int Pinned;
   int Pressed;
   int Selected;

   int Sliding;

   int SlidePosition;
   int SlideDirection;
   int SlideStep;
   int SlideSize;

   int State;
   int Tracking;

} HB_DOCK_AUTOHIDE;


void hbDockAutoHideInit(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HB_DOCK_PANEL * pPanel );

void hbDockAutoHideEnable(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int Enable );

void hbDockAutoHideExpand(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideCollapse(
   HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif