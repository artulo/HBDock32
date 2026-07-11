#include "hbdockautohidesort.h"

void hbDockAutoHideSort(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   HB_DOCK_AUTOHIDE_COMPARE pCompare )
{
   int i;
   int j;

   if( pManager == NULL || pCompare == NULL )
      return;

   for( i = 0; i < pManager->Panes.Count - 1; ++i )
   {
      for( j = i + 1; j < pManager->Panes.Count; ++j )
      {
         HB_DOCK_AUTOHIDE_PANE * pA;
         HB_DOCK_AUTOHIDE_PANE * pB;

         pA = ( HB_DOCK_AUTOHIDE_PANE * )
            pManager->Panes.Items[ i ];

         pB = ( HB_DOCK_AUTOHIDE_PANE * )
            pManager->Panes.Items[ j ];

         if( pCompare( pA, pB ) > 0 )
         {
            void * pTmp;

            pTmp = pManager->Panes.Items[ i ];
            pManager->Panes.Items[ i ] =
               pManager->Panes.Items[ j ];
            pManager->Panes.Items[ j ] =
               pTmp;
         }
      }
   }
}