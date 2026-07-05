#include <stdlib.h>
#include <string.h>

#include "hbdockmanager.h"

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

    if( hWnd != NULL )
        GetClientRect(
            hWnd,
            &p->ClientRect );

    return p;
}

void hbDockManagerDelete(
    HB_DOCK_MANAGER * p )
{
    if( p != NULL )
        free( p );
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

void hbDockManagerLayout(
    HB_DOCK_MANAGER * pManager )
{
    HB_DOCK_PANEL * p;

    if( pManager == NULL )
        return;

    if( pManager->hParent != NULL )
        GetClientRect(
            pManager->hParent,
            &pManager->ClientRect );

    p = pManager->FirstPanel;

    while( p != NULL )
    {
        if( p->Visible && p->hWnd != NULL )
        {
            MoveWindow(
                p->hWnd,
                p->Rect.left,
                p->Rect.top,
                p->Rect.right - p->Rect.left,
                p->Rect.bottom - p->Rect.top,
                TRUE );
        }

        p = p->Next;
    }
}