#include <windows.h>

#include "hbdockpreviewpaint.h"

void hbDockPreviewPaint(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay,
   HDC hDC )
{
   HBRUSH hBrush;
   HPEN hPen;
   HGDIOBJ hOldBrush;
   HGDIOBJ hOldPen;

   if( pOverlay == NULL )
      return;

   hBrush =
      CreateSolidBrush(
         RGB( 80, 140, 255 ) );

   hPen =
      CreatePen(
         PS_SOLID,
         2,
         RGB( 0, 70, 200 ) );

   hOldBrush =
      SelectObject(
         hDC,
         hBrush );

   hOldPen =
      SelectObject(
         hDC,
         hPen );

   Rectangle(
      hDC,
      0,
      0,
      pOverlay->PreviewRect.right -
      pOverlay->PreviewRect.left,
      pOverlay->PreviewRect.bottom -
      pOverlay->PreviewRect.top );

   SelectObject(
      hDC,
      hOldBrush );

   SelectObject(
      hDC,
      hOldPen );

   DeleteObject(
      hBrush );

   DeleteObject(
      hPen );
}