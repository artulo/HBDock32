#ifndef HBDOCKCONTAINERFACTORY_H
#define HBDOCKCONTAINERFACTORY_H

#include <windows.h>

#include "hbdockcontainer.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_CONTAINER *
hbDockContainerNew(
    HWND hParent );

void
hbDockContainerDelete(
    HB_DOCK_CONTAINER * pContainer );

#ifdef __cplusplus
}
#endif

#endif