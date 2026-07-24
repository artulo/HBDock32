#include <windows.h>

#include "hbdocksplitterpaint.h"

void hbDockSplitterPaint(
      const HB_DOCK_SPLITTER * pSplitter,
      HDC hDC )
{
   HBRUSH hBrush;

   if( pSplitter == NULL )
      return;

   hBrush =
      CreateSolidBrush(
         RGB(210,210,210));

   FillRect(
      hDC,
      &pSplitter->Rect,
      hBrush );

   DeleteObject(
      hBrush );
}