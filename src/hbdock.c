/*
 * ---------------------------------------------------------------------------
 * HBDock32
 *
 * Library Core
 *
 * ---------------------------------------------------------------------------
 */

#include "hbdock.h"

static HB_BOOL s_bInitialized = HB_FALSE;

HB_BOOL hbDockInitialize( void )
{
    if( s_bInitialized )
        return HB_TRUE;

    s_bInitialized = HB_TRUE;

    return HB_TRUE;
}

void hbDockExit( void )
{
    s_bInitialized = HB_FALSE;
}

HB_DWORD hbDockVersion( void )
{
    return
        ((HB_DWORD) HBDOCK_VERSION_MAJOR << 24) |
        ((HB_DWORD) HBDOCK_VERSION_MINOR << 16) |
        ((HB_DWORD) HBDOCK_VERSION_BUILD);
}

const char * hbDockVersionString( void )
{
    return "0.1.0";
}