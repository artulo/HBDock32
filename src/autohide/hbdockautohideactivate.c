#include <windows.h>

#include "hbdockautohideactivate.h"

void hbDockAutoHideActivate(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   ShowWindow(
      pPane->hWnd,
      SW_SHOW );

   SetFocus(
      pPane->hWnd );
}

void hbDockAutoHideDeactivate(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   ShowWindow(
      pPane->hWnd,
      SW_HIDE );
}