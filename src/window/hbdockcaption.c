#include <windows.h>

#include "hbdockcaption.h"

void hbDockCaptionInit(
   HB_DOCK_CAPTION * pCaption,
   HB_DOCK_PANEL * pPanel )
{
   ZeroMemory(
      pCaption,
      sizeof( HB_DOCK_CAPTION ) );

   pCaption->Panel = pPanel;
}

void hbDockCaptionLayout(
   HB_DOCK_CAPTION * pCaption,
   const RECT * pRect )
{
   pCaption->Rect = *pRect;

   SetRect(
      &pCaption->CloseRect,
      pRect->right - 20,
      pRect->top + 2,
      pRect->right - 2,
      pRect->top + 20 );

   SetRect(
      &pCaption->PinRect,
      pRect->right - 40,
      pRect->top + 2,
      pRect->right - 22,
      pRect->top + 20 );
}

void hbDockCaptionDraw(
   HDC hDC,
   HB_DOCK_CAPTION * pCaption )
{
   Rectangle(
      hDC,
      pCaption->Rect.left,
      pCaption->Rect.top,
      pCaption->Rect.right,
      pCaption->Rect.bottom );

   Rectangle(
      hDC,
      pCaption->CloseRect.left,
      pCaption->CloseRect.top,
      pCaption->CloseRect.right,
      pCaption->CloseRect.bottom );

   Rectangle(
      hDC,
      pCaption->PinRect.left,
      pCaption->PinRect.top,
      pCaption->PinRect.right,
      pCaption->PinRect.bottom );
}