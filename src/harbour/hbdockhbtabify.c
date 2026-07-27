#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKTABIFYPANEL )
{
    hb_retl(

    hbDockTabifyPanel(

        (void *) hb_parnl(1),

        hb_parc(2),

        hb_parc(3) ) );
}
