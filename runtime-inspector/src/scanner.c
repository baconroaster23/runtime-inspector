#include <stdio.h>
#include "scanner.h"

void scan_for_int(int pid, int target) {
    char mempath[64];
    sprintf(mempath, "/proc/%d/mem", pid);
    FILE *mem = fopen(mempath, "rb");
    if (!mem) {
        perror("Cannot open memory");
        return;
    }

    int value;
    for (long addr = 0x400000; addr < 0x7fffffff; addr += sizeof(int)) {
        fseek(mem, addr, SEEK_SET);
        if (fread(&value, sizeof(int), 1, mem) != 1) continue;
        if (value == target) printf("Found %d at 0x%lx\n", target, addr);
    }

    fclose(mem);
}