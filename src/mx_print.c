#include "../inc/header.h"

void mx_print(t_matrix *mtrx, int color, int rows_size, int column_size) {
    for (int i = 0; i < rows_size; i++) {
			for (int j = 0; j < column_size; j++) {
				if (j >= mtrx[i].start && j <= mtrx[i].finish ) {
					if (j == mtrx[i].finish) {
						attroff(COLOR_PAIR(color));
						attron(COLOR_PAIR(1));
					}

					mvprintw(j, i * 2, "%lc", mtrx[i].arr[j]);

					if (j == mtrx[i].finish) {
						attroff(COLOR_PAIR(1));
						attron(COLOR_PAIR(color));
					}
					if (j == mtrx[i].start)
						mtrx[i].arr[j] = mx_get_kanji();
					if (j == mtrx[i].finish)
						mtrx[i].arr[j] = mx_get_kanji();
				}
			}

			mtrx[i].start++;
			mtrx[i].finish++;

			if (mtrx[i].start > column_size) {
				mtrx[i].length = rand() % column_size;
				mtrx[i].start = 0 - mtrx[i].length - mtrx[i].length;
				mtrx[i].finish = 0 - mtrx[i].length;
			}
		}
}

