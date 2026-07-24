#include "hbdockautohideenable.h"


void hbDockAutoHideEnable(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int Enable )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->Enabled = Enable ? 1 : 0;
}