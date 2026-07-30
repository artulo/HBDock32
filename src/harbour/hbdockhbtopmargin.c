#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKSETTOPMARGIN )
{
    hbDockSetTopMargin(

        (void *) hb_parnl(1),

        hb_parni(2) );
}
