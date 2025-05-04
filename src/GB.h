#ifndef __GB_H__
#define __GB_H__

#include "mem.h"
#include "cpu.h"

typedef struct { 
    cpu_t cpu;
    mem_t mem;
} gb_ctx_t;

void init(gb_ctx_t gb_ctx);
void run(gb_ctx_t gb_ctx);
int load_cartrigbe(gb_ctx_t *gb, const char *path);

#endif
