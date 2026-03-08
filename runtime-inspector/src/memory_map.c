#include <stdio.h>
#include "memory_map.h"

void print_memory_map(int pid) {
    char path[64];
    sprintf(path, "/proc/%d/maps", pid);
    FILE *f = fopen(path, "r");
    if (!f) {
        perror("Cannot open memory maps");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }

    fclose(f);
}