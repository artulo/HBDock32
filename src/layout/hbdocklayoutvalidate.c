#include <windows.h>

#include "hbdocklayoutvalidate.h"

static BOOL hbDockLayoutValidateNode(
   const HB_DOCK_LAYOUT_NODE * pNode,
   const HB_DOCK_LAYOUT_NODE * pParent )
{
   if( pNode == NULL )
      return TRUE;

   /*
    * El padre debe coincidir.
    */

   if( pNode->Parent != pParent )
      return FALSE;

   switch( pNode->Type )
   {
      case HB_LAYOUT_LEAF:

         /*
          * Una hoja no puede tener hijos.
          */

         if( pNode->First != NULL )
            return FALSE;

         if( pNode->Second != NULL )
            return FALSE;

         break;

      case HB_LAYOUT_HORIZONTAL:
      case HB_LAYOUT_VERTICAL:

         /*
          * Un nodo de división debe tener
          * ambos hijos.
          */

         if( pNode->First == NULL )
            return FALSE;

         if( pNode->Second == NULL )
            return FALSE;

         /*
          * Ratio válido.
          */

         if( pNode->Ratio <= 0.0 )
            return FALSE;

         if( pNode->Ratio >= 1.0 )
            return FALSE;

         if( !hbDockLayoutValidateNode(
                  pNode->First,
                  pNode ) )
            return FALSE;

         if( !hbDockLayoutValidateNode(
                  pNode->Second,
                  pNode ) )
            return FALSE;

         break;

      default:

         return FALSE;
   }

   return TRUE;
}

BOOL hbDockLayoutValidate(
   const HB_DOCK_LAYOUT_TREE * pTree )
{
   if( pTree == NULL )
      return FALSE;

   if( pTree->Root == NULL )
      return TRUE;

   return hbDockLayoutValidateNode(
      pTree->Root,
      NULL );
}