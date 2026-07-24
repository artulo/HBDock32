#include <windows.h>

#include "hbdocksplitnode.h"

#define HBDOCK_SPLITTER_SIZE 4

void hbDockSplitNodeInit(
   HB_DOCK_SPLIT_NODE * pSplit,
   HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pSplit == NULL )
      return;

   ZeroMemory(
      pSplit,
      sizeof( HB_DOCK_SPLIT_NODE ) );

   pSplit->Node = pNode;

   pSplit->Tracking = FALSE;

   pSplit->MinFirst  = 80;
   pSplit->MinSecond = 80;

   hbDockSplitNodeUpdate(
      pSplit );
}

void hbDockSplitNodeUpdate(
   HB_DOCK_SPLIT_NODE * pSplit )
{
   RECT rc;
   LONG Size;
   LONG Pos;

   if( pSplit == NULL )
      return;

   if( pSplit->Node == NULL )
      return;

   rc = pSplit->Node->Rect;

   if( pSplit->Node->Type == HB_LAYOUT_HORIZONTAL )
   {
      Size = rc.right - rc.left;

      Pos = ( LONG ) ( ( double ) Size *
                       pSplit->Node->Ratio );

      rc.left  += Pos;
      rc.right  = rc.left + HBDOCK_SPLITTER_SIZE;
   }
   else
   {
      Size = rc.bottom - rc.top;

      Pos = ( LONG ) ( ( double ) Size *
                       pSplit->Node->Ratio );

      rc.top    += Pos;
      rc.bottom  = rc.top + HBDOCK_SPLITTER_SIZE;
   }

   pSplit->SplitterRect = rc;
}

int hbDockSplitNodeHitTest(
   const HB_DOCK_SPLIT_NODE * pSplit,
   POINT pt )
{
   if( pSplit == NULL )
      return FALSE;

   return PtInRect(
      &pSplit->SplitterRect,
      pt );
}

void hbDockSplitNodeMove(
   HB_DOCK_SPLIT_NODE * pSplit,
   int Delta )
{
   LONG Size;
   double Ratio;

   if( pSplit == NULL )
      return;

   if( pSplit->Node == NULL )
      return;

   if( pSplit->Node->Type == HB_LAYOUT_HORIZONTAL )
      Size = pSplit->Node->Rect.right -
             pSplit->Node->Rect.left;
   else
      Size = pSplit->Node->Rect.bottom -
             pSplit->Node->Rect.top;

   if( Size <= 0 )
      return;

   Ratio =
      pSplit->Node->Ratio +
      ( ( double ) Delta / ( double ) Size );

   if( Ratio < 0.10 )
      Ratio = 0.10;

   if( Ratio > 0.90 )
      Ratio = 0.90;

   pSplit->Node->Ratio = ( float ) Ratio;

   hbDockSplitNodeUpdate(
      pSplit );
}