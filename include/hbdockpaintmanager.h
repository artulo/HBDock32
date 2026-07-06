#ifndef HBDOCKPAINTMANAGER_H
#define HBDOCKPAINTMANAGER_H

#include <windows.h>

#include "hbdocktheme.h"
#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_PAINT_MANAGER
{
   HB_DOCK_THEME Theme;

} HB_DOCK_PAINT_MANAGER;

void hbDockPaintManagerInit(
   HB_DOCK_PAINT_MANAGER * pPaint );

void hbDockPaintManagerDraw(
   HDC hDC,
   HB_DOCK_PAINT_MANAGER * pPaint,
   HB_DOCK_NODE * pRoot );

#ifdef __cplusplus
}
#endif

#endif