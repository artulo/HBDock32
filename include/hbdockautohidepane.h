#ifndef HBDOCKAUTOHIDEPANE_H
#define HBDOCKAUTOHIDEPANE_H

#include <windows.h>

#include "hbdockpanel.h"


#ifdef __cplusplus
extern "C" {
#endif


typedef struct _HB_DOCK_AUTOHIDE_PANE
{
   HB_DOCK_PANEL * pPanel;


   int Side;


   BOOL Visible;


   RECT Rect;


} HB_DOCK_AUTOHIDE_PANE;



#ifdef __cplusplus
}
#endif


#endif