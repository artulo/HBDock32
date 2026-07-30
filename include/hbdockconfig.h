#ifndef HBDOCKCONFIG_H
#define HBDOCKCONFIG_H

#define HBDOCK_REGISTRY_ROOT   "Software\\HBDock32"

#define HBDOCK_MAX_PANELS       256
#define HBDOCK_MAX_NAME          64
#define HBDOCK_MAX_CAPTION      128

#define HBDOCK_SPLITTER_WIDTH     4
#define HBDOCK_TITLE_HEIGHT      24
#define HBDOCK_BORDER_SIZE        1
#define HBDOCK_AUTOHIDE_STRIP    24

/*
 * Etapa 50: pedido explicito -- paso de desplazamiento del splitter,
 * en pixeles. El splitter solo se mueve en multiplos de este valor
 * mientras se arrastra (en vez de responder a cada pixel exacto del
 * mouse) -- subir este numero da un arrastre mas "firme"/con pasos
 * mas grandes y deliberados; 1 (el default) es el comportamiento mas
 * fino/continuo posible.
 */
#define HBDOCK_SPLITTER_STEP      1

#endif