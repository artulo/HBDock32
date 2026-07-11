#include <windows.h>

#include "hbdockautohiderepaint.h"

void hbDockAutoHideRepaint(
   HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   if( pManager->hOwner == NULL )
      return;

   InvalidateRect(
      pManager->hOwner,
      NULL,
      TRUE );

   UpdateWindow(
      pManager->hOwner );
}