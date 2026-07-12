#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKINITIALIZE )
{
    hb_retl(
        hbDockInitialize() );
}

HB_FUNC( HBDOCKFINALIZE )
{
    hbDockFinalize();
}