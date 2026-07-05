/*
 * ---------------------------------------------------------------------------
 * HBDock32
 * Window Manager
 * ---------------------------------------------------------------------------
 */

#include <windows.h>
#include <string.h>
#include <stdlib.h>

#include "hbwindow.h"

static LRESULT CALLBACK
hbInternalWndProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam );

HB_WINDOW * hbWindowNew( void )
{
    HB_WINDOW * p;

    p = (HB_WINDOW *) malloc(
            sizeof(HB_WINDOW));

    if( p == NULL )
        return NULL;

    ZeroMemory(
        p,
        sizeof(HB_WINDOW));

    p->hInstance = GetModuleHandle(NULL);

    strcpy(
        p->szClassName,
        "HBDock32Main");

    strcpy(
        p->szWindowTitle,
        "HBDock32");

    p->dwStyle = WS_OVERLAPPEDWINDOW;

    p->Width = 1024;

    p->Height = 768;

    return p;
}

void hbWindowDelete(
    HB_WINDOW * p )
{
    if( p == NULL )
        return;

    free(p);
}

BOOL hbWindowRegister(
    HB_WINDOW * p )
{
    WNDCLASS wc;

    ZeroMemory(
        &wc,
        sizeof(wc));

    wc.style =
        CS_HREDRAW |
        CS_VREDRAW;

    wc.lpfnWndProc =
        hbInternalWndProc;

    wc.hInstance =
        p->hInstance;

    wc.hCursor =
        LoadCursor(
            NULL,
            IDC_ARROW);

    wc.hbrBackground =
        (HBRUSH)
        (COLOR_BTNFACE+1);

    wc.lpszClassName =
        p->szClassName;

    return RegisterClass(
        &wc);
}

BOOL hbWindowCreate(
    HB_WINDOW * p )
{
    p->hWnd =
        CreateWindow(

            p->szClassName,

            p->szWindowTitle,

            p->dwStyle,

            CW_USEDEFAULT,

            CW_USEDEFAULT,

            p->Width,

            p->Height,

            NULL,

            NULL,

            p->hInstance,

            p );

    return
        (p->hWnd != NULL);
}

void hbWindowShow(
    HB_WINDOW * p,
    int nCmdShow )
{
    ShowWindow(
        p->hWnd,
        nCmdShow);

    UpdateWindow(
        p->hWnd);
}

int hbWindowMessageLoop( void )
{
    MSG msg;

    while(
        GetMessage(
            &msg,
            NULL,
            0,
            0))
    {
        TranslateMessage(
            &msg);

        DispatchMessage(
            &msg);
    }

    return
        (int)
        msg.wParam;
}

static LRESULT CALLBACK
hbInternalWndProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam )
{
    switch(uMsg)
    {
        case WM_DESTROY:

            PostQuitMessage(0);

            return 0;
    }

    return
        DefWindowProc(
            hWnd,
            uMsg,
            wParam,
            lParam);
}