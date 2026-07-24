#include <windows.h>

#include "hbdockhost.h"

BOOL hbDockHostAttach(
   HB_DOCK_HOST * pHost,
   HWND hWnd,
   HB_DOCK_MANAGER * pManager )
{
   if( pHost == NULL )
      return FALSE;

   if( hWnd == NULL )
      return FALSE;

   if( pManager == NULL )
      return FALSE;

   ZeroMemory(
      pHost,
      sizeof( HB_DOCK_HOST ) );

   pHost->hWnd = hWnd;

   pHost->pManager = pManager;

   pHost->PendingDragPanel = NULL;

   pHost->PendingDragPoint.x = 0;
   pHost->PendingDragPoint.y = 0;

   pHost->Dragging = FALSE;

   ZeroMemory(
      &pHost->ActiveSplit,
      sizeof( HB_DOCK_SPLIT_NODE ) );

   ZeroMemory(
      &pHost->SplitterTracker,
      sizeof( HB_DOCK_SPLITTER_TRACKER ) );

   pHost->HoverAutoHide = NULL;

   SetTimer(
      hWnd,
      HBDOCK_AUTOHIDE_TIMER_ID,
      HBDOCK_AUTOHIDE_TIMER_MS,
      NULL );

   return TRUE;
}