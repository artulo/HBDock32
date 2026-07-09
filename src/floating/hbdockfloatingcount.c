#include "hbdockfloatingcount.h"

int hbDockFloatingCount(
   const HB_DOCK_FLOATING_MANAGER * pManager )
{
   if( pManager == NULL )
      return 0;

   return pManager->Frames.Count;
}