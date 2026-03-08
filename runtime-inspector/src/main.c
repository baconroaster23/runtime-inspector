#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "memory_map.h"
#include "scanner.h"
#include "hex_view.h"
#include "elf_parser.h"
#include "debugger.h"
#include "threads.h"
#include "tui.h"
#include "lua_console.h"

int main() {
    int pid = 0;


    // 2️⃣ Ask user for PID
    printf("\nEnter PID of process to inspect: ");
    if (scanf("%d", &pid) != 1 || pid <= 0) {
        printf("Invalid PID!\n");
        return 1;
    }

    printf("Selected PID: %d\n", pid);

    // 3️⃣ Optional: Show a small hex dump of first 64 bytes
    printf("\nMemory at 0x400000:\n");
    hex_dump(pid, 0x400000, 64);
    start_ui();
    // 4️⃣ Launch Lua console
    start_lua_console();

    printf("\nExiting Runtime Inspector.\n");
    return 0;
}
