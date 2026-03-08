#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include "debugger.h"

void attach_debugger(int pid) {
    if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1) {
        perror("ptrace attach");
        return;
    }
    wait(NULL);
    printf("Attached to %d\n", pid);
}

void detach_debugger(int pid) {
    ptrace(PTRACE_DETACH, pid, NULL, NULL);
    printf("Detached from %d\n", pid);
}

void step_instruction(int pid) {
    ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
    wait(NULL);
}