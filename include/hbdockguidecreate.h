#ifndef HBDOCKGUIDECREATE_H
#define HBDOCKGUIDECREATE_H

#include "hbdockguide.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockGuideCreate(
   HB_DOCK_GUIDE * pGuide,
   HWND hParent,
   HB_DOCK_GUIDE_TYPE Type );

void hbDockGuideDestroy(
   HB_DOCK_GUIDE * pGuide );

#ifdef __cplusplus
}
#endif

#endif