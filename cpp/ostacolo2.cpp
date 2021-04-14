#include "lista.h"
#include "ostacolo2.h"

lista* ostacolo2::ostacoloColpito(int y, int x, lista* e, bool& collision, int& punti) {
	lista* tmp = e;
	while (tmp != NULL) {
		if ((tmp->posx <= x + 4) && (tmp->posx >= x) && (tmp->posy >= y - 4) && (tmp->posy <= y + 2)) {
			collision = true;
			tmp->remove = true;
			punti = punti - 20;
		}
		tmp = tmp->next;
	}
	return e;
}

void ostacolo2::ins_ostacolo(char x[20][80], int posx, int posy) {
	for (k = posy; k < posy + 5; k++) {
		if (k == posy) {
			x[posx][k] = '{';
		}
		else if (k == posy + 4) {
			x[posx][k] = '}';
		}
		else {
			x[posx][k] = '=';
		}
	}
}
