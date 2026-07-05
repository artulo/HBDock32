#include <windows.h>

#include "hbdockstate.h"

void hbDockStateInit(
   HB_DOCK_STATE * pState )
{
   if( pState == NULL )
      return;

   SetRectEmpty(
      &pState->Rect );

   pState->DockSide = 0;
   pState->Visible = 1;
   pState->Floating = 0;
}