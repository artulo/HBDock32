#include <windows.h>

#include "hbdockautohidebuttoncapture.h"

void hbDockAutoHideButtonSetCapture(
    HWND hWnd )
{
    if( hWnd != NULL )
        SetCapture( hWnd );
}

void hbDockAutoHideButtonReleaseCapture( void )
{
    ReleaseCapture();
}

int hbDockAutoHideButtonHasCapture(
    HWND hWnd )
{
    return GetCapture() == hWnd;
}