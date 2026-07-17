#ifndef HBDOCKPERSISTBIN_H
#define HBDOCKPERSISTBIN_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockSaveBinary(
    const HB_DOCK_LAYOUT_TREE * pTree,
    LPCTSTR pszFile );

BOOL hbDockLoadBinary(
    HB_DOCK_LAYOUT_TREE * pTree,
    LPCTSTR pszFile );

#ifdef __cplusplus
}
#endif

#endif
