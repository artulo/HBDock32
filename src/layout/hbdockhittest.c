#include <windows.h>

#include "hbdockhittest.h"
#include "hbdockcontainer.h"

static void hbDockTreeHit(
   HB_DOCK_LAYOUT_NODE * pNode,
   POINT pt,
   HB_DOCK_HITTEST * pHit )
{
   if( pNode == NULL )
      return;

   if( pHit == NULL )
      return;

   if( !PtInRect(
         &pNode->Rect,
         pt ) )
      return;

   if( pNode->Type == HB_LAYOUT_LEAF )
   {
      pHit->Hit = HB_DOCK_HIT_PANEL;

      pHit->pNode = pNode;

      if( pNode->pContainer != NULL )
         pHit->pPanel =
            pNode->pContainer->TabGroup.pPanel;
      else
         pHit->pPanel = NULL;

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
   if( pHit == NULL )
      return;

   ZeroMemory(
      pHit,
      sizeof( HB_DOCK_HITTEST ) );

   pHit->Hit = HB_DOCK_HIT_NONE;
   pHit->pPanel = NULL;
   pHit->pNode = NULL;
}

void hbDockHitTestTree(
   HB_DOCK_LAYOUT_NODE * pRoot,
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