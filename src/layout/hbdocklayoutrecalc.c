#include "hbdocklayoutrecalc.h"
#include "hbdockcontainer.h"

static void hbDockLayoutCalcNode(
      HB_DOCK_LAYOUT_NODE * pNode,
      RECT rc )
{
   RECT rc1;
   RECT rc2;

   if( pNode == NULL )
      return;

   pNode->Rect = rc;

   if( pNode->Type == HB_LAYOUT_LEAF )
   {
		if( pNode->pContainer != NULL &&
			pNode->pContainer->hWnd != NULL )
		{
		   MoveWindow(
			  pNode->pContainer->hWnd,
			  rc.left,
			  rc.top,
			  rc.right - rc.left,
			  rc.bottom - rc.top,
			  TRUE );
		}
		return;
   }

   rc1 = rc;
   rc2 = rc;

   if( pNode->Type == HB_LAYOUT_HORIZONTAL )
   {
      rc1.bottom = rc.top +
         (LONG)((rc.bottom - rc.top) * pNode->Ratio);

      rc2.top = rc1.bottom;
   }
   else
   {
      rc1.right = rc.left +
         (LONG)((rc.right - rc.left) * pNode->Ratio);

      rc2.left = rc1.right;
   }

   hbDockLayoutCalcNode( pNode->First, rc1 );
   hbDockLayoutCalcNode( pNode->Second, rc2 );
}

void hbDockLayoutRecalc(
      HB_DOCK_LAYOUT_TREE * pTree,
      RECT rcClient )
{
   hbDockLayoutCalcNode(
      pTree->Root,
      rcClient );
}