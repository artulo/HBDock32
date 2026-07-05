#ifndef HBDOCKMESSAGE_H
#define HBDOCKMESSAGE_H

#include <windows.h>

#define HBDM_FIRST           ( WM_USER + 600 )

#define HBDM_DOCK            ( HBDM_FIRST + 1 )
#define HBDM_UNDOCK          ( HBDM_FIRST + 2 )
#define HBDM_LAYOUT          ( HBDM_FIRST + 3 )
#define HBDM_SHOWPANEL       ( HBDM_FIRST + 4 )
#define HBDM_HIDEPANEL       ( HBDM_FIRST + 5 )
#define HBDM_ACTIVATEPANEL   ( HBDM_FIRST + 6 )
#define HBDM_CLOSEPANEL      ( HBDM_FIRST + 7 )
#define HBDM_BEGIN_DRAG      ( HBDM_FIRST + 8 )
#define HBDM_END_DRAG        ( HBDM_FIRST + 9 )

#endif