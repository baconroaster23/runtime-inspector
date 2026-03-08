#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "hex_view.h"

void hex_dump(int pid, unsigned long address, size_t length) {
    char mempath[64];
    sprintf(mempath, "/proc/%d/mem", pid);
    FILE *mem = fopen(mempath, "rb");
    if (!mem) {
        perror("Cannot open memory");
        return;
    }

    uint8_t *buffer = malloc(length);
    if (!buffer) return;

    fseek(mem, address, SEEK_SET);
    fread(buffer, 1, length, mem);

    for (size_t i = 0; i < length; i++) {
        if (i % 16 == 0) printf("\n0x%lx: ", address + i);
        printf("%02x ", buffer[i]);
    }
    printf("\n");

    free(buffer);
    fclose(mem);
}