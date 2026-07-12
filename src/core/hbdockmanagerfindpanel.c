#include "hbdockmanagerfindpanel.h"

#include "hbdockpanelfind.h"

HB_DOCK_PANEL *

hbDockManagerFindPanel(

        HB_DOCK_MANAGER * pManager,

        LPCTSTR pszName )
{
    return hbDockPanelFindName(

        &pManager->Registry,

        pszName );
}