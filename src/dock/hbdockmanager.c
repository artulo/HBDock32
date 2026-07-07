#include <stdlib.h>
#include <string.h>

#include "hbdockmanager.h"
#include "hbdockfloating.h"
#include "hbdockautohide.h"

HB_DOCK_MANAGER * hbDockManagerNew(
    HWND hWnd )
{
    HB_DOCK_MANAGER * p;

    p = (HB_DOCK_MANAGER *) calloc(
            1,
            sizeof( HB_DOCK_MANAGER ) );

    if( p == NULL )
        return NULL;

    p->hParent = hWnd;
    p->hWnd    = hWnd;

    if( hWnd != NULL )
        GetClientRect(
            hWnd,
            &p->ClientRect );

    hbDockLayoutEngineInit(
        &p->LayoutEngine );

    hbDockFocusInit(
        &p->Focus );

    hbDockDragTrackerInit(
        &p->DragTracker );

    hbDockArrayInit(
        &p->FloatWindows );

    hbDockArrayInit(
        &p->AutoHidePanels );

    return p;
}

void hbDockManagerDelete(
    HB_DOCK_MANAGER * p )
{
    int i;

    if( p == NULL )
        return;

    for( i = 0; i < p->FloatWindows.Count; ++i )
    {
        HB_DOCK_FLOATING * pFloating =
            ( HB_DOCK_FLOATING * ) hbDockArrayGet(
                &p->FloatWindows,
                i );

        if( pFloating != NULL )
        {
            hbDockFloatingDestroy(
                pFloating );

            free( pFloating );
        }
    }

    for( i = 0; i < p->AutoHidePanels.Count; ++i )
    {
        void * pAutoHide = hbDockArrayGet(
            &p->AutoHidePanels,
            i );

        if( pAutoHide != NULL )
            free( pAutoHide );
    }

    hbDockArrayRelease(
        &p->FloatWindows );

    hbDockArrayRelease(
        &p->AutoHidePanels );

    if( p->LayoutEngine.Root != NULL )
        hbDockNodeDelete(
            p->LayoutEngine.Root );

    free( p );
}

void hbDockManagerSetInstance(
    HB_DOCK_MANAGER * pManager,
    HINSTANCE hInstance )
{
    if( pManager == NULL )
        return;

    pManager->hInstance = hInstance;
}

void hbDockManagerAddPanel(
    HB_DOCK_MANAGER * pManager,
    HB_DOCK_PANEL * pPanel )
{
    if( pManager == NULL || pPanel == NULL )
        return;

    pPanel->Next = NULL;

    if( pManager->FirstPanel == NULL )
    {
        pManager->FirstPanel = pPanel;
        pManager->LastPanel  = pPanel;
    }
    else
    {
        pManager->LastPanel->Next = pPanel;
        pManager->LastPanel = pPanel;
    }

    pManager->PanelCount++;
}

HB_DOCK_PANEL * hbDockManagerFindPanel(
    HB_DOCK_MANAGER * pManager,
    const char * pszName )
{
    HB_DOCK_PANEL * p;

    if( pManager == NULL || pszName == NULL )
        return NULL;

    p = pManager->FirstPanel;

    while( p != NULL )
    {
        if( strcmp( p->Name, pszName ) == 0 )
            return p;

        p = p->Next;
    }

    return NULL;
}

void hbDockManagerRemovePanel(
    HB_DOCK_MANAGER * pManager,
    HB_DOCK_PANEL * pPanel )
{
    HB_DOCK_PANEL * pPrev;
    HB_DOCK_PANEL * p;

    if( pManager == NULL || pPanel == NULL )
        return;

    pPrev = NULL;
    p = pManager->FirstPanel;

    while( p != NULL )
    {
        if( p == pPanel )
        {
            if( pPrev == NULL )
                pManager->FirstPanel = p->Next;
            else
                pPrev->Next = p->Next;

            if( pManager->LastPanel == p )
                pManager->LastPanel = pPrev;

            p->Next = NULL;

            if( pManager->PanelCount > 0 )
                pManager->PanelCount--;

            return;
        }

        pPrev = p;
        p = p->Next;
    }
}
