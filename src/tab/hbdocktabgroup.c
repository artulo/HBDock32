#include <stdlib.h>
#include <string.h>

#include "hbdocktabgroup.h"

BOOL hbDockTabGroupInit(
      HB_DOCK_TAB_GROUP * pGroup )
{
   memset(
      pGroup,
      0,
      sizeof( *pGroup ) );

   return TRUE;
}

void hbDockTabGroupDone(
      HB_DOCK_TAB_GROUP * pGroup )
{
   free(
      pGroup->Tabs );

   memset(
      pGroup,
      0,
      sizeof( *pGroup ) );
}