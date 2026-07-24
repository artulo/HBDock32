#ifndef HBDOCKCONTAINERSPLIT_H
#define HBDOCKCONTAINERSPLIT_H

#include <windows.h>

#include "hbdockcontainer.h"


#ifdef __cplusplus
extern "C" {
#endif


BOOL hbDockContainerSplit(
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_CONTAINER * pNewContainer,
   int Orientation );


#ifdef __cplusplus
}
#endif


#endif