#include <windows.h>

#include "hbdockautohideupdate.h"

void hbDockAutoHideUpdate(
   HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   if( pManager->hOwner != NULL )
      InvalidateRect(
         pManager->hOwner,
         NULL,
         TRUE );
}