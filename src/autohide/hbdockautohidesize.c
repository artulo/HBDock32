#include <windows.h>

#include "hbdockautohidesize.h"

void hbDockAutoHideGetSize(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   SIZE * pSize )
{
   RECT rc;

   if( pPane == NULL || pSize == NULL )
      return;

   GetWindowRect(
      pPane->hWnd,
      &rc );

   pSize->cx = rc.right - rc.left;
   pSize->cy = rc.bottom - rc.top;
}