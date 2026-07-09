#ifndef HBDOCKFLOATINGENUMERATE_H
#define HBDOCKFLOATINGENUMERATE_H

#include "hbdockfloatingmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int ( * HB_DOCK_FLOATING_ENUMPROC )(
   HB_DOCK_FLOATING_FRAME * pFrame,
   void * Cargo );

void hbDockFloatingEnum(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HB_DOCK_FLOATING_ENUMPROC pProc,
   void * Cargo );

#ifdef __cplusplus
}
#endif

#endif