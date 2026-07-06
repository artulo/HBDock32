#include "hbdocktreewalk.h"

void hbDockTreeWalk(
   HB_DOCK_NODE * pNode,
   HB_DOCK_TREE_PROC pProc,
   void * pCargo )
{
   if( pNode == NULL )
      return;

   if( pProc != NULL )
      pProc(
         pNode,
         pCargo );

   hbDockTreeWalk(
      pNode->First,
      pProc,
      pCargo );

   hbDockTreeWalk(
      pNode->Second,
      pProc,
      pCargo );
}