#include <windows.h>

#include "hbdockautohideshow.h"

void hbDockAutoHideShow(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   pPane->Visible = TRUE;

   ShowWindow(
      pPane->hWnd,
      SW_SHOW );
}

void hbDockAutoHideHide(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   pPane->Visible = FALSE;

   ShowWindow(
      pPane->hWnd,
      SW_HIDE );
}