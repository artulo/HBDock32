/*
 * hbdock.ch - Constantes publicas de HBDock32 para Harbour/FiveWin
 *
 * Los valores coinciden 1 a 1 con el HB_DOCK_SITE / HB_DOCK_GUIDE_TYPE
 * del lado C (ver Etapa 8, src/core/hbdockapi.c). No son arbitrarios:
 * si cambian de un lado, tienen que cambiar del otro.
 */

#ifndef HBDOCK_CH
#define HBDOCK_CH

#define HB_DOCK_NONE       0
#define HB_DOCK_LEFT       1
#define HB_DOCK_RIGHT      2
#define HB_DOCK_TOP        3
#define HB_DOCK_BOTTOM     4
#define HB_DOCK_CENTER     5

/*
 * Etapa 80: temas visuales (Office 2007/2010/2015). Los valores
 * coinciden 1 a 1 con HB_DOCK_THEME_ID del lado C (ver
 * hbdocktheme.h).
 */
#define HBDOCK_THEME_OFFICE2007    0
#define HBDOCK_THEME_OFFICE2010    1
#define HBDOCK_THEME_OFFICE2015    2

#endif
