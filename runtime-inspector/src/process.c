#include <stdio.h>
#include "process.h"

void print_process_info(int pid) {
    char path[64];
    sprintf(path, "/proc/%d/stat", pid);
    FILE *f = fopen(path, "r");
    if (!f) {
        perror("Cannot open process stat");
        return;
    }

    char buffer[1024];
    fgets(buffer, sizeof(buffer), f);
    printf("Process Stat: %s\n", buffer);

    fclose(f);
}