#include "hbdockautohideindexof.h"

int hbDockAutoHideIndexOf(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   int i;

   if( pManager == NULL )
      return -1;

   for( i = 0; i < pManager->Panes.Count; ++i )
   {
      if( pManager->Panes.Items[ i ] == pAutoHide )
         return i;
   }

   return -1;
}