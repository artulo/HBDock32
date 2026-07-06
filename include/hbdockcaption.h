#ifndef HBDOCKCAPTION_H
#define HBDOCKCAPTION_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HBDOCK_CAPTION_HEIGHT 24

typedef struct _HB_DOCK_CAPTION
{
   HB_DOCK_PANEL * Panel;

   RECT Rect;

   RECT CloseRect;

   RECT PinRect;

} HB_DOCK_CAPTION;

void hbDockCaptionInit(
   HB_DOCK_CAPTION * pCaption,
   HB_DOCK_PANEL * pPanel );

void hbDockCaptionLayout(
   HB_DOCK_CAPTION * pCaption,
   const RECT * pRect );

void hbDockCaptionDraw(
   HDC hDC,
   HB_DOCK_CAPTION * pCaption );

#ifdef __cplusplus
}
#endif

#endif