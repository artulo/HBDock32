#ifndef HBDOCKPERSISTCONTAINER_H
#define HBDOCKPERSISTCONTAINER_H

#include <stdio.h>

#include "hbdockcontainer.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockSaveContainer(
      FILE * fp,
      const HB_DOCK_CONTAINER * pContainer );

BOOL hbDockLoadContainer(
      FILE * fp,
      HB_DOCK_CONTAINER ** ppContainer );

#ifdef __cplusplus
}
#endif

#endif