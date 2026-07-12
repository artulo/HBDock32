#ifndef HBDOCKTABMOUSE_H
#define HBDOCKTABMOUSE_H

#include "hbdocktabcontrol.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockTabMouseDown(
    HB_DOCK_TAB_CONTROL * pControl,
    POINT pt );

void hbDockTabMouseMove(
    HB_DOCK_TAB_CONTROL * pControl,
    POINT pt );

void hbDockTabMouseUp(
    HB_DOCK_TAB_CONTROL * pControl,
    POINT pt );

#ifdef __cplusplus
}
#endif

#endif