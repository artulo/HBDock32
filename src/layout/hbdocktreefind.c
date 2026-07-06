#include "hbdocktreefind.h"

HB_DOCK_NODE * hbDockTreeFindPanel(
   HB_DOCK_NODE * pRoot,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_NODE * pNode;

   if( pRoot == NULL )
      return NULL;

   if( pRoot->Panel == pPanel )
      return pRoot;

   pNode = hbDockTreeFindPanel(
      pRoot->First,
      pPanel );

   if( pNode != NULL )
      return pNode;

   return hbDockTreeFindPanel(
      pRoot->Second,
      pPanel );
}