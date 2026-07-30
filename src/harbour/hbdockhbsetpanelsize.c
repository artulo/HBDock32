#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKSETPANELSIZE )
{
    hb_retl(

    hbDockSetPanelSize(

        (void *) hb_parnl(1),

        hb_parc(2),

        hb_parni(3),

        hb_parni(4) ) );
}
