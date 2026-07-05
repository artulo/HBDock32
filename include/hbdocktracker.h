#ifndef HBDOCKTRACKER_H
#define HBDOCKTRACKER_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_TRACKER
{
   RECT Frame;
   int  Visible;

} HB_DOCK_TRACKER;

void hbDockTrackerInit(
   HB_DOCK_TRACKER * pTracker );

void hbDockTrackerShow(
   HDC hDC,
   HB_DOCK_TRACKER * pTracker,
   const RECT * pRect );

void hbDockTrackerHide(
   HDC hDC,
   HB_DOCK_TRACKER * pTracker );

#ifdef __cplusplus
}
#endif

#endif