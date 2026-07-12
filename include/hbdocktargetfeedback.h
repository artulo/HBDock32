#ifndef HBDOCKTARGETFEEDBACK_H
#define HBDOCKTARGETFEEDBACK_H

#include "hbdocktargetresolver.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockTargetSetActive(
      HB_DOCK_TARGET_INFO * pInfo );

void hbDockTargetClear(
      HB_DOCK_TARGET_INFO * pInfo );

#ifdef __cplusplus
}
#endif

#endif