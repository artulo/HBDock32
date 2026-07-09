#include <string.h>

#include "hbdockfloatingcopy.h"

void hbDockFloatingCopy(
   HB_DOCK_FLOATING_FRAME * pDest,
   const HB_DOCK_FLOATING_FRAME * pSource )
{
   if( pDest == NULL )
      return;

   if( pSource == NULL )
      return;

   memcpy(
      pDest,
      pSource,
      sizeof(
         HB_DOCK_FLOATING_FRAME ) );
}