#include <windows.h>

#include "hbdocklayout.h"
#include "hbdockmanager.h"
#include "hbdockpanel.h"
#include "hbdockmanagerlayout.h"

static void hbDockLayoutLeft(
    HB_DOCK_MANAGER * pManager,
    HB_DOCK_PANEL * pPanel,
    RECT * pClient )
{
    int cx;
	(void) pManager;
    cx = pPanel->PreferredSize;

    pPanel->Rect.left   = pClient->left;
    pPanel->Rect.top    = pClient->top;
    pPanel->Rect.right  = pClient->left + cx;
    pPanel->Rect.bottom = pClient->bottom;

    pClient->left += cx;
}

static void hbDockLayoutRight(
    HB_DOCK_MANAGER * pManager,
    HB_DOCK_PANEL * pPanel,
    RECT * pClient )
{
    int cx;
	(void) pManager;
    cx = pPanel->PreferredSize;

    pPanel->Rect.left   = pClient->right - cx;
    pPanel->Rect.top    = pClient->top;
    pPanel->Rect.right  = pClient->right;
    pPanel->Rect.bottom = pClient->bottom;

    pClient->right -= cx;
}

static void hbDockLayoutTop(
    HB_DOCK_MANAGER * pManager,
    HB_DOCK_PANEL * pPanel,
    RECT * pClient )
{
    int cy;
	(void) pManager;
    cy = pPanel->PreferredSize;

    pPanel->Rect.left   = pClient->left;
    pPanel->Rect.top    = pClient->top;
    pPanel->Rect.right  = pClient->right;
    pPanel->Rect.bottom = pClient->top + cy;

    pClient->top += cy;
}

static void hbDockLayoutBottom(
    HB_DOCK_MANAGER * pManager,
    HB_DOCK_PANEL * pPanel,
    RECT * pClient )
{
    int cy;
	(void) pManager;
    cy = pPanel->PreferredSize;

    pPanel->Rect.left   = pClient->left;
    pPanel->Rect.top    = pClient->bottom - cy;
    pPanel->Rect.right  = pClient->right;
    pPanel->Rect.bottom = pClient->bottom;

    pClient->bottom -= cy;
}

static void hbDockLayoutFill(
    HB_DOCK_MANAGER * pManager,
    HB_DOCK_PANEL * pPanel,
    RECT * pClient )
{
	(void) pManager;
    pPanel->Rect = *pClient;
}

void hbDockPerformLayout(
    HB_DOCK_MANAGER * pManager )
{
    RECT rc;
    HB_DOCK_PANEL * pPanel;

    if( pManager == NULL )
        return;

	GetClientRect(
		pManager->hMainWnd,
		&rc );

  //  pManager->ClientRect = rc;
/*
    pPanel = pManager->FirstPanel;

    while( pPanel != NULL )
    {
        if( pPanel->Visible )
        {
            switch( pPanel->DockSide )
            {
                case HB_DOCK_LEFT:
                    hbDockLayoutLeft(
                        pManager,
                        pPanel,
                        &rc );
                    break;

                case HB_DOCK_RIGHT:
                    hbDockLayoutRight(
                        pManager,
                        pPanel,
                        &rc );
                    break;

                case HB_DOCK_TOP:
                    hbDockLayoutTop(
                        pManager,
                        pPanel,
                        &rc );
                    break;

                case HB_DOCK_BOTTOM:
                    hbDockLayoutBottom(
                        pManager,
                        pPanel,
                        &rc );
                    break;

                case HB_DOCK_FILL:
                    hbDockLayoutFill(
                        pManager,
                        pPanel,
                        &rc );
                    break;
            }
        }

        pPanel = pPanel->Next;
    }
*/
    hbDockManagerUpdateLayout(
		pManager );
}