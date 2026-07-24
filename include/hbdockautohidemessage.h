#ifndef HBDOCKAUTOHIDEMESSAGE_H
#define HBDOCKAUTOHIDEMESSAGE_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

LRESULT hbDockAutoHideSendMessage(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam );

BOOL hbDockAutoHidePostMessage(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam );

#ifdef __cplusplus
}
#endif

#endif