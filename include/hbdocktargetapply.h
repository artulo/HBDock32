#ifndef HBDOCKTARGETAPPLY_H
#define HBDOCKTARGETAPPLY_H

#include "hbdocktargetresolver.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockApplyResolvedTarget(
      HB_DOCK_TARGET_INFO * pInfo,
      HWND hDockWindow );

#ifdef __cplusplus
}
#endif

#endif