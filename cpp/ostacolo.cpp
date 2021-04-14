#include "ostacolo.h"
#include <time.h>
#include <iostream>
#include "control.h"
#include "lista.h"

int ostacolo::genera_posizione(char x[20][80]) {
	k = rand() % 45 + 1;
	while (x[0][k] != '*' || x[0][k + 1] != '*' || x[0][k + 2] != '*' || x[0][k + 3] != '*' || x[0][k + 4] != '*' || x[0][k + 5] != '*') {
		k = rand() % 45 + 1;
	}
	return k;
}

int ostacolo::genera_ostacolo() {
	tipo = rand() % 3 + 1;
	return tipo;
}

void ostacolo::ostacoloColpito(int y, int x, struct lista* e, bool& collision, int& punti) {
	lista* tmp = e;
	while (tmp != NULL) {
		if ((tmp->posx <= x + 2) && (tmp->posx >= x) && (tmp->posy >= y - 2) && (tmp->posy <= y + 2)) {
			collision = true;
			tmp->remove = true;
			punti = punti - 10;
		}
		tmp = tmp->next;
	}
}
