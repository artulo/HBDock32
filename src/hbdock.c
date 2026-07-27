/*
 * ---------------------------------------------------------------------------
 * HBDock32
 *
 * Library Core
 *
 * ---------------------------------------------------------------------------
 */

#include "hbdock.h"

static HB_DOCK_BOOL s_bInitialized = HB_DOCK_FALSE;

HB_DOCK_BOOL hbDockInitialize( void )
{
    if( s_bInitialized )
        return HB_DOCK_TRUE;

    s_bInitialized = HB_DOCK_TRUE;

    return HB_DOCK_TRUE;
}

void hbDockExit( void )
{
    s_bInitialized = HB_DOCK_FALSE;
}

HB_DOCK_DWORD hbDockVersion( void )
{
    return
        ((HB_DOCK_DWORD) HBDOCK_VERSION_MAJOR << 24) |
        ((HB_DOCK_DWORD) HBDOCK_VERSION_MINOR << 16) |
        ((HB_DOCK_DWORD) HBDOCK_VERSION_BUILD);
}

const char * hbDockVersionString( void )
{
    return "0.1.0";
}