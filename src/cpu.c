#include "cpu.h"

static cpu_t cpu_;
static mem_t mem_;

#define REG_A cpu_.af.u8[1]
#define REG_B cpu_.bc.u8[1]  
#define REG_C cpu_.bc.u8[0] 
#define REG_D cpu_.de.u8[1] 
#define REG_E cpu_.de.u8[0] 
#define REG_F cpu_.af.u8[0] 
#define REG_H cpu_.hl.u8[1]
#define REG_L cpu_.hl.u8[0]

#define REG_AF cpu_.af.u16
#define REG_BC cpu_.bc.u16 
#define REG_DE cpu_.de.u16 
#define REG_HL cpu_.hl.u16

#define REG_SP cpu_.sp
#define REG_PC cpu_.pc

#define CYCLE_DLY(cycle) cpu_.cycle_delay = cycle
#define CYCLE_DLY_CLEAR() cpu_.cycle_delay = 0

#define memory(addr) mem_.buffer[addr]

/**
 * LD OPERATION MACRO
 * Put value nn into n
 * Use with:
 *     nn = B, C, D, E, H, L, BC, DE, HL, SP
 *     n = 8 bit immediate value
 * */
#define LD(nn, n)  \
    do {           \
        nn = n;    \
    } while(0)     \

cpu_t* cpu_inst() {
    return &cpu_;
}

mem_t* mem_inst() {
    return &mem_;
}

void cpu_init() {

}

void cpu_step(cpu_t *cpu, mem_t *mem) {

    switch(memory(REG_PC)) {
    /* ---- 8 bit loads  ---- */
        case 0x06: {
            LD(
                REG_B,
                memory(REG_PC + 1);
            );
            REG_PC += 2;
            CYCLE_DLY(4);
            break;
        }

        case 0x0e: {
            LD(
                REG_C,
                memory(REG_PC + 1);
            );
            REG_PC += 2;
            CYCLE_DLY(4);
            break;
        }

        case 0x16: {
            LD(
                REG_D,
                memory(REG_PC + 1);
            );
            REG_PC += 2;
            CYCLE_DLY(4);
            break;
        }

        case 0x1e: {
            LD(
                REG_E,
                memory(REG_PC + 1);
            );
            REG_PC += 2;
            CYCLE_DLY(4);
            break;
        }

        case 0x26: {
            LD(
                REG_H,
                memory(REG_PC + 1);
            );
            REG_PC += 2;
            CYCLE_DLY(4);
            break;
        }

        case 0x2e: {
            LD(
                REG_L,
                memory(REG_PC + 1);
            );
            REG_PC += 2;
            CYCLE_DLY(4);
            break;
        }

    /* --------- LD r2 into r1 load --------- */
        case 0x7f: {
            LD(
                REG_A,
                REG_A
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x78: {
            LD(
                REG_A,
                REG_B
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x79: {
            LD(
                REG_A,
                REG_C
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x7a: {
            LD(
                REG_A,
                REG_D
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x7b: {
            LD(
                REG_A,
                REG_E
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x7c: {
            LD(
                REG_A,
                REG_H
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x7d: {
            LD(
                REG_A,
                REG_L
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x7e: {
            LD(
                REG_A,
                REG_HL
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x40: {
            LD(
                REG_B,
                REG_B
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x41: {
            LD(
                REG_B,
                REG_C
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x42: {
            LD(
                REG_B,
                REG_D
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x43: {
            LD(
                REG_B,
                REG_E
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x44: {
            LD(
                REG_B,
                REG_E
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }
    }
}




// 0x06 0x22
