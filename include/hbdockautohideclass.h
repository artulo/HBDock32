#ifndef HBDOCKAUTOHIDECLASS_H
#define HBDOCKAUTOHIDECLASS_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HB_DOCK_AUTOHIDE_CLASS TEXT( "HB_DOCK_AUTOHIDE" )

ATOM hbDockAutoHideRegisterClass(
   HINSTANCE hInstance );

void hbDockAutoHideUnregisterClass(
   HINSTANCE hInstance );

#ifdef __cplusplus
}
#endif

#endif