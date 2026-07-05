#include "hbdockpoint.h"

POINT hbDockPoint(
   LONG x,
   LONG y )
{
   POINT pt;

   pt.x = x;
   pt.y = y;

   return pt;
}

int hbDockPointEqual(
   POINT pt1,
   POINT pt2 )
{
   return pt1.x == pt2.x &&
          pt1.y == pt2.y;
}