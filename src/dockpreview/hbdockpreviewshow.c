#include <windows.h>

#include "hbdockpreviewshow.h"

void hbDockPreviewShow(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay )
{
   if( pOverlay == NULL )
      return;

   pOverlay->Visible = TRUE;

   ShowWindow(
      pOverlay->hWnd,
      SW_SHOWNOACTIVATE );
}

void hbDockPreviewHide(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay )
{
   if( pOverlay == NULL )
      return;

   pOverlay->Visible = FALSE;

   ShowWindow(
      pOverlay->hWnd,
      SW_HIDE );
}