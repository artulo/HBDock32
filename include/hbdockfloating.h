#ifndef HBDOCKFLOATING_H
#define HBDOCKFLOATING_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_FLOATING
{
   HWND hWnd;

   HB_DOCK_PANEL * Panel;

   RECT RestoreRect;

   int Active;

} HB_DOCK_FLOATING;

BOOL hbDockFloatingCreate(
   HB_DOCK_FLOATING * pFloating,
   HINSTANCE hInstance,
   HB_DOCK_PANEL * pPanel );

void hbDockFloatingDestroy(
   HB_DOCK_FLOATING * pFloating );

void hbDockFloatingShow(
   HB_DOCK_FLOATING * pFloating,
   int Show );

void hbDockFloatingMove(
   HB_DOCK_FLOATING * pFloating,
   const RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif