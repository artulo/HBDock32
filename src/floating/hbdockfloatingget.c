#include "hbdockfloatingget.h"

HB_DOCK_FLOATING_FRAME * hbDockFloatingGet(
   HB_DOCK_FLOATING_MANAGER * pManager,
   int Index )
{
   if( pManager == NULL )
      return NULL;

   return
      ( HB_DOCK_FLOATING_FRAME * )
      hbDockArrayGet(
         &pManager->Frames,
         Index );
}