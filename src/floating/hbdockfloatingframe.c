#include <windows.h>

#include "hbdockfloatingframe.h"

void hbDockFloatingFrameInit(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   ZeroMemory(
      pFrame,
      sizeof( HB_DOCK_FLOATING_FRAME ) );

   pFrame->Style =
      WS_OVERLAPPEDWINDOW;

   pFrame->ExStyle = 0;
}

int hbDockFloatingFrameCreate(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HWND hOwner )
{
   pFrame->hWnd =
      CreateWindowEx(
         pFrame->ExStyle,
         TEXT( "HB_FLOATFRAME" ),
         TEXT( "" ),
         pFrame->Style,
         pFrame->Rect.left,
         pFrame->Rect.top,
         pFrame->Rect.right -
            pFrame->Rect.left,
         pFrame->Rect.bottom -
            pFrame->Rect.top,
         hOwner,
         NULL,
         GetModuleHandle( NULL ),
         NULL );

   return
      pFrame->hWnd != NULL;
}

void hbDockFloatingFrameDestroy(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame->hWnd != NULL )
   {
      DestroyWindow(
         pFrame->hWnd );

      pFrame->hWnd = NULL;
   }
}