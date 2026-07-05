#include "hbdockrect.h"

RECT hbDockRect(
   LONG Left,
   LONG Top,
   LONG Right,
   LONG Bottom )
{
   RECT rc;

   rc.left = Left;
   rc.top = Top;
   rc.right = Right;
   rc.bottom = Bottom;

   return rc;
}

int hbDockRectEqual(
   const RECT * pRect1,
   const RECT * pRect2 )
{
   if( pRect1 == NULL || pRect2 == NULL )
      return 0;

   return pRect1->left   == pRect2->left  &&
          pRect1->top    == pRect2->top   &&
          pRect1->right  == pRect2->right &&
          pRect1->bottom == pRect2->bottom;
}