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

   pButton->Rect.left   = x;
   pButton->Rect.top    = y;
   pButton->Rect.right  = x + cx;
   pButton->Rect.bottom = y + cy;
}