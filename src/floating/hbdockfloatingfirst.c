#include "hbdockfloatingfirst.h"

HB_DOCK_FLOATING_FRAME * hbDockFloatingFirst(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   if( pManager == NULL )
      return NULL;

   if( pManager->Frames.Count == 0 )
      return NULL;

   return
      ( HB_DOCK_FLOATING_FRAME * )
      pManager->Frames.Items[ 0 ];
}

HB_DOCK_FLOATING_FRAME * hbDockFloatingLast(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   if( pManager == NULL )
      return NULL;

   if( pManager->Frames.Count == 0 )
      return NULL;

   return
      ( HB_DOCK_FLOATING_FRAME * )
      pManager->Frames.Items[
         pManager->Frames.Count - 1 ];
}