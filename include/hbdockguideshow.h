#ifndef HBDOCKGUIDESHOW_H
#define HBDOCKGUIDESHOW_H

#include "hbdockguide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockGuideShow(
   HB_DOCK_GUIDE * pGuide );

void hbDockGuideHide(
   HB_DOCK_GUIDE * pGuide );

BOOL hbDockGuideIsVisible(
   const HB_DOCK_GUIDE * pGuide );

#ifdef __cplusplus
}
#endif

#endif