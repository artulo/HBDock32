#ifndef HBDOCKCONTAINER_H
#define HBDOCKCONTAINER_H

#include <windows.h>

#include "hbdockmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_CONTAINER
{
   HWND             hWnd;
   HB_DOCK_MANAGER *pManager;

} HB_DOCK_CONTAINER;

BOOL hbDockContainerRegisterClass(
   HINSTANCE hInstance );

HWND hbDockContainerCreate(
   HWND hParent,
   HINSTANCE hInstance,
   HB_DOCK_MANAGER *pManager );

#ifdef __cplusplus
}
#endif

#endif