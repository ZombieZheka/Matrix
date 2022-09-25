#include "../inc/header.h"

void mx_text(WINDOW *mainwin, int colums, int rows) {
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
	wbkgd(mainwin, COLOR_PAIR(2));

	int pause = 250000;
    if (colums > 16 && rows > 32) {
        int x = colums / 8;
        int y = rows / 64;

        wtimeout(mainwin, 60/1700000);
        timeout(6000000);
        usleep(pause);

        char first[] = "Wake up , Neo..";
        char second[] = "The Matrix has you..";
        char third[] = "Follow the white rabbit";
        char fourth[] = "Knock, knock, Neo";

        wclear(mainwin);

        for (int index = 0; index < 15; index++) {
            mvwaddch(mainwin, y, x + index, first[index]);
            refresh();
            wtimeout(mainwin, 60/1700000);
            usleep(pause);
        }

        wclear(mainwin);

        for (int index = 0; index < 20; index++) {
            mvwaddch(mainwin, y, x + index, second[index]);
            refresh();
            wtimeout(mainwin, 60/1700000);
            usleep(pause);
        }

        wclear(mainwin);

        for (int index = 0; index < 23; index++) {
            mvwaddch(mainwin, y, x + index, third[index]);
            refresh();
            wtimeout(mainwin, 60/1700000);
            usleep(pause);
        }

        wclear(mainwin);

        for (int index = 0; index < 17; index++) {
            mvwaddch(mainwin, y, x + index, fourth[index]);
            refresh();
            wtimeout(mainwin, 60/1700000);
            usleep(pause);
        }
    }
}

