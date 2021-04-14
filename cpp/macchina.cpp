#include "macchina.h"
#include <windows.h>
#include <conio.h>

void macchina::genera_macchina(char x[20][80], int* c, int* y) {
	x[*c][*y] = '0';
	x[*c][*y + 1] = '_';
	x[*c][*y + 2] = '0';
	x[*c + 1][*y] = '(';
	x[*c + 1][*y + 1] = 'A';
	x[*c + 1][*y + 2] = ')';
	x[*c + 2][*y] = '0';
	x[*c + 2][*y + 1] = ' ';
	x[*c + 2][*y + 2] = '0';

}

void macchina::sposta_macchina(char x[20][80], char* key, int* c, int* y, bool b) {
	if (b) {
		*key = getch();
		if (*key == 77 && x[*c][*y + 1] != '(' && x[*c][*y + 2] != '(' && x[*c][*y + 3] != '(') {              //freccia destra
			x[*c][*y] = '*';
			x[*c][*y + 1] = '*';
			x[*c][*y + 2] = '*';
			x[*c + 1][*y] = '*';
			x[*c + 1][*y + 1] = '*';
			x[*c + 1][*y + 2] = '*';
			x[*c + 2][*y] = '*';
			x[*c + 2][*y + 1] = '*';
			x[*c + 2][*y + 2] = '*';

			*y = *y + 3;
			genera_macchina(x, c, y);
		}
		if (*key == 75 && x[*c][*y - 1] != ')' && x[*c][*y - 2] != ')' && x[*c][*y - 3] != ')') {       //freccia sinistra
			x[*c][*y] = '*';
			x[*c][*y + 1] = '*';
			x[*c][*y + 2] = '*';
			x[*c + 1][*y] = '*';
			x[*c + 1][*y + 1] = '*';
			x[*c + 1][*y + 2] = '*';
			x[*c + 2][*y] = '*';
			x[*c + 2][*y + 1] = '*';
			x[*c + 2][*y + 2] = '*';

			*y = *y - 3;
			genera_macchina(x, c, y);
		}
		if (*key == 80 && *c + 3 < 20) {                    //freccia giù
			x[*c][*y] = '*';
			x[*c][*y + 1] = '*';
			x[*c][*y + 2] = '*';
			x[*c + 1][*y] = '*';
			x[*c + 1][*y + 1] = '*';
			x[*c + 1][*y + 2] = '*';
			x[*c + 2][*y] = '*';
			x[*c + 2][*y + 2] = '*';

			*c = *c + 2;
			genera_macchina(x, c, y);
		}
		if (*key == 72 && *c > 3) {                       //freccia sù
			x[*c][*y] = '*';
			x[*c][*y + 1] = '*';
			x[*c][*y + 2] = '*';
			x[*c + 1][*y] = '*';
			x[*c + 1][*y + 1] = '*';
			x[*c + 1][*y + 2] = '*';
			x[*c + 2][*y] = '*';
			x[*c + 2][*y + 1] = '*';
			x[*c + 2][*y + 2] = '*';

			*c = *c - 2;
			genera_macchina(x, c, y);
		}
	}
}
