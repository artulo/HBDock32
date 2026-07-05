#include "hbdockevent.h"

static HB_DOCK_EVENT_PROC s_pEventProc = NULL;

void hbDockSetEventProc(
   HB_DOCK_EVENT_PROC pProc )
{
   s_pEventProc = pProc;
}

HB_DOCK_EVENT_PROC hbDockGetEventProc( void )
{
   return s_pEventProc;
}

void hbDockSendEvent(
   HWND hWnd,
   HB_DOCK_EVENT Event,
   void * pData )
{
   if( s_pEventProc != NULL )
      s_pEventProc(
         hWnd,
         Event,
         pData );
}