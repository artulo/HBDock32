#ifndef HBDOCKHOST_H
#define HBDOCKHOST_H

#include <windows.h>

#include "hbdockmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_HOST
{
   HWND hWnd;
   HB_DOCK_MANAGER * pManager;

} HB_DOCK_HOST;

BOOL hbDockHostAttach(
   HB_DOCK_HOST * pHost,
   HWND hWnd,
   HB_DOCK_MANAGER * pManager );

void hbDockHostDetach(
   HB_DOCK_HOST * pHost );

void hbDockHostResize(
   HB_DOCK_HOST * pHost );

void hbDockHostInvalidate(
   HB_DOCK_HOST * pHost );

#ifdef __cplusplus
}
#endif

#endif