#ifndef HBDOCKTARGETRESOLVER_H
#define HBDOCKTARGETRESOLVER_H

#include <windows.h>

#include "hbdockdiamond.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
   HB_DOCK_TARGET_NONE = 0,
   HB_DOCK_TARGET_LEFT,
   HB_DOCK_TARGET_RIGHT,
   HB_DOCK_TARGET_TOP,
   HB_DOCK_TARGET_BOTTOM,
   HB_DOCK_TARGET_CENTER,
   HB_DOCK_TARGET_TAB

} HB_DOCK_TARGET;

typedef struct
{
   HWND hTarget;

   HB_DOCK_TARGET Target;

   RECT PreviewRect;

} HB_DOCK_TARGET_INFO;

BOOL hbDockResolveTarget(
      HWND hHost,
      POINT pt,
      HB_DOCK_TARGET_INFO * pInfo );

#ifdef __cplusplus
}
#endif

#endif