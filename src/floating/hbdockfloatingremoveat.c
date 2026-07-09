#include "hbdockfloatingremoveat.h"

int hbDockFloatingRemoveAt(
   HB_DOCK_FLOATING_MANAGER * pManager,
   int Index )
{
   if( pManager == NULL )
      return 0;

   return hbDockArrayRemove(
      &pManager->Frames,
      Index );
}