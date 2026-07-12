#include <windows.h>

#include "hbdockdiamondshow.h"

void hbDockDiamondShow(
   HB_DOCK_DIAMOND * pDiamond )
{
   pDiamond->Visible = TRUE;

   ShowWindow(
      pDiamond->hWnd,
      SW_SHOWNA );
}

void hbDockDiamondHide(
   HB_DOCK_DIAMOND * pDiamond )
{
   pDiamond->Visible = FALSE;

   ShowWindow(
      pDiamond->hWnd,
      SW_HIDE );
}