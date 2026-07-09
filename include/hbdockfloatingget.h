#ifndef HBDOCKFLOATINGGET_H
#define HBDOCKFLOATINGGET_H

#include "hbdockfloatingmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_FLOATING_FRAME * hbDockFloatingGet(
   HB_DOCK_FLOATING_MANAGER * pManager,
   int Index );

#ifdef __cplusplus
}
#endif

#endif