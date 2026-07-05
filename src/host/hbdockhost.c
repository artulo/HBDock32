#include <windows.h>

#include "hbdockhost.h"
#include "hbdocklayout.h"

BOOL hbDockHostAttach(
   HB_DOCK_HOST * pHost,
   HWND hWnd,
   HB_DOCK_MANAGER * pManager )
{
   if( pHost == NULL )
      return FALSE;

   pHost->hWnd = hWnd;
   pHost->pManager = pManager;

   if( pManager != NULL )
      pManager->hParent = hWnd;

   return TRUE;
}

void hbDockHostDetach(
   HB_DOCK_HOST * pHost )
{
   if( pHost == NULL )
      return;

   pHost->hWnd = NULL;
   pHost->pManager = NULL;
}

void hbDockHostResize(
   HB_DOCK_HOST * pHost )
{
   if( pHost == NULL )
      return;

   if( pHost->pManager == NULL )
      return;

   hbDockPerformLayout(
      pHost->pManager );
}

void hbDockHostInvalidate(
   HB_DOCK_HOST * pHost )
{
   if( pHost == NULL )
      return;

   if( pHost->hWnd != NULL )
      InvalidateRect(
         pHost->hWnd,
         NULL,
         TRUE );
}