#include "../inc/header.h"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "");
	// setlocale(LC_ALL, "ja_JP.UTF8");

	WINDOW* mainwin = initscr();

	curs_set(false);

	mx_matrix_rain(mainwin, argc, argv);

	delwin(mainwin);

	endwin();

	return 0;
}
