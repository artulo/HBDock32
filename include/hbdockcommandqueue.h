#ifndef HBDOCKCOMMANDQUEUE_H
#define HBDOCKCOMMANDQUEUE_H

#include "hbdockcommand.h"

#define HB_DOCK_MAX_COMMANDS 256

typedef struct
{
   HB_DOCK_COMMAND Commands[HB_DOCK_MAX_COMMANDS];

   UINT Head;

   UINT Tail;

   UINT Count;

} HB_DOCK_COMMAND_QUEUE;

BOOL hbDockCommandQueueInit(
      HB_DOCK_COMMAND_QUEUE * pQueue );

BOOL hbDockCommandPush(
      HB_DOCK_COMMAND_QUEUE * pQueue,
      const HB_DOCK_COMMAND * pCommand );

BOOL hbDockCommandPop(
      HB_DOCK_COMMAND_QUEUE * pQueue,
      HB_DOCK_COMMAND * pCommand );

#endif