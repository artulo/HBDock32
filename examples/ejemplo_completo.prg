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
static oWnd
PROCEDURE Main()

   LOCAL  oBar
   LOCAL hDock
   LOCAL oExplorer, oProps, oOutput

   HBDockInitialize()

   DEFINE WINDOW oWnd ;
      FROM 0, 0 TO 770, 1200 PIXEL ;
      TITLE "HBDock32 - Recorrido completo";
	  MENU  BuildMenu()
	  
   hDock := HBDockCreateManager( oWnd:hWnd )

   DEFINE BUTTONBAR oBar OF oWnd SIZE 100, 20 3D 2015

   /*
    * Etapa 37: HBDock32 no sabe que la toolbar existe -- su propio
    * calculo de area disponible (GetClientRect) no la excluye por
    * su cuenta, a diferencia de FiveWin (ver ClientCoors en
    * tsplitter.prg). Se le informa una sola vez, con la altura real
    * de la toolbar, para que la reste siempre de ahi en adelante.
    */
   HBDockSetTopMargin( hDock, oBar:nHeight )

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
         ACTION (oOutput:Float()) 
		 
		 /*MsgInfo( "ANTES de Float() -- IsWindowEnabled = " + hb_ValToExp( IsWindowEnabled( oWnd:hWnd ) ) ), ;
                  oOutput:Float(), ;
                  MsgInfo( "DESPUES de Float() -- IsWindowEnabled( oWnd:hWnd ) = " + hb_ValToExp( IsWindowEnabled( oWnd:hWnd ) ) + hb_eol() + ;
                           "GetActiveWindow()  = " + hb_ValToExp( GetActiveWindow() ) + hb_eol() + ;
                           "oWnd:hWnd          = " + hb_ValToExp( oWnd:hWnd ) ) )*/

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

      DEFINE BUTTON OF oBar ;
         PROMPT "Check Enabled" ;
         ACTION MsgInfo( "IsWindowEnabled( oWnd:hWnd ) = " + hb_ValToExp( IsWindowEnabled( oWnd:hWnd ) ) + hb_eol() + ;
                          "GetActiveWindow() = " + hb_ValToExp( GetActiveWindow() ) + hb_eol() + ;
                          "GetFocus()        = " + hb_ValToExp( GetFocus() ) + hb_eol() + ;
                          "GetCapture()      = " + hb_ValToExp( GetCapture() ) + hb_eol() + ;
                          "oWnd:hWnd         = " + hb_ValToExp( oWnd:hWnd ) )


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