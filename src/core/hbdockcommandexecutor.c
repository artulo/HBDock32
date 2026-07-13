#include "hbdockcommandexecutor.h"

#include "hbdockdockoperation.h"
#include "hbdockfloatoperation.h"
#include "hbdockautohideoperation.h"
#include "hbdocksplitoperation.h"
#include "hbdocktaboperation.h"
#include "hbdocklayoutsync.h"

BOOL hbDockExecuteCommand(
      HB_DOCK_MANAGER * pManager,
      const HB_DOCK_COMMAND * pCommand )
{
   BOOL Result = FALSE;

   if( pManager == NULL || pCommand == NULL )
      return FALSE;

   switch( pCommand->Type )
   {
      case HB_CMD_DOCK:

         Result =
            hbDockExecuteDock(
               pManager,
               pCommand );

         break;

      case HB_CMD_FLOAT:

         Result =
            hbDockExecuteFloat(
               pManager,
               pCommand );

         break;

      case HB_CMD_AUTOHIDE:

         Result =
            hbDockExecuteAutoHide(
               pManager,
               pCommand );

         break;

      case HB_CMD_SPLIT:

         Result =
            hbDockExecuteSplit(
               pManager,
               pCommand );

         break;

      case HB_CMD_TABIFY:

         Result =
            hbDockExecuteTab(
               pManager,
               pCommand );

         break;

      default:

         Result = FALSE;
   }

   if( Result )
      hbDockLayoutSynchronize( pManager );

   return Result;
}