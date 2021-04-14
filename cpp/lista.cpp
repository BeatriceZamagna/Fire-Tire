#include "lista.h"

using namespace std;

lista* inserisci(lista* e, int posx, int posy, int length, bool remove) {
	lista* tmp = new lista;
	tmp->posx = posy;
	tmp->posy = posx;
	tmp->length = length;
	tmp->remove = remove;
	tmp->next = e;
	return tmp;
}

void stampa_ost1(lista* e, char x[20][80]) {
	lista* tmp = e;
	while (tmp->next != NULL && tmp->remove == false) {
		x[tmp->posx][tmp->posy] = '#';
		x[tmp->posx][tmp->posy + 1] = '#';
		x[tmp->posx][tmp->posy + 2] = '#';
		tmp = tmp->next;
	}
}
void stampa_ost2(lista* e, char x[20][80]) {
	lista* tmp = e;
	while (tmp->next != NULL && tmp->remove == false) {
		x[tmp->posx][tmp->posy] = '{';
		x[tmp->posx][tmp->posy + 1] = '=';
		x[tmp->posx][tmp->posy + 2] = '=';
		x[tmp->posx][tmp->posy + 3] = '=';
		x[tmp->posx][tmp->posy + 4] = '}';
		tmp = tmp->next;
	}
}
void stampa_ost3(lista* e, char x[20][80]) {
	lista* tmp = e;
	while (tmp->next != NULL && tmp->remove == false) {
		x[tmp->posx][tmp->posy] = '[';
		x[tmp->posx][tmp->posy + 1] = '@';
		x[tmp->posx][tmp->posy + 2] = ']';
		tmp = tmp->next;
	}
}
void stampa_monete(lista* e, char x[20][80]) {
	lista* tmp = e;
	while (tmp->next != NULL && tmp->remove == false) {
		x[tmp->posx][tmp->posy] = '$';
		tmp = tmp->next;
	}
}

void stampa_maccnem(struct lista* e, char x[20][80]) {
	lista* tmp = e;
	while (tmp->next != NULL && tmp->remove == false) {
		x[tmp->posx][tmp->posy] = 'o';
		x[tmp->posx][tmp->posy + 1] = 'V';
		x[tmp->posx][tmp->posy + 2] = 'o';
		x[tmp->posx - 1][tmp->posy] = '|';
		x[tmp->posx - 1][tmp->posy + 1] = '8';
		x[tmp->posx - 1][tmp->posy + 2] = '|';
		x[tmp->posx - 2][tmp->posy] = 'o';
		x[tmp->posx - 2][tmp->posy + 1] = '-';
		x[tmp->posx - 2][tmp->posy + 2] = 'o';
		tmp = tmp->next;
	}
}
lista* rimuovi(lista* e, char x[20][80]) {
	lista* tmp = e, * prec = NULL;
	while (tmp->next != NULL) {
		if (tmp->remove == true) {
			if (prec == NULL) {
				e = e->next;
				delete(tmp);
				tmp = e;
			}
			else {
				if (tmp->next != NULL) {
					prec->next = tmp->next;
					delete(tmp);
					tmp = prec->next;
				}
				else {
					delete(tmp);
					prec->next = NULL;
				}

			}
		}
		else {
			prec = tmp;
			tmp = tmp->next;
		}
	}
	return e;
}
void aggiornaOst3(lista* e, char x[20][80]) {
	lista* tmp = e, * prec = NULL;
	while (tmp->next != NULL) {
		if (tmp->posx == 20)
			tmp->remove = true;
		else {
			tmp->posx = tmp->posx + 1;
			x[tmp->posx - 1][tmp->posy] = '*';
			x[tmp->posx - 1][tmp->posy + 1] = '*';
			x[tmp->posx - 1][tmp->posy + 2] = '*';
		}
		tmp = tmp->next;
	}
}
void aggiornaOst5(lista* e, char x[20][80]) {
	lista* tmp = e, * prec = NULL;
	while (tmp->next != NULL) {
		if (tmp->posx == 20)
			tmp->remove = true;
		else {
			tmp->posx = tmp->posx + 1;
			x[tmp->posx - 1][tmp->posy] = '*';
			x[tmp->posx - 1][tmp->posy + 1] = '*';
			x[tmp->posx - 1][tmp->posy + 2] = '*';
			x[tmp->posx - 1][tmp->posy + 3] = '*';
			x[tmp->posx - 1][tmp->posy + 4] = '*';
		}
		tmp = tmp->next;
	}
}
void aggiornaMonete(lista* e, char x[20][80]) {
	lista* tmp = e, * prec = NULL;
	while (tmp->next != NULL) {
		if (tmp->posx == 20)
			tmp->remove = true;
		else {
			tmp->posx = tmp->posx + 1;
			x[tmp->posx - 1][tmp->posy] = '*';
		}
		tmp = tmp->next;
	}
}
void aggiornaMaccnem(lista* e, char x[20][80]) {
	lista* tmp = e, * prec = NULL;
	while (tmp->next != NULL) {
		if (tmp->posx == 22)
			tmp->remove = true;
		else {
			tmp->posx = tmp->posx + 1;
			x[tmp->posx - 1][tmp->posy] = '*';
			x[tmp->posx - 1][tmp->posy + 1] = '*';
			x[tmp->posx - 1][tmp->posy + 2] = '*';
			x[tmp->posx - 2][tmp->posy] = '*';
			x[tmp->posx - 2][tmp->posy + 1] = '*';
			x[tmp->posx - 2][tmp->posy + 2] = '*';
			x[tmp->posx - 3][tmp->posy] = '*';
			x[tmp->posx - 3][tmp->posy + 1] = '*';
			x[tmp->posx - 3][tmp->posy + 2] = '*';
		}
		tmp = tmp->next;
	}
}

struct lista* azzera(lista* e) {
	lista* tmp = e;
	while (tmp->next != NULL) {
		e = e->next;
		delete(tmp);
		tmp = e;
	}
	return e;
}

