#include <windows.h>

#include "hbdockautohidedestroy.h"


void hbDockAutoHideDestroy(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd != NULL )
   {
      DestroyWindow(
         pAutoHide->Panel->hWnd );

      pAutoHide->Panel->hWnd = NULL;
   }
}