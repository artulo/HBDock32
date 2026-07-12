#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKAUTOHIDE )
{
    hb_retl(

    hbDockAutoHidePanel(

        (void *) hb_parnl(1),

        hb_parc(2) ) );
}