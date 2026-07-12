#include <windows.h>

#include "hbdockpreviewrect.h"

void hbDockPreviewSetRect(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay,
   const RECT * pRect )
{
   if( pOverlay == NULL || pRect == NULL )
      return;

   pOverlay->PreviewRect = *pRect;

   MoveWindow(
      pOverlay->hWnd,
      pRect->left,
      pRect->top,
      pRect->right - pRect->left,
      pRect->bottom - pRect->top,
      TRUE );
}

const RECT *
hbDockPreviewGetRect(
   const HB_DOCK_PREVIEW_OVERLAY * pOverlay )
{
   if( pOverlay == NULL )
      return NULL;

   return &pOverlay->PreviewRect;
}