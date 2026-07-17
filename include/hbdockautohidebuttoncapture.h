#ifndef HBDOCKAUTOHIDEBUTTONCAPTURE_H
#define HBDOCKAUTOHIDEBUTTONCAPTURE_H

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideButtonSetCapture(
    HWND hWnd );

int hbDockAutoHideButtonHasCapture(
    HWND hWnd );

void hbDockAutoHideButtonReleaseCapture( void );


#ifdef __cplusplus
}
#endif

#endif