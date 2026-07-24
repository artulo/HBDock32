#include "hbdockengine.h"

#include "hbdocklayoutoptimizer.h"
#include "hbdocklayoutvalidate.h"
#include "hbdockeventdispatcher.h"
#include "hbdockcontainerlayout.h"
#include "hbdockpreviewoverlay.h"
#include "hbdockguidemanager.h"
#include "hbdockkernel.h"
#include "hbdockpreviewpaint.h"


static void hbDockEngineLayoutNode(
        HB_DOCK_LAYOUT_NODE * pNode,
        RECT rc )
{
    if( pNode == NULL )
        return;


    if( pNode->Type == HB_LAYOUT_LEAF )
    {
        if( pNode->pPanel != NULL )
        {
            hbDockContainerLayout(
                pNode->pPanel,
                rc );
        }

        return;
    }


    if( pNode->First != NULL )
    {
        hbDockEngineLayoutNode(
            pNode->First,
            rc );
    }


    if( pNode->Second != NULL )
    {
        hbDockEngineLayoutNode(
            pNode->Second,
            rc );
    }
}



BOOL hbDockEngineInitialize(
        HB_DOCK_MANAGER * pManager )
{
    if( pManager == NULL )
        return FALSE;


    hbDockEventDispatcherInit(
        pManager );

    return TRUE;
}



void hbDockEngineUpdateLayout(
        HB_DOCK_MANAGER * pManager )
{
    RECT rc;


    if( pManager == NULL )
        return;


    GetClientRect(
        pManager->hMainWnd,
        &rc );


    hbDockLayoutOptimize(
        &pManager->LayoutTree );


    hbDockLayoutValidate(
        &pManager->LayoutTree );


    hbDockEngineLayoutNode(
        pManager->LayoutTree.Root,
        rc );
}



BOOL hbDockEngineProcessMessage(
        HB_DOCK_MANAGER * pManager,
        HWND hWnd,
        UINT msg,
        WPARAM wp,
        LPARAM lp )
{
    (void)hWnd;
    (void)wp;
    (void)lp;


    if( pManager == NULL )
        return FALSE;


    switch( msg )
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

            return TRUE;


        case WM_MOUSEMOVE:

            return TRUE;

    }


    return FALSE;
}



void hbDockEngineRender(
        HB_DOCK_MANAGER * pManager )
{
    HDC hDC;


    if( pManager == NULL )
        return;


    hDC = GetDC(
        pManager->hMainWnd );


    if( hDC == NULL )
        return;


    hbDockGuideManagerPaint(
        &pManager->GuideManager );


    hbDockPreviewPaint(
        &pManager->Preview,
        hDC );


    ReleaseDC(
        pManager->hMainWnd,
        hDC );
}