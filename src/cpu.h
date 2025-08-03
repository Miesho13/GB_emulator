#ifndef __CPU__
#define __CPU__

#include "GB_int.h"
#include "mem.h"

typedef union {
    uint8_t u8[2];
    uint16_t u16;
} reg;

typedef struct {
    reg af;
    reg bc;
    reg de;
    reg hl;
    uint16_t sp;
    uint16_t pc;
    uint32_t cycle_delay;
} cpu_t;

void cpu_init();
cpu_t* cpu_inst();
void cpu_step(cpu_t *cpu, mem_t *mem);

#endif
