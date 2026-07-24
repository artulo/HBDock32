#ifndef HBDOCKLAYOUTLOAD_H
#define HBDOCKLAYOUTLOAD_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockLayoutLoad(
   HB_DOCK_LAYOUT_TREE * pTree,
   LPCTSTR pszFileName );

#ifdef __cplusplus
}
#endif

#endif