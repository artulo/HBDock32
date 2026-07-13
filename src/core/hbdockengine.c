#include "hbdockengine.h"

#include "hbdocklayoutoptimizer.h"
#include "hbdocklayoutvalidate.h"
#include "hbdockeventdispatcher.h"
#include "hbdockcontainerlayout.h"
#include "hbdockpreviewoverlay.h"
#include "hbdockguidemanager.h"

BOOL hbDockEngineInitialize(
        HB_DOCK_MANAGER * pManager )
{
    hbDockEventDispatcherInit(
        pManager );

    return TRUE;
}
void hbDockEngineUpdateLayout(
        HB_DOCK_MANAGER * pManager )
{
    RECT rc;

    GetClientRect(
        pManager->hMainWnd,
        &rc );

    hbDockLayoutOptimize(
        &pManager->LayoutTree );

    hbDockLayoutValidate(
        &pManager->LayoutTree );

    hbDockContainerLayout(
        pManager->LayoutTree.Root->pContainer,
        rc );
}
BOOL hbDockEngineProcessMessage(
        HB_DOCK_MANAGER * pManager,
        HWND hWnd,
        UINT msg,
        WPARAM wp,
        LPARAM lp )
{
    switch(msg)
    {

        case WM_SIZE:

            hbDockEngineUpdateLayout(
                pManager );

            return TRUE;

        case WM_PAINT:

            hbDockEngineRender(
                pManager );

            return TRUE;
		
		case WM_TIMER:

			hbDockKernelProcess(
				pManager );

			break;

        case WM_MOUSEMOVE:

            /*
               Drag Manager

               Dock Guides

               Splitters

               Preview Overlay

            */

            return TRUE;

    }

    return FALSE;
}
void hbDockEngineRender(
        HB_DOCK_MANAGER * pManager )
{
    hbDockGuideManagerPaint(

        &pManager->GuideManager );

    hbDockPreviewPaint(

        &pManager->Preview );

    /*
       Floating

       AutoHide

       Tabs

       Splitters

    */
}