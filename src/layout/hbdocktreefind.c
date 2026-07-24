#include "hbdocktreefind.h"
#include "hbdockcontainer.h"

HB_DOCK_LAYOUT_NODE * hbDockTreeFindPanel(
   HB_DOCK_LAYOUT_NODE * pRoot,
   HB_DOCK_PANEL * pPanel )
{
   UINT i;
   HB_DOCK_LAYOUT_NODE * pNode;

   if( pRoot == NULL )
      return NULL;

   if( pRoot->pContainer != NULL )
   {
      for( i = 0;
           i < pRoot->pContainer->TabGroup.Count;
           i++ )
      {
         if( pRoot->pContainer->TabGroup.Tabs[i].pPanel == pPanel )
            return pRoot;
      }
   }

   pNode = hbDockTreeFindPanel(
      pRoot->First,
      pPanel );

   if( pNode != NULL )
      return pNode;

   return hbDockTreeFindPanel(
      pRoot->Second,
      pPanel );
}