#include <windows.h>

#include "hbdockpreviewpaint.h"

#define HBDOCK_PREVIEW_BORDER     2

static void hbDockPreviewFill(
   HDC hDC,
   const RECT * pRect )
{
   HBRUSH hBrush;

   hBrush = CreateSolidBrush(
      RGB( 70, 140, 240 ) );

   FillRect(
      hDC,
      ( RECT * ) pRect,
      hBrush );

   DeleteObject(
      hBrush );
}

static void hbDockPreviewFrame(
   HDC hDC,
   const RECT * pRect )
{
   HPEN hPen;
   HPEN hOld;
   HBRUSH hOldBrush;

   hPen = CreatePen(
      PS_SOLID,
      HBDOCK_PREVIEW_BORDER,
      RGB( 30, 90, 220 ) );

   hOld =
      SelectObject(
         hDC,
         hPen );

   hOldBrush =
      SelectObject(
         hDC,
         GetStockObject( NULL_BRUSH ) );

   Rectangle(
      hDC,
      pRect->left,
      pRect->top,
      pRect->right,
      pRect->bottom );

   SelectObject(
      hDC,
      hOldBrush );

   SelectObject(
      hDC,
      hOld );

   DeleteObject(
      hPen );
}

BOOL hbDockPreviewPaint(
   HDC hDC,
   const RECT * pRect )
{
   if( hDC == NULL )
      return FALSE;

   if( pRect == NULL )
      return FALSE;

   SaveDC(
      hDC );

   SetBkMode(
      hDC,
      TRANSPARENT );

   hbDockPreviewFill(
      hDC,
      pRect );

   hbDockPreviewFrame(
      hDC,
      pRect );

   RestoreDC(
      hDC,
      -1 );

   return TRUE;
}