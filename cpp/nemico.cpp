#include "nemico.h"
#include <iostream>
#include <time.h>
#include "lista.h"

int nemico::generaPosizione(char x[20][80]) {
	k = rand() % 45 + 1;
	return k;
}

void nemico::inserisci_maccnem(char x[20][80], int c, int k) {
	if (c == 3) {
		x[0][k] = 'o';
		x[0][k + 1] = 'V';
		x[0][k + 2] = 'o';
	}
	else if (c == 2) {
		x[0][k] = '|';
		x[0][k + 1] = '8';
		x[0][k + 2] = '|';
	}
	else if (c == 1) {
		x[0][k] = 'o';
		x[0][k + 1] = '-';
		x[0][k + 2] = 'o';
	}
	else if (c == 0) {
		x[0][k] = '*';
		x[0][k + 1] = '*';
		x[0][k + 2] = '*';
	}
}

void nemico::nemicoColpito(int y, int x, struct lista* e, bool& collisionNem, int& vita) {
	lista* tmp = e;
	while (tmp != NULL) {
		if ((tmp->posx <= x + 4) && (tmp->posx >= x) && (tmp->posy >= y - 2) && (tmp->posy <= y + 2)) {
			collisionNem = true;
			tmp->remove = true;
			vita--;
		}
		tmp = tmp->next;
	}
}

