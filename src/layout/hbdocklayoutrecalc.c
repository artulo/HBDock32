#include <windows.h>

#include "hbdocklayoutrecalc.h"
#include "hbdocklayouttree.h"
#include "hbdockcontainer.h"

#define HBDOCK_SPLITTER_SIZE 4

static void hbDockLayoutRecalcNode(
   HB_DOCK_LAYOUT_NODE * pNode,
   const RECT * pRect )
{
   RECT rcFirst;
   RECT rcSecond;

   LONG Size;
   LONG Split;

   if( pNode == NULL )
      return;

   pNode->Rect = *pRect;

   if( pNode->Type == HB_LAYOUT_LEAF )
   {
      if( pNode->pContainer != NULL )
         pNode->pContainer->Rect = *pRect;

      return;
   }

   rcFirst = *pRect;
   rcSecond = *pRect;

   if( pNode->Type == HB_LAYOUT_HORIZONTAL )
   {
      Size =
         pRect->right -
         pRect->left;

      Split =
         ( LONG ) ( ( double ) Size *
                    pNode->Ratio );

      rcFirst.right =
         rcFirst.left +
         Split;

      rcSecond.left =
         rcFirst.right +
         HBDOCK_SPLITTER_SIZE;
   }
   else
   {
      Size =
         pRect->bottom -
         pRect->top;

      Split =
         ( LONG ) ( ( double ) Size *
                    pNode->Ratio );

      rcFirst.bottom =
         rcFirst.top +
         Split;

      rcSecond.top =
         rcFirst.bottom +
         HBDOCK_SPLITTER_SIZE;
   }

   hbDockLayoutRecalcNode(
      pNode->First,
      &rcFirst );

   hbDockLayoutRecalcNode(
      pNode->Second,
      &rcSecond );
}

void hbDockLayoutRecalc(
   HB_DOCK_LAYOUT_TREE * pTree,
   const RECT * pRect )
{
   if( pTree == NULL )
      return;

   if( pTree->Root == NULL )
      return;

   if( pRect == NULL )
      return;

   hbDockLayoutRecalcNode(
      pTree->Root,
      pRect );
}