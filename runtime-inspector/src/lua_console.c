#include <stdio.h>
#include <string.h>
#include <lua5.4/lua.h>
#include <lua5.4/lauxlib.h>
#include <lua5.4/lualib.h>

void start_lua_console() {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    char input[512];

    printf("Runtime Inspector Lua Console\n");
    printf("Type 'exit' to quit\n");

    while (1) {
        printf("lua> ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "exit", 4) == 0)
            break;

        if (luaL_dostring(L, input) != LUA_OK) {
            printf("Lua Error: %s\n", lua_tostring(L, -1));
        }
    }

    lua_close(L);
}