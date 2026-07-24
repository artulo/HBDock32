#ifndef HBDOCKLAYOUTRECALC_H
#define HBDOCKLAYOUTRECALC_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockLayoutRecalc(
   HB_DOCK_LAYOUT_TREE * pTree,
   const RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif