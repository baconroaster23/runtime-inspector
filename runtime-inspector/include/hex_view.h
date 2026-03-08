#ifndef HEX_VIEW_H
#define HEX_VIEW_H

#include <sys/types.h>
#include <stddef.h>

void hex_dump(pid_t pid, unsigned long address, size_t length);

#endif