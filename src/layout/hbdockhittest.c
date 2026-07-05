#include <windows.h>

#include "hbdockhittest.h"

static void hbDockTreeHit(
   HB_DOCK_NODE * pNode,
   POINT pt,
   HB_DOCK_HITTEST * pHit )
{
   if( pNode == NULL )
      return;

   if( !PtInRect(
         &pNode->Rect,
         pt ) )
      return;

   if( pNode->Type == HB_DOCK_NODE_LEAF )
   {
      pHit->Hit = HB_DOCK_HIT_PANEL;
      pHit->Panel = pNode->Panel;
      pHit->Node = pNode;
      return;
   }

   hbDockTreeHit(
      pNode->First,
      pt,
      pHit );

   if( pHit->Hit != HB_DOCK_HIT_NONE )
      return;

   hbDockTreeHit(
      pNode->Second,
      pt,
      pHit );
}

void hbDockHitTestInit(
   HB_DOCK_HITTEST * pHit )
{
   ZeroMemory(
      pHit,
      sizeof( HB_DOCK_HITTEST ) );
}

void hbDockHitTestTree(
   HB_DOCK_NODE * pRoot,
   POINT pt,
   HB_DOCK_HITTEST * pHit )
{
   if( pHit == NULL )
      return;

   hbDockHitTestInit(
      pHit );

   hbDockTreeHit(
      pRoot,
      pt,
      pHit );
}