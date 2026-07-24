#ifndef HBDOCKGUIDEWINDOW_H
#define HBDOCKGUIDEWINDOW_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockGuideWindowRegister(
   HINSTANCE hInstance );

HWND hbDockGuideWindowCreate(
   HWND hParent );

void hbDockGuideWindowDestroy(
   HWND hWnd );

void hbDockGuideWindowShow(
   HWND hWnd );

void hbDockGuideWindowHide(
   HWND hWnd );

void hbDockGuideWindowMove(
   HWND hWnd,
   const RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif