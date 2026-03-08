#include <ncurses.h>
#include "tui.h"

void start_ui() {
    initscr();
    noecho();
    curs_set(FALSE);

    printw("Runtime Inspector TUI\n");
    printw("Press q to quit\n");
    refresh();

    while (getch() != 'q');

    endwin();
}