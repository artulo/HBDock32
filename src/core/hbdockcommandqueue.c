#include <string.h>

#include "hbdockcommandqueue.h"

BOOL hbDockCommandQueueInit(
      HB_DOCK_COMMAND_QUEUE * pQueue )
{
   ZeroMemory(
      pQueue,
      sizeof(*pQueue));

   return TRUE;
}

BOOL hbDockCommandPush(
      HB_DOCK_COMMAND_QUEUE * pQueue,
      const HB_DOCK_COMMAND * pCommand )
{
   if(pQueue->Count>=HB_DOCK_MAX_COMMANDS)
      return FALSE;

   pQueue->Commands[
      pQueue->Tail]=*pCommand;

   pQueue->Tail++;

   if(pQueue->Tail>=HB_DOCK_MAX_COMMANDS)
      pQueue->Tail=0;

   pQueue->Count++;

   return TRUE;
}

BOOL hbDockCommandPop(
      HB_DOCK_COMMAND_QUEUE * pQueue,
      HB_DOCK_COMMAND * pCommand )
{
   if(pQueue->Count==0)
      return FALSE;

   *pCommand=
      pQueue->Commands[
         pQueue->Head];

   pQueue->Head++;

   if(pQueue->Head>=HB_DOCK_MAX_COMMANDS)
      pQueue->Head=0;

   pQueue->Count--;

   return TRUE;
}