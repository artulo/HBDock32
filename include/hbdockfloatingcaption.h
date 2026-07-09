#ifndef HBDOCKFLOATINGCAPTION_H
#define HBDOCKFLOATINGCAPTION_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingSetCaption(
   HB_DOCK_FLOATING_FRAME * pFrame,
   const char * pszCaption );

int hbDockFloatingGetCaption(
   const HB_DOCK_FLOATING_FRAME * pFrame,
   char * pszBuffer,
   int nBuffer );

#ifdef __cplusplus
}
#endif

#endif