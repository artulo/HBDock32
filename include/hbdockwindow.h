#ifndef HBDOCKWINDOW_H
#define HBDOCKWINDOW_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HB_DOCKWND_CLASS "HBDockPanel"

BOOL hbDockWindowRegisterClass(
    HINSTANCE hInstance );

HWND hbDockWindowCreate(
    HWND hParent,
    HINSTANCE hInstance,
    const char * pszTitle,
    DWORD dwStyle,
    DWORD dwExStyle );

#ifdef __cplusplus
}
#endif

#endif