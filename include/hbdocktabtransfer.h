#ifndef HBDOCKTABTRANSFER_H
#define HBDOCKTABTRANSFER_H

#include "hbdocktabgroup.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockTabTransfer(
      HB_DOCK_TAB_GROUP * pSource,
      UINT SourceIndex,
      HB_DOCK_TAB_GROUP * pTarget );

#ifdef __cplusplus
}
#endif

#endif