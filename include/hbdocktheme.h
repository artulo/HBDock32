#ifndef HBDOCKTHEME_H
#define HBDOCKTHEME_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_THEME
{
   COLORREF Background;
   COLORREF Border;
   COLORREF Caption;
   COLORREF CaptionText;
   COLORREF TabActive;
   COLORREF TabInactive;
   COLORREF Guide;

} HB_DOCK_THEME;

void hbDockThemeDefault(
   HB_DOCK_THEME * pTheme );

#ifdef __cplusplus
}
#endif

#endif