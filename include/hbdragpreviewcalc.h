#ifndef HBDRAGPREVIEWCALC_H
#define HBDRAGPREVIEWCALC_H

#include <windows.h>

#include "hbdockdiamond.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDragPreviewCalcRect(
      const RECT * pHost,
      HB_DOCK_DIAMOND_PART Part,
      RECT * pPreview );

#ifdef __cplusplus
}
#endif

#endif