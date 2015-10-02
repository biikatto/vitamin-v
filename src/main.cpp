#include <ncurses.h>

int main(){
    initscr();

    // misc settings
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // color settings
    start_color();
    use_default_colors();

    
    // ----- Doing! -------

    WINDOW *scr = newwin(0,0,0,0);

    wborder(scr,
            0, 0, 0, 0,
            0, 0, 0, 0);

    wrefresh(scr);

    wgetch(scr);

    endwin();
}
