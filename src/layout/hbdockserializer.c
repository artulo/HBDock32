#include <stdio.h>

#include "hbdockserializer.h"

static int hbDockSaveNode(
   FILE * fp,
   HB_DOCK_NODE * pNode )
{
   if( pNode == NULL )
   {
      fprintf(
         fp,
         "#\n" );

      return 1;
   }

   fprintf(
      fp,
      "%d %d %d\n",
      ( int ) pNode->Type,
      pNode->SplitPos,
      pNode->SplitterSize );

   hbDockSaveNode(
      fp,
      pNode->First );

   hbDockSaveNode(
      fp,
      pNode->Second );

   return 1;
}

int hbDockTreeSave(
   FILE * fp,
   HB_DOCK_NODE * pRoot )
{
   if( fp == NULL )
      return 0;

   return hbDockSaveNode(
      fp,
      pRoot );
}

static HB_DOCK_NODE * hbDockLoadNode(
   FILE * fp )
{
   int Type;
   int Pos;
   int Size;
   HB_DOCK_NODE * pNode;

   if( fscanf(
         fp,
         "%d",
         &Type ) != 1 )
      return NULL;

   if( Type == '#')
      return NULL;

   fscanf(
      fp,
      "%d%d",
      &Pos,
      &Size );

   if( Type == HB_DOCK_NODE_LEAF )
      pNode = hbDockNodeNewLeaf(
         NULL );
   else
      pNode = hbDockNodeNewSplit(
         ( HB_DOCK_NODE_TYPE ) Type,
         NULL,
         NULL );

   pNode->SplitPos = Pos;
   pNode->SplitterSize = Size;

   pNode->First =
      hbDockLoadNode(
         fp );

   if( pNode->First != NULL )
      pNode->First->Parent =
         pNode;

   pNode->Second =
      hbDockLoadNode(
         fp );

   if( pNode->Second != NULL )
      pNode->Second->Parent =
         pNode;

   return pNode;
}

HB_DOCK_NODE * hbDockTreeLoad(
   FILE * fp )
{
   if( fp == NULL )
      return NULL;

   return hbDockLoadNode(
      fp );
}