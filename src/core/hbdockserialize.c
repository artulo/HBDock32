#include <windows.h>

#include "hbdockserialize.h"

BOOL hbDockStateSave(
   HANDLE hFile,
   const HB_DOCK_STATE * pState )
{
   DWORD dwWritten;

   if( hFile == INVALID_HANDLE_VALUE )
      return FALSE;

   if( pState == NULL )
      return FALSE;

   return WriteFile(
      hFile,
      pState,
      sizeof( HB_DOCK_STATE ),
      &dwWritten,
      NULL );
}

BOOL hbDockStateLoad(
   HANDLE hFile,
   HB_DOCK_STATE * pState )
{
   DWORD dwRead;

   if( hFile == INVALID_HANDLE_VALUE )
      return FALSE;

   if( pState == NULL )
      return FALSE;

   return ReadFile(
      hFile,
      pState,
      sizeof( HB_DOCK_STATE ),
      &dwRead,
      NULL );
}