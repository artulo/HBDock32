#ifndef HBDOCKVERSIONAPI_H
#define HBDOCKVERSIONAPI_H

#ifdef __cplusplus
extern "C" {
#endif

int hbDockGetMajorVersion( void );
int hbDockGetMinorVersion( void );
int hbDockGetPatchVersion( void );

const char * hbDockGetVersionString( void );

#ifdef __cplusplus
}
#endif

#endif