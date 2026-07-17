#include "hbdockcontainerfactory.h"

#include "hbapi.h"

HB_DOCK_CONTAINER *
hbDockContainerNew(
    HWND hParent )
{
    HB_DOCK_CONTAINER * pContainer;

    pContainer =
        ( HB_DOCK_CONTAINER * )
        hb_xgrab( sizeof( HB_DOCK_CONTAINER ) );

    if( pContainer == NULL )
        return NULL;

    if( !hbDockContainerCreate(
            pContainer,
            hParent ) )
    {
        hb_xfree( pContainer );
        return NULL;
    }

    return pContainer;
}

void
hbDockContainerDelete(
    HB_DOCK_CONTAINER * pContainer )
{
    if( pContainer == NULL )
        return;

    hbDockContainerDestroy(
        pContainer );

    hb_xfree(
        pContainer );
}