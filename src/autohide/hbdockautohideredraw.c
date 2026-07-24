#include <windows.h>

#include "hbdockautohideredraw.h"

void hbDockAutoHideRedraw(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   RedrawWindow(
      pAutoHide->Panel->hWnd,
      NULL,
      NULL,
      RDW_INVALIDATE |
      RDW_UPDATENOW |
      RDW_ALLCHILDREN );
}