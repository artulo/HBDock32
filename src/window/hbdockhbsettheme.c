#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKSETTHEME )
{
    hb_retl(

    hbDockSetTheme(

        (void *) hb_parnl(1),

        hb_parni(2) ) );
}
