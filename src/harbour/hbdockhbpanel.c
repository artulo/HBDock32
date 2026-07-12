#include "hbapi.h"

#include "hbdockapi.h"

HB_FUNC( HBDOCKREGISTERPANEL )
{
    hb_retl(

        hbDockRegisterPanel(

        (void *) hb_parnl(1),

        (HWND) hb_parnl(2),

        hb_parc(3),

        hb_parc(4) ) );
}