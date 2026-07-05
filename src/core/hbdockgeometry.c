#include <windows.h>

#include "hbdockgeometry.h"

void hbDockRectNormalize(
   RECT * pRect )
{
   LONG t;

   if( pRect == NULL )
      return;

   if( pRect->left > pRect->right )
   {
      t = pRect->left;
      pRect->left = pRect->right;
      pRect->right = t;
   }

   if( pRect->top > pRect->bottom )
   {
      t = pRect->top;
      pRect->top = pRect->bottom;
      pRect->bottom = t;
   }
}

void hbDockRectOffset(
   RECT * pRect,
   int dx,
   int dy )
{
   if( pRect == NULL )
      return;

   OffsetRect(
      pRect,
      dx,
      dy );
}

void hbDockRectInflate(
   RECT * pRect,
   int dx,
   int dy )
{
   if( pRect == NULL )
      return;

   InflateRect(
      pRect,
      dx,
      dy );
}