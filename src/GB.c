#include "GB.h"
#include "mem.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int load_cartrigbe(gb_ctx_t *gb, const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) {
        return 1;
    }

    fseek(f, 0, SEEK_END);
    uint32_t file_size = ftell(f);
    rewind(f);
    
    if (file_size >= CARTRIGBE_SIZE) {
        return 2;
    }

    size_t fread_ret = fread(gb->mem.buffer, 1, file_size, f);
    if (fread_ret != file_size) {
        return 3;
    }

    fclose(f);
    return 0;
}
