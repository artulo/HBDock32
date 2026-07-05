#include <stdlib.h>

#include "hbdockmouse.h"

int hbDockMouseMoved(
   POINT pt1,
   POINT pt2,
   int cxThreshold,
   int cyThreshold )
{
   if( abs( pt1.x - pt2.x ) >= cxThreshold )
      return 1;

   if( abs( pt1.y - pt2.y ) >= cyThreshold )
      return 1;

   return 0;
}