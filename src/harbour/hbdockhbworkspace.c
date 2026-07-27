#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKSAVEWORKSPACE )
{
    hb_retl(

    hbDockSaveWorkspace(

        (void *) hb_parnl(1),

        hb_parc(2) ) );
}

HB_FUNC( HBDOCKLOADWORKSPACE )
{
    hb_retl(

    hbDockLoadWorkspace(

        (void *) hb_parnl(1),

        hb_parc(2) ) );
}
