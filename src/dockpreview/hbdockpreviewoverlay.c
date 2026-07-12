#include <windows.h>

#include "hbdockpreviewoverlay.h"

BOOL hbDockPreviewOverlayCreate(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay,
   HWND hOwner )
{
   if( pOverlay == NULL )
      return FALSE;

   ZeroMemory(
      pOverlay,
      sizeof( HB_DOCK_PREVIEW_OVERLAY ) );

   pOverlay->Alpha = 90;

   pOverlay->hWnd =
      CreateWindowEx(
         WS_EX_LAYERED |
         WS_EX_TOOLWINDOW,
         TEXT( "STATIC" ),
         TEXT( "" ),
         WS_POPUP,
         0,
         0,
         10,
         10,
         hOwner,
         NULL,
         GetModuleHandle( NULL ),
         NULL );

   if( pOverlay->hWnd == NULL )
      return FALSE;

   SetLayeredWindowAttributes(
      pOverlay->hWnd,
      0,
      pOverlay->Alpha,
      LWA_ALPHA );

   return TRUE;
}

void hbDockPreviewOverlayDestroy(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay )
{
   if( pOverlay == NULL )
      return;

   if( pOverlay->hWnd )
   {
      DestroyWindow(
         pOverlay->hWnd );

      pOverlay->hWnd = NULL;
   }
}