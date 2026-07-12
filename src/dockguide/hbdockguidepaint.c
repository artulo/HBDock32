#include <windows.h>

#include "hbdockguidepaint.h"

void hbDockGuidePaint(
   HB_DOCK_GUIDE * pGuide,
   HDC hDC )
{
   HBRUSH hBrush;
   HBRUSH hOld;

   if( pGuide == NULL )
      return;

   hBrush =
      CreateSolidBrush(
         pGuide->Hot ?
         RGB( 0, 120, 215 ) :
         RGB( 190, 190, 190 ) );

   hOld =
      ( HBRUSH ) SelectObject(
         hDC,
         hBrush );

   Ellipse(
      hDC,
      pGuide->Rect.left,
      pGuide->Rect.top,
      pGuide->Rect.right,
      pGuide->Rect.bottom );

   SelectObject(
      hDC,
      hOld );

   DeleteObject(
      hBrush );
}