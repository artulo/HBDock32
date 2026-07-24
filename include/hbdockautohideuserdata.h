#ifndef HBDOCKAUTOHIDEUSERDATA_H
#define HBDOCKAUTOHIDEUSERDATA_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetUserData(
   HB_DOCK_AUTOHIDE * pAutoHide,
   void * pData );


void * hbDockAutoHideGetUserData(
   HB_DOCK_AUTOHIDE * pAutoHide );


#ifdef __cplusplus
}
#endif

#endif