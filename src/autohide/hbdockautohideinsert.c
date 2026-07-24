#include "hbdockautohideinsert.h"
 
int hbDockAutoHideInsert(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   int nIndex,
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   int i;

   if( pManager == NULL )
      return 0;

   if( nIndex < 0 )
      nIndex = 0;
 
   if( nIndex > pManager->Panes.Count )
      nIndex = pManager->Panes.Count;

   if( !hbDockArrayResize(
            &pManager->Panes,
            pManager->Panes.Count + 1 ) )
      return 0;

   for( i = pManager->Panes.Count - 1;
        i > nIndex;
        --i )
      pManager->Panes.Items[ i ] =
         pManager->Panes.Items[ i - 1 ];

   pManager->Panes.Items[ nIndex ] = pPane;

   return 1;
}