#include "cpu.h"

void cpu_step(cpu_t *cpu_ctx, mem_t *mem_ctx) {

    switch(mem_ctx->buffer[cpu_ctx->PC]) {
        case 0x06:
            cpu_ctx->B = mem_ctx->buffer[cpu_ctx->PC+1];
            cpu_ctx->PC+=2;
            break;

        case 0x0E:
            cpu_ctx->C = mem_ctx->buffer[cpu_ctx->PC+1];
            cpu_ctx->PC+=2;
            break;
    }
}


// 0x06 0x22
