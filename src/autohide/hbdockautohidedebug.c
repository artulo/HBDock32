#include <windows.h>
#include <stdio.h>

#include "hbdockautohidedebug.h"

void hbDockAutoHideDump(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   char szBuffer[ 256 ];

   if( pPane == NULL )
      return;

   wsprintf(
      szBuffer,
      "HWND=%p Visible=%d Side=%lu\r\n",
      pPane->hWnd,
      pPane->Visible,
      ( unsigned long ) pPane->Side );

   OutputDebugString(
      szBuffer );
}