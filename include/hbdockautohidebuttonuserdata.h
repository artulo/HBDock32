#ifndef HBDOCKAUTOHIDEBUTTONUSERDATA_H
#define HBDOCKAUTOHIDEBUTTONUSERDATA_H

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideButtonSetUserData(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   void * pData );

void * hbDockAutoHideButtonGetUserData(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

#ifdef __cplusplus
}
#endif

#endif