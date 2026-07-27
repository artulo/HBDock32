#ifndef HBDOCKMONITOR_H
#define HBDOCKMONITOR_H

/*
 * MonitorFromWindow/MonitorFromPoint/GetMonitorInfo/EnumDisplayMonitors
 * requieren WINVER/_WIN32_WINNT >= 0x0500 (Windows 2000) para que
 * <windows.h> los declare. Se define solo si el proyecto no fijo ya
 * un valor mas alto en otro lado.
 */
#ifndef WINVER
#define WINVER 0x0500
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Etapa 10 -- soporte de multiples monitores.
 *
 * Hasta esta etapa, nada del proyecto era consciente de que puede
 * haber mas de un monitor: no se usaba MonitorFromWindow/GetMonitorInfo
 * en ningun lado. En la practica esto no rompia el arrastre/float
 * basico (Windows acepta coordenadas de escritorio virtual sin
 * problema en MoveWindow/CreateWindowEx), pero dejaba dos huecos
 * reales:
 *
 *   1) Una ventana flotante podia terminar mitad adentro/mitad
 *      afuera del area de trabajo del monitor (por ejemplo, tapada
 *      por la barra de tareas de ESE monitor en particular, que
 *      puede estar en un borde distinto al del monitor principal).
 *
 *   2) Si mas adelante se guarda la posicion de una ventana flotante
 *      y despues se abre la app con un monitor desconectado (por
 *      ejemplo, una notebook sin el segundo monitor enchufado), la
 *      ventana podria "aparecer" en coordenadas que ya no existen --
 *      invisible para el usuario, sin ningun mensaje de error.
 *
 * Este modulo da las 4 operaciones basicas para resolver ambos casos.
 * Es Win32 puro (multi-monitor API, disponible desde Windows 2000),
 * sin nada especifico de un compilador.
 */

/* Area de trabajo (sin la barra de tareas) del monitor que contiene
 * hWnd, o del monitor mas cercano si hWnd esta fuera de todos. */
BOOL hbDockMonitorGetWorkArea(
   HWND hWnd,
   RECT * pWorkArea );

/* Igual, pero a partir de un punto de pantalla (por ejemplo, donde
 * se soltó el mouse al terminar un arrastre) en vez de una ventana. */
BOOL hbDockMonitorGetWorkAreaAtPoint(
   POINT pt,
   RECT * pWorkArea );

/* TRUE si pRect es al menos parcialmente visible en algun monitor
 * conectado ahora mismo. Util para detectar layouts guardados con
 * una posicion de un monitor que ya no esta. */
BOOL hbDockMonitorRectIsVisible(
   const RECT * pRect );

/* Ajusta pRect (in/out) para que quede completamente adentro de
 * pWorkArea, conservando su tamaño si entra, o recortandolo si el
 * monitor es mas chico que la ventana. */
void hbDockMonitorClampRect(
   RECT * pRect,
   const RECT * pWorkArea );

#ifdef __cplusplus
}
#endif

#endif /* HBDOCKMONITOR_H */
