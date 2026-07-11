#include <windows.h>

#include "hbdockautohidemovebutton.h"

void hbDockAutoHideMoveButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   int x,
   int y,
   int cx,
   int cy )
{
   if( pButton == NULL )
      return;

   MoveWindow(
      pButton->hWnd,
      x,
      y,
      cx,
      cy,
      TRUE );
}