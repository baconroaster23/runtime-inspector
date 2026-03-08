#include <stdio.h>
#include <dirent.h>
#include "threads.h"

void list_threads(int pid) {
    char path[64];
    sprintf(path, "/proc/%d/task", pid);
    DIR *dir = opendir(path);
    if (!dir) {
        perror("Cannot open threads");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (entry->d_name[0] == '.') continue;
        printf("Thread ID: %s\n", entry->d_name);
    }

    closedir(dir);
}