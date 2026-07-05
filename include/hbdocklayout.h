#ifndef HBDOCKLAYOUT_H
#define HBDOCKLAYOUT_H

#include "hbdockmanager.h"

#define HB_DOCK_LEFT      0
#define HB_DOCK_RIGHT     1
#define HB_DOCK_TOP       2
#define HB_DOCK_BOTTOM    3
#define HB_DOCK_FILL      4
#define HB_DOCK_FLOATING  5

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPerformLayout(
    HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif