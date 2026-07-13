#include "hbdockengineprocess.h"

#include "hbdockcommandqueue.h"

static BOOL ExecuteCommand(
      HB_DOCK_MANAGER * pManager,
      HB_DOCK_COMMAND * pCmd );

BOOL hbDockEngineProcessQueue(
      HB_DOCK_MANAGER * pManager )
{
   HB_DOCK_COMMAND Cmd;

   while(
      hbDockCommandPop(
         &pManager->CommandQueue,
         &Cmd))
   {
      ExecuteCommand(
         pManager,
         &Cmd);
   }

   return TRUE;
}
static BOOL ExecuteCommand(
      HB_DOCK_MANAGER * pManager,
      HB_DOCK_COMMAND * pCmd )
{
   switch(pCmd->Type)
   {

      case HB_CMD_DOCK:

         /* Dock Panel */

         break;

      case HB_CMD_FLOAT:

         /* Float Window */

         break;

      case HB_CMD_AUTOHIDE:

         /* AutoHide */

         break;

      case HB_CMD_SPLIT:

         /* Split Container */

         break;

      case HB_CMD_TABIFY:

         /* Crear TabGroup */

         break;

      case HB_CMD_RESTORE_LAYOUT:

         /* Restaurar XML */

         break;

      default:

         break;
   }

   return TRUE;
}
