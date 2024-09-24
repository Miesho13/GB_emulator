#ifndef __CPU__
#define __CPU__

#include "GB_int.h"
#include "mem.h"

typedef struct {
    byte_t A; byte_t F;
    byte_t B; byte_t C;
    byte_t D; byte_t E;
    byte_t H; byte_t L;
    word_t SP;
    word_t PC;

} cpu_t;

void cpu_step(cpu_t *cpu_ctx, mem_t *mem_ctx);

#endif
