#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKCREATEMANAGER )
{
    HWND hWnd =
        (HWND)
        hb_parnl(1);

    hb_retnl(
        (LONG_PTR)
        hbDockCreateManager(
            hWnd ) );
}

HB_FUNC( HBDOCKDESTROYMANAGER )
{
    hbDockDestroyManager(
        (void *)
        hb_parnl(1) );
}