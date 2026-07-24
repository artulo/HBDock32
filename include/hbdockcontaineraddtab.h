#ifndef HBDOCKCONTAINERADDTAB_H
#define HBDOCKCONTAINERADDTAB_H

#include "hbdockcontainer.h"
#include "hbdockpanel.h"


#ifdef __cplusplus
extern "C" {
#endif


BOOL hbDockContainerAddTab(
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_PANEL * pPanel );


BOOL hbDockContainerRemoveTab(
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_PANEL * pPanel );


#ifdef __cplusplus
}
#endif

#endif