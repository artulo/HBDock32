#include "hbdocksplitter.h"

#define HB_SPLITTER_SIZE 4

BOOL hbDockSplitterBuild(
      HB_DOCK_LAYOUT_NODE * pNode,
      HB_DOCK_SPLITTER * pSplitter )
{
   RECT rc;

   if( pNode == NULL )
      return FALSE;

   if( pNode->Type == HB_LAYOUT_LEAF )
      return FALSE;

   rc = pNode->Rect;

   pSplitter->pNode = pNode;
   pSplitter->Tracking = FALSE;
   pSplitter->Size = HB_SPLITTER_SIZE;

   if( pNode->Type == HB_LAYOUT_VERTICAL )
   {
      LONG x;

      x = rc.left +
          (LONG)((rc.right - rc.left) * pNode->Ratio);

      SetRect(
         &pSplitter->Rect,
         x - HB_SPLITTER_SIZE / 2,
         rc.top,
         x + HB_SPLITTER_SIZE / 2,
         rc.bottom );
   }
   else
   {
      LONG y;

      y = rc.top +
          (LONG)((rc.bottom - rc.top) * pNode->Ratio);

      SetRect(
         &pSplitter->Rect,
         rc.left,
         y - HB_SPLITTER_SIZE / 2,
         rc.right,
         y + HB_SPLITTER_SIZE / 2 );
   }

   return TRUE;
}