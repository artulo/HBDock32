#include <windows.h>

#include "hbdockguidebuffer.h"

HDC hbDockGuideBeginPaintBuffer(
   HDC hDC,
   RECT * pRect,
   HBITMAP * phBitmap )
{
   HDC hMem;

   hMem =
      CreateCompatibleDC(
         hDC );

   *phBitmap =
      CreateCompatibleBitmap(
         hDC,
         pRect->right - pRect->left,
         pRect->bottom - pRect->top );

   SelectObject(
      hMem,
      *phBitmap );

   return hMem;
}

void hbDockGuideEndPaintBuffer(
   HDC hScreen,
   HDC hBuffer,
   RECT * pRect,
   HBITMAP hBitmap )
{
   BitBlt(
      hScreen,
      pRect->left,
      pRect->top,
      pRect->right - pRect->left,
      pRect->bottom - pRect->top,
      hBuffer,
      0,
      0,
      SRCCOPY );

   DeleteObject(
      hBitmap );

   DeleteDC(
      hBuffer );
}