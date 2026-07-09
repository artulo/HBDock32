#ifndef HBDOCKFLOATINGFIRST_H
#define HBDOCKFLOATINGFIRST_H

#include "hbdockfloatingmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_FLOATING_FRAME * hbDockFloatingFirst(
   HB_DOCK_FLOATING_MANAGER * pManager );

HB_DOCK_FLOATING_FRAME * hbDockFloatingLast(
   HB_DOCK_FLOATING_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif