#ifndef HBDOCKFOCUS_H
#define HBDOCKFOCUS_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_FOCUS
{
   HB_DOCK_PANEL * Current;
   HB_DOCK_PANEL * Previous;

} HB_DOCK_FOCUS;

void hbDockFocusInit(
   HB_DOCK_FOCUS * pFocus );

void hbDockFocusSet(
   HB_DOCK_FOCUS * pFocus,
   HB_DOCK_PANEL * pPanel );

HB_DOCK_PANEL * hbDockFocusGet(
   HB_DOCK_FOCUS * pFocus );

#ifdef __cplusplus
}
#endif

#endif