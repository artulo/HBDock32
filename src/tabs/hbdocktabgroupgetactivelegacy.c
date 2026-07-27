#include "hbdocktabgroup.h"

/*
 * NOTA DE ESTABILIZACION (Etapa 1):
 * Este archivo se llamaba "hbdocktabgroup_de dock.c" (nombre con un
 * espacio literal, señal de una generacion/renombrado automatico
 * que fallo). Ademas, hbDockTabGroupInit/Add/Remove/SetActive aqui
 * usaban pGroup->Panels[] y pGroup->Active, campos que YA NO EXISTEN
 * en HB_DOCK_TAB_GROUP (el struct actual usa Tabs[]/ActiveIndex, ver
 * include/hbdocktabgroup.h). Esas cuatro funciones no podian compilar
 * contra el header actual y ademas duplicaban (con el struct correcto)
 * a hbdocktabgroup.c / hbdocktabgroupinit.c / addpanel.c / removepanel.c
 * / setactive.c, asi que se retiraron.
 *
 * hbDockTabGroupGetActive SI se usa en vivo (src/dock/hbdockdocument.c)
 * y es la unica definicion de este simbolo en todo el arbol, asi que
 * se conserva aqui, corregida para usar los campos reales del struct.
 */

HB_DOCK_PANEL * hbDockTabGroupGetActive(
   HB_DOCK_TAB_GROUP * pGroup )
{
   if( pGroup == NULL )
      return NULL;

   if( pGroup->ActiveIndex >= pGroup->Count )
      return NULL;

   return pGroup->Tabs[
      pGroup->ActiveIndex ].pPanel;
}
