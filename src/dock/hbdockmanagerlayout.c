#include <windows.h>

#include "hbdockmanagerlayout.h"

void hbDockManagerLayout(
   HB_DOCK_MANAGER * pManager )
{
   RECT rc;

   if( pManager == NULL )
      return;

   GetClientRect(
      pManager->hWnd,
      &rc );

   hbDockLayoutEnginePerform(
      &pManager->LayoutEngine,
      &rc );
}

void hbDockManagerResize(
   HB_DOCK_MANAGER * pManager,
   int cx,
   int cy )
{
   RECT rc;

   if( pManager == NULL )
      return;

   SetRect(
      &rc,
      0,
      0,
      cx,
      cy );

   hbDockLayoutEnginePerform(
      &pManager->LayoutEngine,
      &rc );
}