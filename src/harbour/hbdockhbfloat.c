#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKFLOAT )
{
    hb_retl(

    hbDockFloatPanel(

        (void *) hb_parnl(1),

        hb_parc(2) ) );
}