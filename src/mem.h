#ifndef __MEM__
#define __MEM__

#include <stdlib.h>
#include "GB_int.h"


#define MEM_SIZE 0xFFFF
#define CARTRIGBE_SIZE 0x8000

// MEMORY SIZE
typedef enum {
    ROM_BANK = 0x0000,
    SW_ROM_BANK = 0x4000,
    VRAM = 0x8000,
    SW_RAM = 0xa000,
    INT_RAM_1 = 0xc000, 
    ECHO_RAM = 0xe000,
    SPIRITE_ATTRIBUTE_MEMORY = 0xfe00,
    EMPTY_UNSABLE_IO_1 = 0xfea0,
    IO_PORTS = 0xff00,
    EMPTY_UNSABLE_IO_2 = 0xfea0,
    INT_RAM_2 = 0xff80,
    INTERRUPT_ENABLE_REGISTER = 0xffff

} MEMORY_MAP;

typedef struct {
    uint8_t buffer[MEM_SIZE];
} mem_t;

#endif
