#include <windows.h>

#include "hbdockdiamondcreate.h"

BOOL hbDockDiamondCreate(
   HB_DOCK_DIAMOND * pDiamond,
   HWND hParent )
{
   if( pDiamond == NULL )
      return FALSE;

   ZeroMemory(
      pDiamond,
      sizeof( HB_DOCK_DIAMOND ) );

   pDiamond->hWnd =
      CreateWindowEx(
         WS_EX_TOOLWINDOW |
         WS_EX_LAYERED,
         TEXT("STATIC"),
         TEXT(""),
         WS_POPUP,
         0,
         0,
         140,
         140,
         hParent,
         NULL,
         GetModuleHandle(NULL),
         NULL );

   return
      pDiamond->hWnd != NULL;
}

void hbDockDiamondDestroy(
   HB_DOCK_DIAMOND * pDiamond )
{
   if( pDiamond == NULL )
      return;

   if( pDiamond->hWnd )
      DestroyWindow(
         pDiamond->hWnd );
}