#include <windows.h>

#include "hbdockautohideredraw.h"

void hbDockAutoHideRedraw(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   if( pPane->hWnd == NULL )
      return;

   RedrawWindow(
      pPane->hWnd,
      NULL,
      NULL,
      RDW_INVALIDATE |
      RDW_UPDATENOW |
      RDW_ALLCHILDREN );
}