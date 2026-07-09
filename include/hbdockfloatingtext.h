#ifndef HBDOCKFLOATINGTEXT_H
#define HBDOCKFLOATINGTEXT_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockFloatingGetTextLength(
   HB_DOCK_FLOATING_FRAME * pFrame );

void hbDockFloatingGetText(
   HB_DOCK_FLOATING_FRAME * pFrame,
   char * pszText,
   int nSize );

#ifdef __cplusplus
}
#endif

#endif