#pragma once

/* Unused: for ljmp base */
#define BOOTSEC 0x07c0
#define LDRSEC 0x0090
#define LDRENTRY 0x0090

#define BOOTSEC_ADDR 0x7c00
#define LDRSEC_ADDR 0x0900
#define LDRENTRY_OFFSET 0x0300
#define LDRENTRY_ADDR (LDRSEC_ADDR + LDRENTRY_OFFSET)
#define LDRSTART 0x02
#define LDRSIZE 0x04
