#include <windows.h>

#include "hbdocklayoutcontext.h"

void hbDockLayoutContextInit(
   HB_DOCK_LAYOUT_CONTEXT * pContext )
{
   if( pContext == NULL )
      return;

   ZeroMemory(
      pContext,
      sizeof( HB_DOCK_LAYOUT_CONTEXT ) );
}

void hbDockLayoutContextSetRect(
   HB_DOCK_LAYOUT_CONTEXT * pContext,
   const RECT * pRect )
{
   if( pContext == NULL )
      return;

   if( pRect == NULL )
      return;

   pContext->ClientRect = *pRect;

   pContext->Width =
      pRect->right - pRect->left;

   pContext->Height =
      pRect->bottom - pRect->top;
}