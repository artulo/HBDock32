#include "hbdockhistory.h"
#include "hbdocktreeclone.h"

void hbDockHistoryInit(
   HB_DOCK_HISTORY * pHistory )
{
   hbDockUndoInit(
      &pHistory->Undo );

   hbDockRedoInit(
      &pHistory->Redo );
}

void hbDockHistorySave(
   HB_DOCK_HISTORY * pHistory,
   HB_DOCK_NODE * pRoot )
{
   hbDockUndoPush(
      &pHistory->Undo,
      pRoot );

   hbDockRedoInit(
      &pHistory->Redo );
}

HB_DOCK_NODE * hbDockHistoryUndo(
   HB_DOCK_HISTORY * pHistory,
   HB_DOCK_NODE * pCurrent )
{
   if( pCurrent != NULL )
      hbDockRedoPush(
         &pHistory->Redo,
         pCurrent );

   return hbDockUndoPop(
      &pHistory->Undo );
}

HB_DOCK_NODE * hbDockHistoryRedo(
   HB_DOCK_HISTORY * pHistory,
   HB_DOCK_NODE * pCurrent )
{
   if( pCurrent != NULL )
      hbDockUndoPush(
         &pHistory->Undo,
         pCurrent );

   return hbDockRedoPop(
      &pHistory->Redo );
}