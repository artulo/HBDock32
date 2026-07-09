#ifndef HBDOCKFLOATINGCREATE_H
#define HBDOCKFLOATINGCREATE_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockFloatingCreateWindow(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HWND hOwner,
   LPCTSTR lpCaption );

#ifdef __cplusplus
}
#endif

#endif