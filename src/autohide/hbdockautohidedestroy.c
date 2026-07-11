#include <windows.h>

#include "hbdockautohidedestroy.h"

void hbDockAutoHideDestroy(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   if( pPane->hWnd != NULL )
   {
      DestroyWindow(
         pPane->hWnd );

      pPane->hWnd = NULL;
   }
}