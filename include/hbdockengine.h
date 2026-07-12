#ifndef HBDOCKENGINE_H
#define HBDOCKENGINE_H

#include "hbdockmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockEngineInitialize(
        HB_DOCK_MANAGER * pManager );

void hbDockEngineShutdown(
        HB_DOCK_MANAGER * pManager );

BOOL hbDockEngineProcessMessage(
        HB_DOCK_MANAGER * pManager,
        HWND hWnd,
        UINT message,
        WPARAM wParam,
        LPARAM lParam );

void hbDockEngineUpdateLayout(
        HB_DOCK_MANAGER * pManager );

void hbDockEngineRender(
        HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif