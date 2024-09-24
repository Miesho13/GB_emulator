#ifndef __MEM__
#define __MEM__

#include <stdlib.h>
#include "GB_int.h"

#define MEM_SIZE 0xFFFF
typedef struct {
    byte_t buffer[MEM_SIZE];
} mem_t;

// Function what ensure for load cardridge code 
// to memory.
void load_card();

#endif
