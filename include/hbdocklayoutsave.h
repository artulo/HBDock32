#ifndef HBDOCKLAYOUTSAVE_H
#define HBDOCKLAYOUTSAVE_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockLayoutSave(
   const HB_DOCK_LAYOUT_TREE * pTree,
   LPCTSTR pszFileName );

#ifdef __cplusplus
}
#endif

#endif