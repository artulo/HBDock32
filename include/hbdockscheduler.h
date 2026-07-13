#ifndef HBDOCKSCHEDULER_H
#define HBDOCKSCHEDULER_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    BOOL LayoutDirty;
    BOOL PaintDirty;
    BOOL TreeDirty;
    BOOL TabsDirty;
    BOOL FloatingDirty;
    BOOL AutoHideDirty;
    BOOL GuidesDirty;
    BOOL PersistDirty;
    BOOL ThemeDirty;

    UINT UpdateFlags;

} HB_DOCK_SCHEDULER;

#ifdef __cplusplus
}
#endif

#endif