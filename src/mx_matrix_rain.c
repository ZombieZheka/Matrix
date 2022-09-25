#include "../inc/header.h"

void mx_matrix_rain(WINDOW *mainwin, int argc, char *argv[]) {
	int SPEED = 10;
	int rows_size;
	int column_size;
	int color = 2;
	getmaxyx(mainwin, column_size, rows_size);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);

	curs_set(false);
	noecho();

	t_matrix *mtrx = (t_matrix *) malloc(sizeof(t_matrix) * rows_size);

	for (int i = 0; i < rows_size; i++) {
		mtrx[i].arr = (wchar_t *) malloc(sizeof(wchar_t) * column_size);

		for (int j = 0; j < column_size; j++)
			mtrx[i].arr[j] = mx_get_kanji();

		mtrx[i].length = rand() % column_size;
		mtrx[i].start = 0 - mtrx[i].length - mtrx[i].length;
		mtrx[i].finish = 0 - mtrx[i].length;
	}

	wbkgd(mainwin, COLOR_PAIR(color));

	wclear(mainwin);

  if (argc != 2 || (argc == 2 && mx_strcmp(argv[1], "-s") != 0))
		mx_text(mainwin, column_size, rows_size);

	while(true) {
		wtimeout(mainwin, 60 / SPEED * 10);

		switch(getch()) {
			case '-':
				if (SPEED > 20)
					SPEED -= 10;
				break;
			case '+':
				if (SPEED < 180)
					SPEED += 10;
				break;
			case '1':
				color = 1;
				break;
			case '2':
				color = 2;
				break;
			case '3':
				color = 3;
				break;
			case '4':
				color = 4;
				break;
			case '5':
				color = 5;
				break;
			case '6':
				color = 6;
				break;
			case '7':
				color = 7;
				break;
			case 'q':
				exit(0);
		}

		wclear(mainwin);

		mx_print(mtrx, color, rows_size, column_size);

		refresh();
	}

	for(int i = 0; i < column_size; i++)
		free(mtrx[i].arr);

	free(mtrx);
	mtrx = NULL;
}

