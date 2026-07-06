#include "hbdocktreerotate.h"

HB_DOCK_NODE * hbDockTreeRotateLeft(
   HB_DOCK_NODE * pNode )
{
   HB_DOCK_NODE * pNewRoot;

   if( pNode == NULL )
      return NULL;

   pNewRoot = pNode->Second;

   if( pNewRoot == NULL )
      return pNode;

   pNode->Second = pNewRoot->First;

   if( pNewRoot->First != NULL )
      pNewRoot->First->Parent = pNode;

   pNewRoot->First = pNode;

   pNewRoot->Parent = pNode->Parent;
   pNode->Parent = pNewRoot;

   return pNewRoot;
}

HB_DOCK_NODE * hbDockTreeRotateRight(
   HB_DOCK_NODE * pNode )
{
   HB_DOCK_NODE * pNewRoot;

   if( pNode == NULL )
      return NULL;

   pNewRoot = pNode->First;

   if( pNewRoot == NULL )
      return pNode;

   pNode->First = pNewRoot->Second;

   if( pNewRoot->Second != NULL )
      pNewRoot->Second->Parent = pNode;

   pNewRoot->Second = pNode;

   pNewRoot->Parent = pNode->Parent;
   pNode->Parent = pNewRoot;

   return pNewRoot;
}