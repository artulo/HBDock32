#include "hbdockundo.h"
#include "hbdocktreeclone.h"

void hbDockUndoInit(
   HB_DOCK_UNDO * pUndo )
{
   int i;

   pUndo->Count = 0;

   for( i = 0;
        i < HB_DOCK_UNDO_LEVELS;
        i++ )
      pUndo->States[ i ] = NULL;
}

void hbDockUndoPush(
   HB_DOCK_UNDO * pUndo,
   HB_DOCK_NODE * pRoot )
{
   int i;

   if( pUndo->Count ==
       HB_DOCK_UNDO_LEVELS )
   {
      hbDockNodeDelete(
         pUndo->States[ 0 ] );

      for( i = 1;
           i < HB_DOCK_UNDO_LEVELS;
           i++ )
         pUndo->States[ i - 1 ] =
            pUndo->States[ i ];

      pUndo->Count--;
   }

   pUndo->States[
      pUndo->Count++ ] =
      hbDockTreeClone(
         pRoot );
}

HB_DOCK_NODE * hbDockUndoPop(
   HB_DOCK_UNDO * pUndo )
{
   if( pUndo->Count == 0 )
      return NULL;

   pUndo->Count--;

   return pUndo->States[
      pUndo->Count ];
}