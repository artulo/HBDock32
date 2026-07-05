#include <windows.h>

#include "hbdockpaint.h"

void hbDockPaintBackground(
   HDC hDC,
   const RECT * pRect )
{
   HBRUSH hBrush;

   if( hDC == NULL || pRect == NULL )
      return;

   hBrush = CreateSolidBrush(
      GetSysColor( COLOR_BTNFACE ) );

   FillRect(
      hDC,
      ( RECT * ) pRect,
      hBrush );

   DeleteObject( hBrush );
}

void hbDockPaintBorder(
   HDC hDC,
   const RECT * pRect )
{
   RECT rc;

   if( hDC == NULL || pRect == NULL )
      return;

   rc = *pRect;

   DrawEdge(
      hDC,
      &rc,
      EDGE_ETCHED,
      BF_RECT );
}