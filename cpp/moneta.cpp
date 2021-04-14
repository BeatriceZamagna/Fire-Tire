#include "moneta.h"
#include "lista.h"
#include <time.h>
#include <iostream>

int moneta::generaMoneta(char x[20][80]) {
	k = rand() % 45 + 1;
	while (x[0][k] != '*') {
		k = rand() % 45 + 1;
	}
	x[0][k] = '$';
	return k;
}

void moneta::monetaPresa(int y, int x, struct lista* e, bool& monetaPr, int& punti) {
	bool presa = false;
	lista* tmp = e;
	while (tmp != NULL) {
		if ((tmp->posx <= x + 2) && (tmp->posx >= x) && (tmp->posy >= y) && (tmp->posy <= y + 2)) {
			monetaPr = true;
			tmp->remove = true;
			punti = punti + 10;
		}
		tmp = tmp->next;
	}
}
