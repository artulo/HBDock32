#include <windows.h>

#include "hbdockutil.h"

void hbDockCopyRect(
   RECT * pDst,
   const RECT * pSrc )
{
   if( pDst == NULL || pSrc == NULL )
      return;

   *pDst = *pSrc;
}

int hbDockRectWidth(
   const RECT * pRect )
{
   if( pRect == NULL )
      return 0;

   return pRect->right - pRect->left;
}

int hbDockRectHeight(
   const RECT * pRect )
{
   if( pRect == NULL )
      return 0;

   return pRect->bottom - pRect->top;
}