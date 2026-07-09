#include "hbdockfloatingisempty.h"

int hbDockFloatingIsEmpty(
   const HB_DOCK_FLOATING_MANAGER * pManager )
{
   if( pManager == NULL )
      return 1;

   return
      pManager->Frames.Count == 0;
}