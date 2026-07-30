#include <windows.h>

#include "hbdockmanagerclosetab.h"
#include "hbdockmanagerundock.h"
#include "hbdockmanagerlayout.h"

/*
 * Etapa 51: "Cierre individual" de una pestana. Reusa
 * hbDockManagerUndockPanel (ya existente y correcto -- distingue
 * "sacar solo este panel de la pestana" de "sacar el contenedor
 * entero" segun si hay otros compañeros de pestana) y le agrega lo
 * que hacia falta para que sea un "cierre" real: ocultar la ventana
 * del panel y marcarlo No Visible. Sin esto, el panel quedaria
 * huerfano (fuera del arbol) pero con su ventana todavia mostrada en
 * pantalla en la ultima posicion que tenia -- nada la va a volver a
 * mover/ocultar una vez que ya no es parte de ningun contenedor.
 */
void hbDockManagerCloseTab(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   if( pManager == NULL )
      return;

   if( pPanel == NULL )
      return;

   hbDockManagerUndockPanel(
      pManager,
      pPanel );

   pPanel->Visible = 0;

   if( pPanel->hWnd != NULL )
      ShowWindow(
         pPanel->hWnd,
         SW_HIDE );

   hbDockManagerLayout(
      pManager );
}
