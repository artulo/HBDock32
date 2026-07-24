#include <stdlib.h>
#include <string.h>

#include "hbdocklayoutdeserialize.h"
#include "hbdocklayoutnodecreate.h"

static HB_DOCK_LAYOUT_NODE * hbDockDeserializeNode(
   HB_DOCK_LAYOUT_READER Reader,
   void * Cargo );

static HB_DOCK_LAYOUT_NODE * hbDockDeserializeSplit(
   HB_LAYOUT_NODE_TYPE Type,
   HB_DOCK_LAYOUT_READER Reader,
   void * Cargo )
{
   HB_DOCK_LAYOUT_NODE * pNode;
   HB_DOCK_LAYOUT_NODE * pFirst;
   HB_DOCK_LAYOUT_NODE * pSecond;
   const char * pszRatio;

   pFirst =
      hbDockDeserializeNode(
         Reader,
         Cargo );

   pSecond =
      hbDockDeserializeNode(
         Reader,
         Cargo );

   pNode =
      hbDockLayoutNodeCreateSplit(
         Type,
         pFirst,
         pSecond );

   if( pNode == NULL )
      return NULL;

   pszRatio =
      Reader(
         Cargo );

   if( pszRatio != NULL )
      pNode->Ratio =
         atof(
            pszRatio );

   return pNode;
}

static HB_DOCK_LAYOUT_NODE * hbDockDeserializeNode(
   HB_DOCK_LAYOUT_READER Reader,
   void * Cargo )
{
   const char * pszToken;

   pszToken =
      Reader(
         Cargo );

   if( pszToken == NULL )
      return NULL;

   if( strcmp(
            pszToken,
            "NULL" ) == 0 )
   {
      return NULL;
   }

   if( strcmp(
            pszToken,
            "LEAF" ) == 0 )
   {
      Reader(
         Cargo );

      return hbDockLayoutNodeCreateLeaf(
         NULL );
   }

   if( strcmp(
            pszToken,
            "HSPLIT" ) == 0 )
   {
      return hbDockDeserializeSplit(
         HB_LAYOUT_HORIZONTAL,
         Reader,
         Cargo );
   }

   if( strcmp(
            pszToken,
            "VSPLIT" ) == 0 )
   {
      return hbDockDeserializeSplit(
         HB_LAYOUT_VERTICAL,
         Reader,
         Cargo );
   }

   return NULL;
}

BOOL hbDockLayoutDeserialize(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_READER Reader,
   void * Cargo )
{
   if( pTree == NULL )
      return FALSE;

   if( Reader == NULL )
      return FALSE;

   pTree->Root =
      hbDockDeserializeNode(
         Reader,
         Cargo );

   return pTree->Root != NULL;
}