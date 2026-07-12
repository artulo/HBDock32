#include <windows.h>

#include "hbdockcontainerlayout.h"

static void hbLayoutContainer(
      HB_DOCK_CONTAINER * pContainer,
      RECT rc )
{
   if(pContainer==NULL)
      return;

   pContainer->Rect = rc;

   switch(pContainer->Type)
   {
      case HB_CONTAINER_TABS:

         if(pContainer->TabGroup.hActiveDock)
         {
            MoveWindow(
               pContainer->TabGroup.hActiveDock,
               rc.left,
               rc.top+24,
               rc.right-rc.left,
               rc.bottom-rc.top-24,
               TRUE);
         }

         break;

      case HB_CONTAINER_SPLIT:

         /* siguiente etapa */

         break;

      default:

         break;
   }
}

void hbDockContainerLayout(
      HB_DOCK_CONTAINER * pContainer,
      RECT rc )
{
   hbLayoutContainer(
      pContainer,
      rc);
}