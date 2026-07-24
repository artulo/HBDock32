#include <windows.h>
#include <stdio.h>

#include "hbdockautohidedebug.h"

void hbDockAutoHideDump(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   char szBuffer[ 256 ];

   HWND hWnd;


   if( pAutoHide == NULL )
      return;


   hWnd = NULL;


   if( pAutoHide->Panel != NULL )
   {
      hWnd = pAutoHide->Panel->hWnd;
   }


   wsprintf(
      szBuffer,
      "HWND=%p Active=%d Expanded=%d Enabled=%d\r\n",
      hWnd,
      pAutoHide->Active,
      pAutoHide->Expanded,
      pAutoHide->Enabled );


   OutputDebugString(
      szBuffer );
}