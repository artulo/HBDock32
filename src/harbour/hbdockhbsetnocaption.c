#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKSETNOCAPTION )
{
    hb_retl(

    hbDockSetPanelNoCaption(

        (void *) hb_parnl(1),

        hb_parc(2),

        hb_parl(3) ) );
}
