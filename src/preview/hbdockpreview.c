#include <windows.h>

#include "hbdockpreview.h"

void hbDockPreviewInit(
   HB_DOCK_PREVIEW * pPreview )
{
   if( pPreview == NULL )
      return;

   ZeroMemory(
      pPreview,
      sizeof( HB_DOCK_PREVIEW ) );
}

void hbDockPreviewShow(
   HB_DOCK_PREVIEW * pPreview,
   const RECT * pRect )
{
   if( pPreview == NULL || pRect == NULL )
      return;

   pPreview->Rect = *pRect;
   pPreview->Visible = 1;
}

void hbDockPreviewHide(
   HB_DOCK_PREVIEW * pPreview )
{
   if( pPreview == NULL )
      return;

   pPreview->Visible = 0;
}

void hbDockPreviewDraw(
   HDC hDC,
   const HB_DOCK_PREVIEW * pPreview )
{
   HBRUSH hBrush;

   if( hDC == NULL || pPreview == NULL )
      return;

   if( !pPreview->Visible )
      return;

   hBrush = CreateSolidBrush(
      RGB( 0, 120, 215 ) );

   FrameRect(
      hDC,
      ( RECT * ) &pPreview->Rect,
      hBrush );

   DeleteObject(
      hBrush );
}