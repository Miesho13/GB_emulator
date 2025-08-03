#include <stdio.h>
#include <stdlib.h>

#include "GB_int.h"
#include "GB.h"

void gb_monitor(gb_ctx_t *gb) {
    for (int i = 0; i < CARTRIGBE_SIZE; i++) {
        printf("0x%2x ", gb->mem.buffer[i]);
        if (i%10 == 0 && i != 0) {
            printf("\n");
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        puts("Error: invalid arguments.\n\tUsage: GB <path_to_rome>");
        return 1;
    }
    gb_ctx_t gb;

    load_cartrigbe(&gb, argv[1]);
    gb_monitor(&gb);

    cpu_step(NULL, NULL);

    return 0;
}
