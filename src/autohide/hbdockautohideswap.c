#include "hbdockautohideswap.h"

int hbDockAutoHideSwap(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   int nIndex1,
   int nIndex2 )
{
   void * pTemp;

   if( pManager == NULL )
      return 0;

   if( nIndex1 < 0 ||
       nIndex2 < 0 )
      return 0;

   if( nIndex1 >= pManager->Panes.Count )
      return 0;

   if( nIndex2 >= pManager->Panes.Count )
      return 0;

   pTemp =
      pManager->Panes.Items[ nIndex1 ];

   pManager->Panes.Items[ nIndex1 ] =
      pManager->Panes.Items[ nIndex2 ];

   pManager->Panes.Items[ nIndex2 ] =
      pTemp;

   return 1;
}