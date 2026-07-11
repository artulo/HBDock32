#ifndef HBDOCKGUIDE_H
#define HBDOCKGUIDE_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
   HB_DOCK_GUIDE_NONE = 0,
   HB_DOCK_GUIDE_LEFT,
   HB_DOCK_GUIDE_RIGHT,
   HB_DOCK_GUIDE_TOP,
   HB_DOCK_GUIDE_BOTTOM,
   HB_DOCK_GUIDE_CENTER

} HB_DOCK_GUIDE_TYPE;

typedef struct _HB_DOCK_GUIDE
{
   HWND hWnd;
   RECT Rect;
   HB_DOCK_GUIDE_TYPE Type;
   BOOL Visible;
   BOOL Hot;
   BOOL Enabled;

} HB_DOCK_GUIDE;

#ifdef __cplusplus
}
#endif

#endif