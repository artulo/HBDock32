#include <windows.h>

#include "hbdockmanagerdrag.h"

void hbDockManagerBeginDrag(
      HB_DOCK_MANAGER * pManager,
      HWND hWnd )
{
    pManager->Dragging = TRUE;

    pManager->hCapturedWindow = hWnd;

    SetCapture(
        hWnd );

    hbDockDiamondShow(
        &pManager->Diamond );
}

void hbDockManagerEndDrag(
      HB_DOCK_MANAGER * pManager )
{
    pManager->Dragging = FALSE;

    ReleaseCapture();

    hbDockDiamondHide(
        &pManager->Diamond );

    hbDockPreviewHide(
        &pManager->Preview );
}