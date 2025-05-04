#include "cpu.h"

void ld_r1r2(uint8_t* r1, uint8_t *r2) {
    *r1 = *r2;
}

void cpu_step(cpu_t *cpu, mem_t *mem) {

    switch(mem->buffer[cpu->pc]) {
        case 0x06:
            ld_r1r2(&cpu->bc.u8[1], &mem->buffer[cpu->pc + 1]);
            cpu->pc += 2;
            break;

        case 0x0e:
            ld_r1r2(&cpu->bc.u8[0], &mem->buffer[++cpu->pc + 1]);
            cpu->pc += 2;
            break;

        case 0x16:
            ld_r1r2(&cpu->de.u8[1], &mem->buffer[cpu->pc + 1]);
            cpu->pc += 2;
            break;

        case 0x1e:
            ld_r1r2(&cpu->de.u8[0], &mem->buffer[cpu->pc + 1]);
            cpu->pc += 2;
            break;

        case 0x26:
            ld_r1r2(&cpu->hl.u8[1], &mem->buffer[cpu->pc + 1]);
            cpu->pc += 2;
            break;

        case 0x2e:
            ld_r1r2(&cpu->hl.u8[0], &mem->buffer[cpu->pc + 1]);
            cpu->pc += 2;
            break;
            
        case 0x7f:
            ld_r1r2(&cpu->af.u8[1], &cpu->af.u8[1]);
            break;

        case 0x78:
            ld_r1r2(&cpu->af.u8[1], &cpu->bc.u8[1]);
            break;

        case 0x79:
            ld_r1r2(&cpu->af.u8[1], &cpu->bc.u8[0]);
            break;

        case 0x7a:
            ld_r1r2(&cpu->af.u8[1], &cpu->de.u8[1]);
            break;

        case 0x7b:
            ld_r1r2(&cpu->af.u8[1], &cpu->de.u8[0]);
            break;

        case 0x7c:
            ld_r1r2(&cpu->af.u8[1], &cpu->hl.u8[1]);
            break;

        case 0x7d:
            ld_r1r2(&cpu->af.u8[1], &cpu->hl.u8[0]);
            break;

        case 0x7d:
            ld_r1r2(&cpu->af.u8[1], &cpu->hl.u8[0]);
            break;

    }
}

// 0x06 0x22
