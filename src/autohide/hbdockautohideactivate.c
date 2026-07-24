#include "hbdockautohideactivate.h"

void hbDockAutoHideActivate(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Active = 1;
}

void hbDockAutoHideDeactivate(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Active = 0;
}

int hbDockAutoHideIsActive(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return pAutoHide->Active;
}