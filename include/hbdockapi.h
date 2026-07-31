#ifndef HBDOCKAPI_H
#define HBDOCKAPI_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

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

/*
 * Etapa 49: fijar el ancho/alto deseado de un panel para cuando se
 * acople -- ver src/core/hbdockapi.c.
 */
BOOL hbDockSetPanelSize(
        void * pManager,
        LPCTSTR pszPanel,
        int cx,
        int cy );

/*
 * Etapa 64: ver src/core/hbdockapi.c.
 */
BOOL hbDockSetPanelNoCaption(
        void * pManager,
        LPCTSTR pszPanel,
        BOOL bNoCaption );

BOOL hbDockAutoHidePanel(
        void * pManager,
        LPCTSTR pszPanel );

BOOL hbDockShowPanel(
        void * pManager,
        LPCTSTR pszPanel );

BOOL hbDockHidePanel(
        void * pManager,
        LPCTSTR pszPanel );

BOOL hbDockUndockPanel(
        void * pManager,
        LPCTSTR pszPanel );

BOOL hbDockAutoHideRestorePanel(
        void * pManager,
        LPCTSTR pszPanel );

BOOL hbDockTabifyPanel(
        void * pManager,
        LPCTSTR pszSource,
        LPCTSTR pszTarget );

BOOL hbDockSaveWorkspace(
        void * pManager,
        LPCTSTR pszFile );

BOOL hbDockLoadWorkspace(
        void * pManager,
        LPCTSTR pszFile );

BOOL hbDockRefreshLayout(
        void * pManager );

/*
 * Etapa 28: version acotada de refresh -- solo muestra/repinta las
 * ventanas de caption puntuales, sin recalcular geometria ni tocar
 * nada fuera del arbol de HBDock32 (ver hbDockHostPaintCaptions).
 */
void hbDockRepaintCaptions(
        void * pManager );

/*
 * Etapa 29: diagnostico -- ver src/core/hbdockapi.c.
 */
const char * hbDockDebugCaptions(
        void * pManager );

/*
 * Etapa 37: ver src/core/hbdockapi.c.
 */
void hbDockSetTopMargin(
        void * pManager,
        int nMargin );

/*
 * Etapa 80: ver src/core/hbdockapi.c. nTheme: 0=Office2007,
 * 1=Office2010, 2=Office2015 (ver HB_DOCK_THEME_ID en
 * hbdocktheme.h).
 */
BOOL hbDockSetTheme(
        void * pManager,
        int nTheme );

#ifdef __cplusplus
}
#endif

#endif