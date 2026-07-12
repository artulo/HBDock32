#ifndef HBDOCKGUIDEHIT_H
#define HBDOCKGUIDEHIT_H

#include "hbdockguidemanager.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_GUIDE *
hbDockGuideManagerHitTest(
   HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif