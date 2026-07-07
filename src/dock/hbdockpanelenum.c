#include "hbdockpanelenum.h"

static void hbDockPanelEnumNode(
   HB_DOCK_NODE * pNode,
   HB_DOCK_PANEL_ENUMPROC pProc,
   void * Cargo )
{
   if( pNode == NULL )
      return;

   if( pNode->Type == HB_DOCK_NODE_LEAF )
   {
      if( pNode->Panel != NULL )
         pProc(
            pNode->Panel,
            Cargo );

      return;
   }

   hbDockPanelEnumNode(
      pNode->First,
      pProc,
      Cargo );

   hbDockPanelEnumNode(
      pNode->Second,
      pProc,
      Cargo );
}

void hbDockPanelEnum(
   HB_DOCK_NODE * pRoot,
   HB_DOCK_PANEL_ENUMPROC pProc,
   void * Cargo )
{
   if( pProc == NULL )
      return;

   hbDockPanelEnumNode(
      pRoot,
      pProc,
      Cargo );
}