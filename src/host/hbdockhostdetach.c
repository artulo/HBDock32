#include <windows.h>

#include "hbdockhost.h"

void hbDockHostDetach(
   HB_DOCK_HOST * pHost )
{
   if( pHost == NULL )
      return;

   if( pHost->hWnd != NULL )
   {
      KillTimer(
         pHost->hWnd,
         HBDOCK_AUTOHIDE_TIMER_ID );
   }

   pHost->PendingDragPanel = NULL;

   pHost->HoverAutoHide = NULL;

   pHost->Dragging = FALSE;

   pHost->hWnd = NULL;

   pHost->pManager = NULL;
}