#include "hbdocklayoutsync.h"

#include "hbdocklayoutoptimizer.h"
#include "hbdocklayoutvalidate.h"
#include "hbdockengine.h"

BOOL hbDockLayoutSynchronize(
        HB_DOCK_MANAGER * pManager )
{
    if( pManager == NULL )
        return FALSE;

    hbDockLayoutOptimize(
        &pManager->LayoutTree );

    if( !hbDockLayoutValidate(
            &pManager->LayoutTree ) )
        return FALSE;

    hbDockEngineUpdateLayout(
        pManager );

    return TRUE;
}