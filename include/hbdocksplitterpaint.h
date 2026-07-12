#ifndef HBDOCKSPLITTERPAINT_H
#define HBDOCKSPLITTERPAINT_H

#include <windows.h>

#include "hbdocksplitter.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockSplitterPaint(
      const HB_DOCK_SPLITTER * pSplitter,
      HDC hDC );

#ifdef __cplusplus
}
#endif

#endif