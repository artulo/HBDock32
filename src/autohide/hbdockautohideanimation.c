#include <windows.h>

#include "hbdockautohideanimation.h"

void hbDockAutoHideSlideIn(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   AnimateWindow(
      pPane->hWnd,
      120,
      AW_SLIDE | AW_ACTIVATE );
}

void hbDockAutoHideSlideOut(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   AnimateWindow(
      pPane->hWnd,
      120,
      AW_SLIDE | AW_HIDE );
}