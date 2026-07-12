#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKPANEL )
{
    hb_retl(

    hbDockDockPanel(

        (void *) hb_parnl(1),

        hb_parc(2),

        hb_parni(3) ) );
}