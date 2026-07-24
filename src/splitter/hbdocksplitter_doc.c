#include <windows.h>

#include "hbdocksplitter.h"

void hbDockSplitterInit(
   HB_DOCK_SPLITTER * pSplitter )
{
   if( pSplitter == NULL )
      return;

   SetRectEmpty( &pSplitter->Rect );

   pSplitter->Visible  = 0;
   pSplitter->Vertical = 1;
   pSplitter->Tracking = 0;
}

void hbDockSplitterSetRect(
   HB_DOCK_SPLITTER * pSplitter,
   const RECT * pRect )
{
   if( pSplitter == NULL || pRect == NULL )
      return;

   pSplitter->Rect = *pRect;
}

void hbDockSplitterDraw(
   HDC hDC,
   const HB_DOCK_SPLITTER * pSplitter )
{
   HBRUSH hBrush;

   if( hDC == NULL || pSplitter == NULL )
      return;

   if( !pSplitter->Visible )
      return;

   hBrush = CreateSolidBrush(
      GetSysColor( COLOR_BTNFACE ) );

   FillRect(
      hDC,
      ( RECT * ) &pSplitter->Rect,
      hBrush );

   DeleteObject( hBrush );

   DrawEdge(
      hDC,
      ( RECT * ) &pSplitter->Rect,
      EDGE_RAISED,
      BF_RECT );
}

int hbDockSplitterHitTest(
   const HB_DOCK_SPLITTER * pSplitter,
   POINT pt )
{
   if( pSplitter == NULL )
      return 0;

   if( !pSplitter->Visible )
      return 0;

   return PtInRect(
      ( RECT * ) &pSplitter->Rect,
      pt );
}