#include "hbdockversion.h"

int hbDockGetMajorVersion( void )
{
   return HBDOCK_VERSION_MAJOR;
}

int hbDockGetMinorVersion( void )
{
   return HBDOCK_VERSION_MINOR;
}

int hbDockGetPatchVersion( void )
{
   return HBDOCK_VERSION_PATCH;
}

const char * hbDockGetVersionString( void )
{
   return HBDOCK_VERSION_TEXT;
}