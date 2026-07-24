#ifndef HBDOCKFLOATING_H
#define HBDOCKFLOATING_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Declaración adelantada */
typedef struct _HB_DOCK_PANEL HB_DOCK_PANEL;

/* Estructura de ventana flotante */
typedef struct _HB_DOCK_FLOATING
{
   HWND hWnd;

   HB_DOCK_PANEL * Panel;

   RECT RestoreRect;

   int Active;

} HB_DOCK_FLOATING;


/* Crea la ventana flotante */
BOOL hbDockFloatingCreate(
   HB_DOCK_FLOATING * pFloating,
   HINSTANCE hInstance,
   HB_DOCK_PANEL * pPanel );

/* Destruye la ventana flotante */
void hbDockFloatingDestroy(
   HB_DOCK_FLOATING * pFloating );

/* Muestra u oculta */
void hbDockFloatingShow(
   HB_DOCK_FLOATING * pFloating,
   int Show );

/* Cambia posición */
void hbDockFloatingMove(
   HB_DOCK_FLOATING * pFloating,
   const RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif /* HBDOCKFLOATING_H */