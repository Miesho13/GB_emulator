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

#define LD(L, R)  \
    do {          \
        L = R;    \
    } while(0)    \

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

    }
}




// 0x06 0x22
