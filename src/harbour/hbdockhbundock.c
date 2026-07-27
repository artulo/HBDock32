#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKUNDOCKPANEL )
{
    hb_retl(

    hbDockUndockPanel(

        (void *) hb_parnl(1),

        hb_parc(2) ) );
}
