#ifndef HBDOCKAUTOHIDEENUM_H
#define HBDOCKAUTOHIDEENUM_H

#include "hbdockautohidemanager.h"
#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int ( * HB_DOCK_AUTOHIDE_ENUMPROC )(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   void * Cargo );

void hbDockAutoHideEnum(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   HB_DOCK_AUTOHIDE_ENUMPROC pProc,
   void * Cargo );

#ifdef __cplusplus
}
#endif

#endif