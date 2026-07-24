#include <windows.h>

#include "hbdockautohideshow.h"

void hbDockAutoHideShow(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   pAutoHide->Visible = TRUE;

   ShowWindow(
      pAutoHide->Panel->hWnd,
      SW_SHOW );
}


void hbDockAutoHideHide(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   pAutoHide->Visible = FALSE;

   ShowWindow(
      pAutoHide->Panel->hWnd,
      SW_HIDE );
}