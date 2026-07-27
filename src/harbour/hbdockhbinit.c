#include "hbapi.h"

#include "hbdock.h"

HB_FUNC( HBDOCKINITIALIZE )
{
    hb_retl(
        hbDockInitialize() );
}

HB_FUNC( HBDOCKFINALIZE )
{
    hbDockExit();
}