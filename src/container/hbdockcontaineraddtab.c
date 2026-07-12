#include "hbdockcontaineraddtab.h"

#include "hbdocktabadd.h"

BOOL hbDockContainerAddTab(
      HB_DOCK_CONTAINER * pContainer,
      HWND hDock,
      LPCTSTR Caption )
{
   pContainer->Type =
      HB_CONTAINER_TABS;

   return hbDockTabAdd(
      &pContainer->TabGroup,
      hDock,
      Caption );
}