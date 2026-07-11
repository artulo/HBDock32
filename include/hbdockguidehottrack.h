#ifndef HBDOCKGUIDEHOTTRACK_H
#define HBDOCKGUIDEHOTTRACK_H

#include "hbdockguide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockGuideSetHot(
   HB_DOCK_GUIDE * pGuide,
   BOOL Hot );

BOOL hbDockGuideIsHot(
   const HB_DOCK_GUIDE * pGuide );

#ifdef __cplusplus
}
#endif

#endif