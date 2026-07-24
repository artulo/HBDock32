#include <windows.h>

#include "hbdocklayoutserialize.h"

static void hbDockLayoutSerializeNode(
   const HB_DOCK_LAYOUT_NODE * pNode,
   HB_DOCK_LAYOUT_WRITER Writer,
   void * Cargo )
{
   char Buffer[64];

   if( pNode == NULL )
   {
      Writer(
         Cargo,
         "NULL" );
      return;
   }

   switch( pNode->Type )
   {
      case HB_LAYOUT_LEAF:

         Writer(
            Cargo,
            "LEAF" );

         /*
          * Identificador del panel.
          * De momento se deja vacío hasta que
          * exista el Registry del Manager.
          */

         Writer(
            Cargo,
            "-" );

         break;

      case HB_LAYOUT_HORIZONTAL:

         Writer(
            Cargo,
            "HSPLIT" );

         wsprintf(
            Buffer,
            "%.8f",
            pNode->Ratio );

         Writer(
            Cargo,
            Buffer );

         hbDockLayoutSerializeNode(
            pNode->First,
            Writer,
            Cargo );

         hbDockLayoutSerializeNode(
            pNode->Second,
            Writer,
            Cargo );

         break;

      case HB_LAYOUT_VERTICAL:

         Writer(
            Cargo,
            "VSPLIT" );

         wsprintf(
            Buffer,
            "%.8f",
            pNode->Ratio );

         Writer(
            Cargo,
            Buffer );

         hbDockLayoutSerializeNode(
            pNode->First,
            Writer,
            Cargo );

         hbDockLayoutSerializeNode(
            pNode->Second,
            Writer,
            Cargo );

         break;

      default:

         Writer(
            Cargo,
            "NULL" );

         break;
   }
}

BOOL hbDockLayoutSerialize(
   const HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_WRITER Writer,
   void * Cargo )
{
   if( pTree == NULL )
      return FALSE;

   if( Writer == NULL )
      return FALSE;

   hbDockLayoutSerializeNode(
      pTree->Root,
      Writer,
      Cargo );

   return TRUE;
}