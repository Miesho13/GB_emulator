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
#define LD(nn, n) nn = n

#define DEC(n) --n 

#define INC(n) ++n 

/*
* Description:
*   Put A into memory address HL. Decrement HL.
*   Same as: LD (HL),A - DEC HL
*/
#define LDD(nn, n) \
    do {           \
        nn = n;    \
        n--;       \ 
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
                memory(REG_HL)
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
                REG_H
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x45: {
            LD(
                REG_B,
                REG_L
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x46: {
            LD(
                REG_B,
                memory(REG_HL)
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x48: {
            LD(
                REG_C,
                REG_B
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x49: {
            LD(
                REG_C,
                REG_C
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x4A: {
            LD(
                REG_C,
                REG_D
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x4B: {
            LD(
                REG_C,
                REG_E
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x4C: {
            LD(
                REG_C,
                REG_H
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x4D: {
            LD(
                REG_C,
                REG_L
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }
                   
        case 0x4E: {
            LD(
                REG_C,
                memory(REG_HL)
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }
                   
        case 0x50: {
            LD(
                REG_D,
                REG_B
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x51: {
            LD(
                REG_D,
                REG_C
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x52: {
            LD(
                REG_D,
                REG_D
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x53: {
            LD(
                REG_D,
                REG_E
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x54: {
            LD(
                REG_D,
                REG_H
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x55: {
            LD(
                REG_D,
                REG_L
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }
                   
        case 0x56: {
            LD(
                REG_D,
                memory(REG_HL)
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }
                   
        case 0x58: {
            LD(
                REG_E,
                REG_B
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x59: {
            LD(
                REG_E,
                REG_C
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }
                   
        case 0x5A: {
            LD(
                REG_E,
                REG_D
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x5B: {
            LD(
                REG_E,
                REG_E
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x5C: {
            LD(
                REG_E,
                REG_H
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x5D: {
            LD(
                REG_E,
                REG_L
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x5E: {
            LD(
                REG_E,
                memory(REG_HL)
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x60: {
            LD(
                REG_H,
                REG_B
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }
                  
        case 0x61: {
            LD(
                REG_H,
                REG_C
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x62: {
            LD(
                REG_H,
                REG_D
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x63: {
            LD(
                REG_H,
                REG_E
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x64: {
            LD(
                REG_H,
                REG_H
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }
                   
        case 0x65: {
            LD(
                REG_H,
                REG_L
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x66: {
            LD(
                REG_H,
                memory(REG_HL)
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x68: {
            LD(
                REG_L,
                REG_B
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x69: {
            LD(
                REG_L,
                REG_C
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x6A: {
            LD(
                REG_L,
                REG_D
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x6B: {
            LD(
                REG_L,
                REG_E
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x6C: {
            LD(
                REG_L,
                REG_H
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x6D: {
            LD(
                REG_L,
                REG_L
            );
            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x6E: {
            LD(
                REG_L,
                memory(REG_HL)
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x70: {
            LD(
                REG_HL,
                REG_B
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x71: {
            LD(
                memory(REG_HL),
                REG_C
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x72: {
            LD(
                memory(REG_HL),
                REG_D
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x73: {
            LD(
                memory(REG_HL),
                REG_E
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x74: {
            LD(
                memory(REG_HL),
                REG_H
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x75: {
            LD(
                memory(REG_HL),
                REG_L
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x36: {
            LD(
                memory(REG_HL),
                memory(REG_PC + 1);
            );
            REG_PC += 2;
            CYCLE_DLY(12);
            break;
        }
                   
        case 0x0A: {
            LD(
                REG_A,
                memory(REG_BC)
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x1A: {
            LD(
                REG_A,
                memory(REG_DE)
            );
            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0xFA: {

            uint16_t nn = memory(REG_PC + 1);
            nn = memory(REG_PC + 2) << 8;

            LD(
                REG_A,
                memory(nn);
            );

            REG_PC += 3;
            CYCLE_DLY(16);
            break;
        }

        case 0x3e: {
            LD(
                REG_A,
                memory(REG_PC + 1);
            );

            REG_PC += 2;
            CYCLE_DLY(8);
            break;
        }

        case 0x47: {
            LD(
                REG_B,
                REG_A
            );

            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x4f: {
            LD(
                REG_C,
                REG_A
            );

            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x57: {
            LD(
                REG_D,
                REG_A
            );

            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x5f: {
            LD(
                REG_E,
                REG_A
            );

            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x67: {
            LD(
                REG_H,
                REG_A
            );

            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x6f: {
            LD(
                REG_L,
                REG_A
            );

            REG_PC += 1;
            CYCLE_DLY(4);
            break;
        }

        case 0x02: {
            LD(
                memory(REG_BC),
                REG_A
            );

            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x12: {
            LD(
                memory(REG_DE),
                REG_A
            );

            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x77: {
            LD(
                memory(REG_HL),
                REG_A
            );

            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0xEA: {
            uint16_t nn = memory(REG_PC + 1);
            nn = memory(REG_PC + 2) << 8;

            LD(
                memory(nn),
                REG_A
            );

            REG_PC += 3;
            CYCLE_DLY(16);
            break;
        }
                   
        case 0xF2: {
            LD(
                REG_A,
                memory(0xFF00 + memory(REG_C))
            );

            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0xE2: {
            LD(
                memory(0xFF00 + memory(REG_C)),
                REG_A
            );

            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x3A: {
            LD(
                REG_A,
                memory(REG_HL)
            );

            DEC(REG_HL);

            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x32: {
            LD(
                memory(REG_HL),
                REG_A
            );

            DEC(REG_HL);

            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        // LDI
        case 0x2A: {
            LD(
                REG_A,
                memory(REG_HL)
            );

            INC(REG_HL);

            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0x22: {
            LD(
                memory(REG_HL),
                REG_A
            );

            INC(REG_HL);

            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

        case 0xE0: {
            LD(
                memory(0xFF00 + memory(REG_PC + 1)),
                REG_A
            );

            REG_PC += 2;
            CYCLE_DLY(12);
            break;
        }

        case 0xF0: {
            LD(
                REG_A,
                memory(0xFF00 + memory(REG_PC + 1))
            );

            REG_PC += 2;
            CYCLE_DLY(12);
            break;
        }

        case 0x01: {
            uint16_t nn = memory(REG_PC + 1);
            nn = memory(REG_PC + 2) << 8;

            LD(
                REG_BC,
                nn
            );

            REG_PC += 3;
            CYCLE_DLY(12);
            break;
        }

        case 0x11: {
            uint16_t nn = memory(REG_PC + 1);
            nn = memory(REG_PC + 2) << 8;

            LD(
                REG_DE,
                nn
            );

            REG_PC += 3;
            CYCLE_DLY(12);
            break;
        }

        case 0x21: {
            uint16_t nn = memory(REG_PC + 1);
            nn = memory(REG_PC + 2) << 8;

            LD(
                REG_HL,
                nn
            );

            REG_PC += 3;
            CYCLE_DLY(12);
            break;
        }

        case 0x31: {
            uint16_t nn = memory(REG_PC + 1);
            nn = memory(REG_PC + 2) << 8;

            LD(
                REG_SP,
                nn
            );

            REG_PC += 3;
            CYCLE_DLY(12);
            break;
        }

        case 0xF9: {
            LD(
                REG_SP,
                REG_HL
            );

            REG_PC += 1;
            CYCLE_DLY(8);
            break;
        }

    }
}




// 0x06 0x22
