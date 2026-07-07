#include <stdlib.h>
#include <string.h>

#include "hbdockpanel.h"
#include "hbdocklayout.h"
#include "hbdockdocksite.h"
#include "hbdockpaneloptions.h"

HB_DOCK_PANEL * hbDockPanelNew( void )
{
    HB_DOCK_PANEL * pPanel;

    pPanel = ( HB_DOCK_PANEL * ) calloc(
        1,
        sizeof( HB_DOCK_PANEL ) );

    if( pPanel == NULL )
        return NULL;

    pPanel->DockSide  = HB_DOCK_LEFT;
    pPanel->DockSite  = HB_DOCKSITE_NONE;
    pPanel->Visible   = 1;
    pPanel->Enabled   = 1;
    pPanel->MinWidth  = 120;
    pPanel->MinHeight = 120;

    pPanel->PreferredSize = 200;

    pPanel->BkColor   = GetSysColor( COLOR_BTNFACE );
    pPanel->TextColor = GetSysColor( COLOR_BTNTEXT );

    pPanel->Options =
        HB_DOCK_OPTION_CLOSEBUTTON |
        HB_DOCK_OPTION_PINBUTTON   |
        HB_DOCK_OPTION_FLOATABLE   |
        HB_DOCK_OPTION_DOCKABLE    |
        HB_DOCK_OPTION_VISIBLE;

    SetRect(
        &pPanel->Rect,
        0,
        0,
        pPanel->MinWidth,
        pPanel->MinHeight );

    pPanel->Name[ 0 ]    = '\0';
    pPanel->Caption[ 0 ] = '\0';
    pPanel->Hint[ 0 ]    = '\0';

    pPanel->Cargo     = NULL;
    pPanel->UserData  = NULL;
    pPanel->Next      = NULL;

    return pPanel;
}

void hbDockPanelDelete(
    HB_DOCK_PANEL * pPanel )
{
    if( pPanel != NULL )
        free( pPanel );
}