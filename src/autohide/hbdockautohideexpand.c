#include "hbdockautohideexpand.h"

void hbDockAutoHideExpand(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Expanded = 1;
}

void hbDockAutoHideCollapse(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Expanded = 0;
}

int hbDockAutoHideIsExpanded(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return pAutoHide->Expanded;
}