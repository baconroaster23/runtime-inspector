#ifndef DEBUGGER_H
#define DEBUGGER_H

void attach_debugger(int pid);
void detach_debugger(int pid);
void step_instruction(int pid);

#endif