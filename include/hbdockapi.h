#ifndef HBDOCKAPI_H
#define HBDOCKAPI_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockInitialize(void);

void hbDockFinalize(void);

void * hbDockCreateManager(HWND hMainWnd);

void hbDockDestroyManager(void * pManager);

BOOL hbDockRegisterPanel(
        void * pManager,
        HWND hPanel,
        LPCTSTR pszName,
        LPCTSTR pszCaption );

BOOL hbDockDockPanel(
        void * pManager,
        LPCTSTR pszPanel,
        int nSide );

BOOL hbDockFloatPanel(
        void * pManager,
        LPCTSTR pszPanel );

BOOL hbDockAutoHidePanel(
        void * pManager,
        LPCTSTR pszPanel );

BOOL hbDockShowPanel(
        void * pManager,
        LPCTSTR pszPanel );

BOOL hbDockHidePanel(
        void * pManager,
        LPCTSTR pszPanel );

#ifdef __cplusplus
}
#endif

#endif