#include "hbdocktabtransfer.h"
#include "hbdocktabadd.h"
#include "hbdocktabremove.h"

BOOL hbDockTabTransfer(
      HB_DOCK_TAB_GROUP * pSource,
      UINT SourceIndex,
      HB_DOCK_TAB_GROUP * pTarget )
{
   HB_DOCK_TAB Tab;

   if( SourceIndex >= pSource->Count )
      return FALSE;

   Tab =
      pSource->Tabs[
         SourceIndex ];

   if( !hbDockTabAdd(
         pTarget,
         Tab.hDock,
         Tab.Caption ) )
      return FALSE;

   hbDockTabRemove(
      pSource,
      SourceIndex );

   return TRUE;
}