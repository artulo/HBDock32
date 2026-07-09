#include <string.h>

#include "hbdockfloatingreset.h"

void hbDockFloatingReset(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   memset(
      pFrame,
      0,
      sizeof(
         HB_DOCK_FLOATING_FRAME ) );
}