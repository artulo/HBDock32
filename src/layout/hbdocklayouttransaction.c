#include "hbdocklayouttransaction.h"

void hbDockLayoutTransactionBegin(
   HB_DOCK_LAYOUT_TRANSACTION * pTransaction,
   HB_DOCK_MANAGER_STATE * pState )
{
   pTransaction->State = pState;
   pTransaction->Active = 1;

   if( pState != NULL )
   {
      hbDockHistorySave(
         &pState->History,
         pState->Root );
   }
}

void hbDockLayoutTransactionCommit(
   HB_DOCK_LAYOUT_TRANSACTION * pTransaction )
{
   pTransaction->Active = 0;
}

void hbDockLayoutTransactionRollback(
   HB_DOCK_LAYOUT_TRANSACTION * pTransaction )
{
   if( pTransaction->State == NULL )
      return;

   pTransaction->State->Root =
      hbDockHistoryUndo(
         &pTransaction->State->History,
         pTransaction->State->Root );

   pTransaction->Active = 0;
}