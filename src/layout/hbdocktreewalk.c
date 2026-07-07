#include "hbdocktreewalk.h"

static void hbDockTreeWalkNode(
   HB_DOCK_NODE * pNode,
   HB_DOCK_NODE_PROC pProc,
   void * Cargo )
{
   if( pNode == NULL )
      return;

   pProc(
      pNode,
      Cargo );

   hbDockTreeWalkNode(
      pNode->First,
      pProc,
      Cargo );

   hbDockTreeWalkNode(
      pNode->Second,
      pProc,
      Cargo );
}

void hbDockTreeWalk(
   HB_DOCK_NODE * pRoot,
   HB_DOCK_NODE_PROC pProc,
   void * Cargo )
{
   if( pProc == NULL )
      return;

   hbDockTreeWalkNode(
      pRoot,
      pProc,
      Cargo );
}