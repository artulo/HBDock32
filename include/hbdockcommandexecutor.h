#ifndef HBDOCKCOMMANDEXECUTOR_H
#define HBDOCKCOMMANDEXECUTOR_H

#include "hbdockmanager.h"
#include "hbdockcommand.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockExecuteCommand(
      HB_DOCK_MANAGER * pManager,
      const HB_DOCK_COMMAND * pCommand );

#ifdef __cplusplus
}
#endif

#endif