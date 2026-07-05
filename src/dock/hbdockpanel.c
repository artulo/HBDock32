#include <stdlib.h>
#include <string.h>

#include "hbdockpanel.h"
#include "hbdocklayout.h"

HB_DOCK_PANEL * hbDockPanelNew( void )
{
    HB_DOCK_PANEL * pPanel;

    pPanel = ( HB_DOCK_PANEL * ) calloc(
        1,
        sizeof( HB_DOCK_PANEL ) );

    if( pPanel == NULL )
        return NULL;

    pPanel->DockSide  = HB_DOCK_LEFT;
    pPanel->Visible   = 1;
    pPanel->MinWidth  = 120;
    pPanel->MinHeight = 120;

    SetRect(
        &pPanel->Rect,
        0,
        0,
        pPanel->MinWidth,
        pPanel->MinHeight );

    pPanel->Name[ 0 ] = '\0';
    pPanel->Cargo     = NULL;
    pPanel->Next      = NULL;

    return pPanel;
}

void hbDockPanelDelete(
    HB_DOCK_PANEL * pPanel )
{
    if( pPanel != NULL )
        free( pPanel );
}

void hbDockPanelSetName(
    HB_DOCK_PANEL * pPanel,
    const char * pszName )
{
    if( pPanel == NULL )
        return;

    if( pszName == NULL )
    {
        pPanel->Name[ 0 ] = '\0';
        return;
    }

    strncpy(
        pPanel->Name,
        pszName,
        sizeof( pPanel->Name ) - 1 );

    pPanel->Name[ sizeof( pPanel->Name ) - 1 ] = '\0';
}