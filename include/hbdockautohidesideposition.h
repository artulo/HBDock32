#ifndef HBDOCKAUTOHIDESIDEPOSITION_H
#define HBDOCKAUTOHIDESIDEPOSITION_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideCalcLeftRect(
   const RECT * pHost,
   RECT * pPane,
   int nWidth,
   int nSlide );

void hbDockAutoHideCalcRightRect(
   const RECT * pHost,
   RECT * pPane,
   int nWidth,
   int nSlide );

void hbDockAutoHideCalcTopRect(
   const RECT * pHost,
   RECT * pPane,
   int nHeight,
   int nSlide );

void hbDockAutoHideCalcBottomRect(
   const RECT * pHost,
   RECT * pPane,
   int nHeight,
   int nSlide );

#ifdef __cplusplus
}
#endif

#endif