#pragma once
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <locale.h>

typedef struct s_matrix {
	int length;
	int start;
	int finish;
	wchar_t *arr;
} t_matrix;

int mx_strcmp(const char *s1, const char *s2);
void mx_matrix_rain(WINDOW *window, int argc, char *argv[]);
void mx_text(WINDOW *mainwin, int colums, int rows);
wchar_t mx_get_kanji();
void mx_print(t_matrix *mtrx, int color, int rows_size, int column_size);

