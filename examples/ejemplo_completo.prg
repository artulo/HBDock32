/*
 * ejemplo_completo.prg - HBDock32 v1.0
 *
 * Recorrido interactivo por las 7 operaciones principales, usando
 * la clase TDockPanel. El orden de creacion sigue el patron
 * confirmado que funciona: primero BUTTONBAR y MENU, despues los
 * TDockPanel.
 */

#include "FiveWin.ch"
#include "hbdock.ch"

PROCEDURE Main()

   LOCAL oWnd, oBar
   LOCAL hDock
   LOCAL oExplorer, oProps, oOutput

   HBDockInitialize()

   DEFINE WINDOW oWnd ;
      FROM 0, 0 TO 770, 1200 PIXEL ;
      TITLE "HBDock32 - Recorrido completo";
	  MENU  BuildMenu()
	  
   hDock := HBDockCreateManager( oWnd:hWnd )

   DEFINE BUTTONBAR oBar OF oWnd SIZE 100, 20

      DEFINE BUTTON OF oBar ;
         PROMPT "1. Dock izquierda" ;
         ACTION oExplorer:Dock( HB_DOCK_LEFT )

      DEFINE BUTTON OF oBar ;
         PROMPT "2. Tab al centro" ;
         ACTION oProps:Dock( HB_DOCK_CENTER )

      DEFINE BUTTON OF oBar ;
         PROMPT "3. AutoHide" ;
         ACTION oOutput:AutoHide()

      DEFINE BUTTON OF oBar ;
         PROMPT "4. Restaurar" ;
         ACTION oOutput:RestoreAutoHide()

      DEFINE BUTTON OF oBar ;
         PROMPT "5. Flotar" ;
         ACTION oOutput:Float()

      DEFINE BUTTON OF oBar ;
         PROMPT "6. Guardar" ;
         ACTION ( HBDockSaveWorkspace( hDock, "layout_demo.txt" ), ;
                  MsgInfo( "Layout guardado en layout_demo.txt" ) )

      DEFINE BUTTON OF oBar ;
         PROMPT "7. Restaurar" ;
         ACTION ( HBDockLoadWorkspace( hDock, "layout_demo.txt" ), ;
                  MsgInfo( "Layout restaurado" ) )

      DEFINE BUTTON OF oBar ;
         PROMPT "Rects" ;
         ACTION MsgInfo( "Explorer: " + hb_ValToExp( GETWNDRECT( oExplorer:hWnd ) ) + hb_eol() + ;
                          "Props:    " + hb_ValToExp( GETWNDRECT( oProps:hWnd ) )    + hb_eol() + ;
                          "Output:   " + hb_ValToExp( GETWNDRECT( oOutput:hWnd ) )   + hb_eol() + ;
                          "Ventana:  " + hb_ValToExp( GETWNDRECT( oWnd:hWnd ) ) )


   oExplorer := TDockPanel():New( 30, 0,  60, 25, oWnd, hDock, "Explorer",     "Explorador de soluciones" )
   oProps    := TDockPanel():New( 30, 25, 60, 50, oWnd, hDock, "Propiedades",  "Propiedades" )
   oOutput   := TDockPanel():New( 60, 0,  70, 25, oWnd, hDock, "Salida",       "Ventana de salida" )

   oExplorer:nClrPane := RGB( 200, 220, 255 )
   oProps:nClrPane    := RGB( 255, 220, 200 )
   oOutput:nClrPane   := RGB( 210, 255, 210 )

   ACTIVATE WINDOW oWnd ;
      ON INIT ( oExplorer:Dock( HB_DOCK_LEFT ), ;
                oOutput:Dock( HB_DOCK_BOTTOM ) ) ;
      ON RESIZE HBDockRefreshLayout( hDock )

   HBDockDestroyManager( hDock )
   HBDockFinalize()

RETURN

function BuildMenu()

   local oMenu

   MENU oMenu    
      MENUITEM "&Salir" ACTION oWnd:End()
   ENDMENU
   

return oMenu