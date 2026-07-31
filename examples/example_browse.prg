/*
 * example_browse.prg - HBDock32 v1.0
 *
 * Igual que example.prg (layout estilo Visual Studio con paneles de
 * ancho/alto fijo -- SetDockSize, Etapa 49/63), pero con un TWBrowse
 * real de datos en el area central de trabajo.
 *
 * A diferencia de la version anterior de este archivo, el TWBrowse
 * ya NO se posiciona a mano contra la ventana principal (eso
 * duplicaba los mismos numeros de SetDockSize en dos lugares
 * distintos -- fragil, y quedaba mal alineado con el resto). Ahora
 * el TWBrowse vive DENTRO de un quinto TDockPanel ("Documentos") que
 * NO tiene SetDockSize -- queda flexible, y HBDock32 le da
 * automaticamente todo el espacio que sobra despues de ubicar a los
 * otros 4 paneles (fijos) a su alrededor. El TWBrowse solo necesita
 * llenar a SU PROPIO padre (el panel), no calcular nada respecto de
 * la ventana principal -- exactamente el mismo patron que usa la
 * referencia XDockPane (oDockMgr:EmbedWindow -- una ventana real de
 * FiveWin embebida DENTRO de un panel acoplado).
 *
 * Estructura (de afuera hacia el centro):
 *
 *   +----------+----------+--------------------------+----------+
 *   |Explorador| Archivos |                          |Panel     |
 *   |  220px   |  260px   |   Documentos (panel       |FiveWin   |
 *   |          |          |   FLEXIBLE, sin           |  260px   |
 *   |          |          |   SetDockSize -- el       |          |
 *   |          |          |   TWBrowse vive adentro)  |          |
 *   +----------+----------+--------------------------+----------+
 *   |                    Salida (150px de alto)                 |
 *   +------------------------------------------------------------+
 */

#include "FiveWin.ch"
#include "hbdock.ch"

 static oWnd, oBar
 static hDock
  
PROCEDU hDock
PROCEDURE Main()

   //LOCAL oWnd, oBar
  // LOCAL hDock
   LOCAL oExplorador, oArchivos, oPanelFW, oSalida, oDocumentos
   LOCAL oGetNombre
   LOCAL cNombre := Space( 40 )
   LOCAL oBrowse
   LOCAL aData

   aData := { ;
      { "C001", "Juan Perez",     "juan.perez@mail.com" }, ;
      { "C002", "Maria Gomez",    "maria.gomez@mail.com" }, ;
      { "C003", "Carlos Ruiz",    "carlos.ruiz@mail.com" }, ;
      { "C004", "Ana Torres",     "ana.torres@mail.com" }, ;
      { "C005", "Luis Fernandez", "luis.fernandez@mail.com" }, ;
      { "C006", "Sofia Diaz",     "sofia.diaz@mail.com" }, ;
      { "C007", "Pedro Alvarez",  "pedro.alvarez@mail.com" } }

   HBDockInitialize()

   DEFINE WINDOW oWnd ;
      FROM 0, 0 TO 800, 1300 PIXEL ;
      TITLE "HBDock32 - TWBrowse embebido en panel flexible" ;
      MENU BuildMenu()

   hDock := HBDockCreateManager( oWnd:hWnd )
HBDockSetTheme( hDock, HBDOCK_THEME_OFFICE2007 )
   DEFINE BUTTONBAR oBar OF oWnd SIZE 100, 20 ed 2007

   /*
    * HBDock32 no sabe que la toolbar existe -- hay que informarle su
    * altura real una sola vez para que la reste siempre del area
    * disponible (ver Etapa 37).
    */
   HBDockSetTopMargin( hDock, oBar:nHeight )

      DEFINE BUTTON OF oBar ;
         PROMPT "Guardar layout" ;
         ACTION ( HBDockSaveWorkspace( hDock, "layout_vs.txt" ), ;
                  MsgInfo( "Layout guardado en layout_vs.txt" ) )

      DEFINE BUTTON OF oBar ;
         PROMPT "Restaurar layout" ;
         ACTION ( HBDockLoadWorkspace( hDock, "layout_vs.txt" ), ;
                  MsgInfo( "Layout restaurado" ) )

   /*
    * Los 5 paneles acoplados -- 4 de ancho/alto fijo (SetDockSize,
    * mas abajo) y "Documentos" sin fijar, que es el que absorbe todo
    * el espacio restante. Los colores de fondo son solo para
    * distinguirlos a simple vista en la demo.
    */
   oExplorador := TDockPanel():New( 10, 10, 40, 30, oWnd, hDock, "Explorador", "Explorador" )
   oArchivos   := TDockPanel():New( 10, 30, 40, 50, oWnd, hDock, "Archivos",   "Archivos" )
   oDocumentos := TDockPanel():New( 10, 50, 40, 70, oWnd, hDock, "Documentos", "Documentos" )
   oPanelFW    := TDockPanel():New( 10, 70, 40, 90, oWnd, hDock, "PanelFW",    "Panel FiveWin" )
   oSalida     := TDockPanel():New( 40, 10, 55, 90, oWnd, hDock, "Salida",     "Salida" )
/*
   oExplorador:nClrPane := RGB( 240, 240, 240 )
   oArchivos:nClrPane   := RGB( 240, 240, 240 )
   oDocumentos:nClrPane := RGB( 255, 255, 255 )
   oPanelFW:nClrPane    := RGB( 250, 250, 250 )
   oSalida:nClrPane     := RGB( 255, 255, 255 )
   */
oExplorador:SetColor( CLR_BLACK, CLR_RED )
oArchivos:SetColor( CLR_BLACK, CLR_YELLOW )
oDocumentos:SetColor( CLR_BLACK, CLR_WHITE )
oPanelFW:SetColor( CLR_BLACK, CLR_BLUE )
oSalida:SetColor( CLR_BLACK, CLR_GREEN )
   /*
    * Contenido de ejemplo de los paneles laterales/inferior (igual
    * que example.prg).
    */
   @ 4, 4 SAY "Arbol de proyecto" OF oExplorador SIZE 150, 12 PIXEL
   @ 4, 4 SAY "Arbol de archivos" OF oArchivos SIZE 150, 12 PIXEL

   @ 20, 10 SAY "Nombre:" OF oPanelFW SIZE 60, 12 PIXEL
   @ 18, 75 GET oGetNombre VAR cNombre OF oPanelFW SIZE 140, 14 PIXEL
   @ 50, 10 BUTTON "Guardar" OF oPanelFW SIZE 90, 24 PIXEL ;
      ACTION MsgInfo( "Nombre: " + AllTrim( cNombre ) )

   @ 4, 4 SAY "=== Compilacion iniciada ===" + CRLF + ;
              "Compilando Main.prg... OK" + CRLF + ;
              "0 errores, 0 advertencias" ;
      OF oSalida SIZE 400, 60 PIXEL

   /*
    * El TWBrowse -- OJO: se crea con oDocumentos (el PANEL) como
    * padre, NO oWnd (la ventana principal). Esto es lo que lo hace
    * "independiente": no necesita saber nada de los otros paneles ni
    * de la ventana principal, solo llenar a su propio padre -- el
    * padre es chico (10x10 al principio, cualquier valor sirve) y se
    * reajusta solo en cada resize de oDocumentos (ver bResized mas
    * abajo), que a su vez HBDock32 mueve/redimensiona automaticamente
    * como a cualquier otro panel.
    *
    * TWBrowse recibe aHeaders y aColSizes directo en el constructor,
    * y bLine es un bloque que devuelve la FILA ACTUAL completa como
    * array. El bloque recibe SU PROPIO objeto como parametro (Self,
    * pasado por la clase via Eval(::bLine,Self)) -- se usa ESE
    * parametro (oSelf), no una variable externa, porque Default()
    * evalua bLine una vez DENTRO del propio New(), antes de que
    * "oBrowse := ...:New(...)" termine de asignarse.
    */
   oBrowse := TWBrowse():New( 0, 0, 10, 10, ;
      {| oSelf | aData[ oSelf:nAt ] }, ;
      { "Codigo", "Nombre", "Email" }, ;
      { 70, 220, 260 }, ;
      oDocumentos )

   oBrowse:SetArray( aData )
   oBrowse:nClrPane := RGB( 255, 255, 255 )

   /*
    * Cada vez que oDocumentos cambia de tamaño (HBDock32 lo mueve
    * automaticamente, como a cualquier panel), el propio panel avisa
    * via bResized -- ahi se reajusta el TWBrowse para llenarlo
    * completo. Nada de esto necesita saber el ancho/alto de ningun
    * OTRO panel ni de la ventana principal.
    */
   oDocumentos:bResized := {| nType, nWidth, nHeight | ;
      oBrowse:Move( 0, 0, nWidth, nHeight, .t. ) }
	  
	/*  oDocumentos:bResized := {| nType, nWidth, nHeight | ;
   oBrowse:Move( 0, 0, nWidth, nHeight, .t. ), ;
   MsgInfo( "bResized: " + Str(nWidth) + "x" + Str(nHeight) ) }
*/
   /*
    * SetDockSize ANTES de Dock() fija el ancho/alto deseado,
    * recalculado en CADA resize (Etapa 63) para los 4 paneles fijos.
    * oDocumentos NO recibe SetDockSize -- se queda flexible.
    *
    * Orden de acoplado -- IMPORTANTE: cada Dock() se aplica relativo
    * a TODA la raiz actual del arbol, no al panel anterior en
    * particular. Para terminar con Explorador (el mas pegado al
    * borde izquierdo) | Archivos | Documentos | PanelFW hay que
    * acoplar en este orden: Documentos primero (queda solo, como
    * raiz completa), Archivos a su izquierda, Explorador a la
    * izquierda de eso, y por ultimo PanelFW a la derecha de todo.
    */
   ACTIVATE WINDOW oWnd ;
      ON INIT ( oDocumentos:SetNoCaption( .t. ), ;
				oDocumentos:Dock( HB_DOCK_LEFT ), ;
				oArchivos:SetDockSize( 260 ), ;
                oArchivos:Dock( HB_DOCK_LEFT ), ;
				oExplorador:SetDockSize( 220 ), ;
                oExplorador:Dock( HB_DOCK_LEFT ), ;
				oPanelFW:SetDockSize( 260 ), ;
                oPanelFW:Dock( HB_DOCK_RIGHT ), ;
				oSalida:SetDockSize( , 150 ), ;
				oSalida:Dock( HB_DOCK_BOTTOM ) ) ;
      ON RESIZE HBDockRefreshLayout( hDock )

 //oDocumentos:SetNoCaption(), ; 
				
   HBDockDestroyManager( hDock )
   HBDockFinalize()

RETURN

//----------------------------------------------------------------------------//

function BuildMenu()
local omenu

     MENU oMenu
      MENUITEM "&Informacion"
      MENU
         MENUITEM "&About..." ACTION MsgInfo( "TestRes", "FiveWin" )
         SEPARATOR
         MENUITEM "&End" ACTION ;
            If( MsgYesNo( OemToAnsi( "Want to end ?" ) ), oWnd:End(),)
      ENDMENU

      MENUITEM "&Themes"
      MENU
        MENUITEM "Office 2007" ACTION HBDockSetTheme( hDock, HBDOCK_THEME_OFFICE2007 )
		MENUITEM "Office 2010" ACTION HBDockSetTheme( hDock, HBDOCK_THEME_OFFICE2010 )
		MENUITEM "Office 2015" ACTION HBDockSetTheme( hDock, HBDOCK_THEME_OFFICE2015 )
      ENDMENU

      MENUITEM "&Utilities"
      MENU
         MENUITEM "&Calculator" ACTION WinExec( "Calc" )
         MENUITEM "C&alendar"   ACTION WinExec( "Calendar" )
         SEPARATOR
         MENUITEM "&Write"      ACTION oWnd:Say( 20, 2, "FiveWin, wow !!!" )
      ENDMENU
   ENDMENU
   
return oMenu
