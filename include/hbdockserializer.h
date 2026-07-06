#ifndef HBDOCKSERIALIZER_H
#define HBDOCKSERIALIZER_H

#include <stdio.h>

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockTreeSave(
   FILE * fp,
   HB_DOCK_NODE * pRoot );

HB_DOCK_NODE * hbDockTreeLoad(
   FILE * fp );

#ifdef __cplusplus
}
#endif

#endif