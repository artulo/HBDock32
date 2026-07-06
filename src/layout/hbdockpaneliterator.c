#include "hbdockpaneliterator.h"

void hbDockPanelIteratorInit(
   HB_DOCK_PANEL_ITERATOR * pIterator,
   HB_DOCK_NODE * pRoot )
{
   pIterator->Top = 0;

   while( pRoot != NULL )
   {
      pIterator->Stack[
         pIterator->Top++ ] = pRoot;

      pRoot = pRoot->First;
   }
}

HB_DOCK_PANEL * hbDockPanelIteratorNext(
   HB_DOCK_PANEL_ITERATOR * pIterator )
{
   HB_DOCK_NODE * pNode;

   while( pIterator->Top > 0 )
   {
      pNode =
         pIterator->Stack[
            --pIterator->Top ];

      if( pNode->Second != NULL )
      {
         HB_DOCK_NODE * p;

         p = pNode->Second;

         while( p != NULL )
         {
            pIterator->Stack[
               pIterator->Top++ ] = p;

            p = p->First;
         }
      }

      if( pNode->Type ==
          HB_DOCK_NODE_LEAF )
         return pNode->Panel;
   }

   return NULL;
}