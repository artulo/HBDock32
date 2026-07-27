#ifndef HBDOCKPERSISTCONTAINER_H
#define HBDOCKPERSISTCONTAINER_H

#include <stdio.h>

#include "hbdockcontainer.h"
#include "hbdocktabgroup.h"
#include "hbdockpanelregistry.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockSaveContainer(
      FILE * fp,
      const HB_DOCK_CONTAINER * pContainer );

BOOL hbDockLoadContainer(
      FILE * fp,
      HB_DOCK_CONTAINER ** ppContainer,
      HB_DOCK_PANEL_REGISTRY * pRegistry );

#ifdef __cplusplus
}
#endif

#endif