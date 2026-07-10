#include "hbdockautohidereverse.h"

void hbDockAutoHideReverse(
   HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   int i;
   int j;

   if( pManager == NULL )
      return;

   i = 0;
   j = pManager->Panes.Count - 1;

   while( i < j )
   {
      void * pTemp;

      pTemp =
         pManager->Panes.Items[ i ];

      pManager->Panes.Items[ i ] =
         pManager->Panes.Items[ j ];

      pManager->Panes.Items[ j ] =
         pTemp;

      ++i;
      --j;
   }
}