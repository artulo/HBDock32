#include <windows.h>

#include "hbdocksplitnode.h"

void hbDockSplitNodeInit(
   HB_DOCK_SPLIT_NODE * pSplit,
   HB_DOCK_NODE * pNode )
{
   if( pSplit == NULL )
      return;

   ZeroMemory(
      pSplit,
      sizeof( HB_DOCK_SPLIT_NODE ) );

   pSplit->Node = pNode;
   pSplit->MinFirst = 80;
   pSplit->MinSecond = 80;
}

void hbDockSplitNodeUpdate(
   HB_DOCK_SPLIT_NODE * pSplit )
{
   RECT rc;

   if( pSplit == NULL )
      return;

   if( pSplit->Node == NULL )
      return;

   rc = pSplit->Node->Rect;

   if( pSplit->Node->Type == HB_DOCK_NODE_SPLIT_H )
   {
      rc.left = rc.left + pSplit->Node->SplitPos;
      rc.right = rc.left + pSplit->Node->SplitterSize;
   }
   else
   {
      rc.top = rc.top + pSplit->Node->SplitPos;
      rc.bottom = rc.top + pSplit->Node->SplitterSize;
   }

   pSplit->SplitterRect = rc;
}

int hbDockSplitNodeHitTest(
   const HB_DOCK_SPLIT_NODE * pSplit,
   POINT pt )
{
   if( pSplit == NULL )
      return 0;

   return PtInRect(
      ( RECT * ) &pSplit->SplitterRect,
      pt );
}

void hbDockSplitNodeMove(
   HB_DOCK_SPLIT_NODE * pSplit,
   int Delta )
{
   int Size;

   if( pSplit == NULL )
      return;

   if( pSplit->Node == NULL )
      return;

   pSplit->Node->SplitPos += Delta;

   if( pSplit->Node->Type == HB_DOCK_NODE_SPLIT_H )
   {
      Size = pSplit->Node->Rect.right -
             pSplit->Node->Rect.left;
   }
   else
   {
      Size = pSplit->Node->Rect.bottom -
             pSplit->Node->Rect.top;
   }

   if( pSplit->Node->SplitPos < pSplit->MinFirst )
      pSplit->Node->SplitPos = pSplit->MinFirst;

   if( pSplit->Node->SplitPos >
       Size - pSplit->MinSecond )
      pSplit->Node->SplitPos =
         Size - pSplit->MinSecond;
}