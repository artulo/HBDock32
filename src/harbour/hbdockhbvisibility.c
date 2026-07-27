#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKSHOWPANEL )
{
    hb_retl(

    hbDockShowPanel(

        (void *) hb_parnl(1),

        hb_parc(2) ) );
}

HB_FUNC( HBDOCKHIDEPANEL )
{
    hb_retl(

    hbDockHidePanel(

        (void *) hb_parnl(1),

        hb_parc(2) ) );
}
