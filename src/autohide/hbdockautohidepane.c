#include <string.h>

#include "hbdockautohide.h"

void hbDockAutoHideInit(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HB_DOCK_PANEL * pPanel )
{
   if( pAutoHide == NULL )
      return;

   memset(
      pAutoHide,
      0,
      sizeof( HB_DOCK_AUTOHIDE ) );

   pAutoHide->Panel = pPanel;

   SetRectEmpty(
      &pAutoHide->HiddenRect );

   SetRectEmpty(
      &pAutoHide->VisibleRect );

   pAutoHide->Enabled = TRUE;
   pAutoHide->Expanded = FALSE;

   pAutoHide->Active = FALSE;

   pAutoHide->Animation = TRUE;

   pAutoHide->Delay = 0;

   pAutoHide->SlideSpeed = 1;
   pAutoHide->SlideAcceleration = 0;

   pAutoHide->HotTrack = TRUE;
   pAutoHide->Hover = FALSE;
   pAutoHide->Locked = FALSE;

   pAutoHide->WaitingMouseLeave = FALSE;

   pAutoHide->Pinned = FALSE;
   pAutoHide->Pressed = FALSE;
   pAutoHide->Selected = FALSE;

   pAutoHide->Sliding = FALSE;

   pAutoHide->SlidePosition = 0;
   pAutoHide->SlideDirection = 0;
   pAutoHide->SlideStep = 1;
   pAutoHide->SlideSize = 0;

   pAutoHide->State = 0;
   pAutoHide->Tracking = 0;
}