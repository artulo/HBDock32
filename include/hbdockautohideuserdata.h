#ifndef HBDOCKAUTOHIDEUSERDATA_H
#define HBDOCKAUTOHIDEUSERDATA_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetUserData(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   void * pData );

void * hbDockAutoHideGetUserData(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif