#include <windows.h>

#include "hbdocktreesplitfind.h"

#define HBDOCK_SPLITTER_SIZE   4

static void hbDockNodeSplitterRect(
   const HB_DOCK_LAYOUT_NODE * pNode,
   RECT * pRect )
{
   LONG Size;
   LONG Pos;

   if( pNode == NULL || pRect == NULL )
      return;

   *pRect = pNode->Rect;

   switch( pNode->Type )
   {
      case HB_LAYOUT_HORIZONTAL:

         Size =
            pNode->Rect.right -
            pNode->Rect.left;

         Pos =
            ( LONG )
            ( ( double ) Size *
              ( double ) pNode->Ratio );

         pRect->left =
            pNode->Rect.left + Pos;

         pRect->right =
            pRect->left +
            HBDOCK_SPLITTER_SIZE;

         break;

      case HB_LAYOUT_VERTICAL:

         Size =
            pNode->Rect.bottom -
            pNode->Rect.top;

         Pos =
            ( LONG )
            ( ( double ) Size *
              ( double ) pNode->Ratio );

         pRect->top =
            pNode->Rect.top + Pos;

         pRect->bottom =
            pRect->top +
            HBDOCK_SPLITTER_SIZE;

         break;

      default:

         break;
   }
}

HB_DOCK_LAYOUT_NODE * hbDockTreeFindSplitterAt(
   HB_DOCK_LAYOUT_NODE * pNode,
   POINT pt )
{
   RECT rc;

   HB_DOCK_LAYOUT_NODE * pFound;

   if( pNode == NULL )
      return NULL;

   if( pNode->Type == HB_LAYOUT_LEAF )
      return NULL;

   hbDockNodeSplitterRect(
      pNode,
      &rc );

   if( PtInRect(
         &rc,
         pt ) )
   {
      return pNode;
   }

   pFound =
      hbDockTreeFindSplitterAt(
         pNode->First,
         pt );

   if( pFound != NULL )
      return pFound;

   return
      hbDockTreeFindSplitterAt(
         pNode->Second,
         pt );
}