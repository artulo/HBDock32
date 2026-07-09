#ifndef HBDOCKFLOATINGCLASS_H
#define HBDOCKFLOATINGCLASS_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HB_DOCK_FLOATING_CLASS TEXT("HB_DOCK_FLOATING_FRAME")

ATOM hbDockFloatingRegisterClass(
   HINSTANCE hInstance );

void hbDockFloatingUnregisterClass(
   HINSTANCE hInstance );

#ifdef __cplusplus
}
#endif

#endif