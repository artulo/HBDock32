#include <windows.h>

#include "hbdockautohidesideposition.h"

void hbDockAutoHideCalcLeftRect(
   const RECT * pHost,
   RECT * pPane,
   int nWidth,
   int nSlide )
{
   pPane->left   = pHost->left - nWidth + nSlide;
   pPane->right  = pPane->left + nWidth;
   pPane->top    = pHost->top;
   pPane->bottom = pHost->bottom;
}

void hbDockAutoHideCalcRightRect(
   const RECT * pHost,
   RECT * pPane,
   int nWidth,
   int nSlide )
{
   pPane->left   = pHost->right - nSlide;
   pPane->right  = pPane->left + nWidth;
   pPane->top    = pHost->top;
   pPane->bottom = pHost->bottom;
}

void hbDockAutoHideCalcTopRect(
   const RECT * pHost,
   RECT * pPane,
   int nHeight,
   int nSlide )
{
   pPane->top    = pHost->top - nHeight + nSlide;
   pPane->bottom = pPane->top + nHeight;
   pPane->left   = pHost->left;
   pPane->right  = pHost->right;
}

void hbDockAutoHideCalcBottomRect(
   const RECT * pHost,
   RECT * pPane,
   int nHeight,
   int nSlide )
{
   pPane->top    = pHost->bottom - nSlide;
   pPane->bottom = pPane->top + nHeight;
   pPane->left   = pHost->left;
   pPane->right  = pHost->right;
}