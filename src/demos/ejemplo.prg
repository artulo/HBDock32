PROCEDURE Main()

   LOCAL oDock

   DEFINE WINDOW Form_1 ;
      WIDTH 1200 ;
      HEIGHT 800 ;
      MAIN

   oDock := HBDOCKCREATEMANAGER( Form_1.HWnd )

   HBDOCKREGISTERPANEL(
      oDock,
      Form_1.Panel1.HWnd,
      "Explorer",
      "Solution Explorer" )

   HBDOCKREGISTERPANEL(
      oDock,
      Form_1.Panel2.HWnd,
      "Properties",
      "Properties" )

   HBDOCKDOCKPANEL(
      oDock,
      "Explorer",
      HB_DOCK_LEFT )

   HBDOCKDOCKPANEL(
      oDock,
      "Properties",
      HB_DOCK_RIGHT )

   ACTIVATE WINDOW Form_1

RETURN
/*
oDock := HBDockManager():New( Form_1 )

oExplorer := oDock:AddPanel( ;
      "Explorer", ;
      Form_Explorer )

oExplorer:DockLeft()

oOutput := oDock:AddPanel( ;
      "Output",
      Form_Output )

oOutput:DockBottom()

oExplorer:AutoHide()

oDock:SaveLayout( "layout.xml" )

oDock:LoadLayout( "layout.xml" )
*/