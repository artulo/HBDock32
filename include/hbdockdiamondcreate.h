#ifndef HBDOCKDIAMONDCREATE_H
#define HBDOCKDIAMONDCREATE_H

#include "hbdockdiamond.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockDiamondCreate(
    HB_DOCK_DIAMOND * pDiamond,
    HWND hParent );

void hbDockDiamondDestroy(
    HB_DOCK_DIAMOND * pDiamond );
	

#ifdef __cplusplus
}
#endif

#endif