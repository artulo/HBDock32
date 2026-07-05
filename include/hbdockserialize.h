#ifndef HBDOCKSERIALIZE_H
#define HBDOCKSERIALIZE_H

#include <windows.h>

#include "hbdockstate.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockStateSave(
   HANDLE hFile,
   const HB_DOCK_STATE * pState );

BOOL hbDockStateLoad(
   HANDLE hFile,
   HB_DOCK_STATE * pState );

#ifdef __cplusplus
}
#endif

#endif