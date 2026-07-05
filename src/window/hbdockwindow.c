#include <windows.h>

#include "hbdockwindow.h"

static LRESULT CALLBACK hbDockWindowProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam )
{
    switch( uMsg )
    {
        case WM_ERASEBKGND:
            return 1;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            RECT rc;
            HBRUSH hBrush;

            BeginPaint(
                hWnd,
                &ps );

            GetClientRect(
                hWnd,
                &rc );

            hBrush = CreateSolidBrush(
                RGB( 230, 230, 230 ) );

            FillRect(
                ps.hdc,
                &rc,
                hBrush );

            DeleteObject(
                hBrush );

            DrawEdge(
                ps.hdc,
                &rc,
                EDGE_RAISED,
                BF_RECT );

            EndPaint(
                hWnd,
                &ps );

            return 0;
        }
    }

    return DefWindowProc(
        hWnd,
        uMsg,
        wParam,
        lParam );
}

BOOL hbDockWindowRegisterClass(
    HINSTANCE hInstance )
{
    WNDCLASS wc;

    ZeroMemory(
        &wc,
        sizeof( wc ) );

    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = hbDockWindowProc;
    wc.hInstance     = hInstance;
    wc.hCursor       = LoadCursor(
                           NULL,
                           IDC_ARROW );
    wc.hbrBackground = (HBRUSH)( COLOR_BTNFACE + 1 );
    wc.lpszClassName = HB_DOCKWND_CLASS;

    return RegisterClass(
        &wc ) != 0;
}

HWND hbDockWindowCreate(
    HWND hParent,
    HINSTANCE hInstance,
    const char * pszTitle,
    DWORD dwStyle,
    DWORD dwExStyle )
{
    return CreateWindowEx(
        dwExStyle,
        HB_DOCKWND_CLASS,
        pszTitle,
        dwStyle,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        200,
        200,
        hParent,
        NULL,
        hInstance,
        NULL );
}