/*
 * ---------------------------------------------------------------------------
 * HBDock32
 * Window Manager
 *
 * File : hbwindow.h
 *
 * ANSI C89
 * Win32
 * ---------------------------------------------------------------------------
 */

#ifndef HBDOCK_WINDOW_H
#define HBDOCK_WINDOW_H

#include <windows.h>

#include "hbdock.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_WINDOW HB_WINDOW;

typedef LRESULT (*HB_WNDPROC)
(
    HB_WINDOW *,
    HWND,
    UINT,
    WPARAM,
    LPARAM
);

struct _HB_WINDOW
{
    HWND        hWnd;

    HINSTANCE   hInstance;

    char        szClassName[64];

    char        szWindowTitle[128];

    DWORD       dwStyle;

    DWORD       dwExStyle;

    int         X;

    int         Y;

    int         Width;

    int         Height;

    HB_WNDPROC  WindowProc;

    void *      Cargo;
};

/*-----------------------------------------------------------*/

HB_WINDOW * hbWindowNew( void );

void hbWindowDelete(
        HB_WINDOW * pWindow );

BOOL hbWindowRegister(
        HB_WINDOW * pWindow );

BOOL hbWindowCreate(
        HB_WINDOW * pWindow );

void hbWindowShow(
        HB_WINDOW * pWindow,
        int nCmdShow );

int hbWindowMessageLoop( void );

#ifdef __cplusplus
}
#endif

#endif