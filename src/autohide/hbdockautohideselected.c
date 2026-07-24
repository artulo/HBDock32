#include "hbdockautohideselected.h"

void hbDockAutoHideSelect(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Selected = TRUE;
}

void hbDockAutoHideUnselect(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Selected = FALSE;
}

int hbDockAutoHideIsSelected(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return FALSE;

   return pAutoHide->Selected;
}