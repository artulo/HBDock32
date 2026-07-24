#include "hbdockmanagerstate.h"

void hbDockManagerStateInit(
   HB_DOCK_MANAGER_STATE * pState )
{
   hbDockLayoutEngineInit(
      &pState->Layout );

   hbDockHistoryInit(
      &pState->History );

   pState->Root = NULL;
}

void hbDockManagerStateClear(
   HB_DOCK_MANAGER_STATE * pState )
{
   if( pState->Root != NULL )
   {
      hbDockNodeDelete(
         pState->Root );

      pState->Root = NULL;
   }

   hbDockHistoryInit(
      &pState->History );
}