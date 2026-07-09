#ifndef HBDOCKFLOATINGUSERDATA_H
#define HBDOCKFLOATINGUSERDATA_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingSetUserData(
   HB_DOCK_FLOATING_FRAME * pFrame,
   void * pData );

void * hbDockFloatingGetUserData(
   const HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif