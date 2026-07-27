/*
 * TDockPanel.prg - HBDock32 v1.0
 *
 * Clase FiveWin dedicada para paneles dockeables, en vez de usar
 * TPanel "pelado" + llamadas sueltas a la API de HBDock32.
 *
 * Por que: HBDock32 mueve la ventana real del panel via MoveWindow()
 * desde C, por fuera del modelo de objetos de FiveWin. Envolviendo
 * eso en una clase propia, el resto del codigo de la aplicacion
 * trabaja con metodos (:Dock(), :Float(), :AutoHide()...) en vez de
 * tener que pasar hDock/cDockName a mano en cada llamada, y queda
 * un solo lugar para sincronizar cualquier cosa que haga falta del
 * lado FiveWin despues de cada operacion.
 *
 * Requiere hbdock.ch (constantes HB_DOCK_LEFT, etc.)
 */

#include "FiveWin.ch"
#include "hbdock.ch"

//----------------------------------------------------------------------------//

CLASS TDockPanel FROM TPanel

   DATA cCaption          // Texto que se muestra (puede repetirse, cambiar de idioma)
   DATA cDockName         // Identificador estable interno (unico por manager)
   DATA hDock             // Handle del manager HBDock32 al que pertenece

   METHOD New( nTop, nLeft, nBottom, nRight, oWnd, hDock, cDockName, cCaption ) CONSTRUCTOR

   METHOD Dock( nSide )            INLINE HBDockPanel( ::hDock, ::cDockName, nSide )
   METHOD TabifyOn( cTargetName )  INLINE HBDockTabifyPanel( ::hDock, ::cDockName, cTargetName )
   METHOD Float()                  INLINE HBDockFloat( ::hDock, ::cDockName )
   METHOD Undock()                 INLINE HBDockUndockPanel( ::hDock, ::cDockName )
   METHOD AutoHide()                INLINE HBDockAutoHide( ::hDock, ::cDockName )
   METHOD RestoreAutoHide()         INLINE HBDockAutoHideRestore( ::hDock, ::cDockName )
   METHOD ShowPanel()               INLINE HBDockShowPanel( ::hDock, ::cDockName )
   METHOD HidePanel()               INLINE HBDockHidePanel( ::hDock, ::cDockName )

ENDCLASS

//----------------------------------------------------------------------------//

METHOD New( nTop, nLeft, nBottom, nRight, oWnd, hDock, cDockName, cCaption ) CLASS TDockPanel

   ::Super:New( nTop, nLeft, nBottom, nRight, oWnd, .F., cDockName, .T. )

   ::hDock     := hDock
   ::cDockName := cDockName
   ::cCaption  := cCaption

   /* Registro automatico: en cuanto se crea el panel, ya queda
    * registrado en HBDock32 -- no hace falta llamar a
    * HBDockRegisterPanel() a mano desde el .prg de la aplicacion. */
   if hDock != NIL .and. !Empty( cDockName )
      HBDockRegisterPanel( hDock, ::hWnd, cDockName, cCaption )
   endif

return Self

//----------------------------------------------------------------------------//
