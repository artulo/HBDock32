#include <string.h>

#include "hbdockautohidepane.h"

void hbDockAutoHidePaneInit(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   memset(
      pPane,
      0,
      sizeof( HB_DOCK_AUTOHIDE_PANE ) );
	
	SetRectEmpty( &pPane->Rect );
	SetRectEmpty( &pPane->WindowRect );

	pPane->Visible = FALSE;
	pPane->Active = FALSE;
	pPane->Enabled = TRUE;
	pPane->Expanded = FALSE;
	pPane->Animation = TRUE;
	pPane->Delay = 0;
	pPane->SlideAcceleration = 0;
	pPane->HotTrack = TRUE;
	pPane->Hover = FALSE;
	pPane->Locked = FALSE;
	pPane->WaitingMouseLeave = FALSE;
	pPane->Pinned = FALSE;
	pPane->Pressed = FALSE;
	pPane->Selected = FALSE;
	pPane->Sliding         = FALSE;
	pPane->SlidePosition   = 0;
	pPane->SlideDirection  = 0;
	pPane->SlideStep       = 1;
	pPane->SlideSize = 0;
	pPane->State = 0;
	pPane->Tracking = 0;
   
}