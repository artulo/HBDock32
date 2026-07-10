#include "hbdockautohideisempty.h"

int hbDockAutoHideIsEmpty(
   const HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return 1;

   return
      pManager->Panes.Count == 0;
}