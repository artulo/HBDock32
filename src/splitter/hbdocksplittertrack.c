#include "hbdocksplittertrack.h"

void hbDockSplitterBeginTrack(
      HB_DOCK_SPLITTER * pSplitter )
{
   if( pSplitter )
      pSplitter->Tracking = TRUE;
}

void hbDockSplitterEndTrack(
      HB_DOCK_SPLITTER * pSplitter )
{
   if( pSplitter )
      pSplitter->Tracking = FALSE;
}