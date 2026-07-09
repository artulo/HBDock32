#include <stdlib.h>
#include <string.h>

#include "hbdockfloatingclone.h"

HB_DOCK_FLOATING_FRAME *
hbDockFloatingClone(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   HB_DOCK_FLOATING_FRAME * pNew;

   if( pFrame == NULL )
      return NULL;

   pNew =
      ( HB_DOCK_FLOATING_FRAME * )
      malloc(
         sizeof(
            HB_DOCK_FLOATING_FRAME ) );

   if( pNew == NULL )
      return NULL;

   memcpy(
      pNew,
      pFrame,
      sizeof(
         HB_DOCK_FLOATING_FRAME ) );

   return pNew;
}