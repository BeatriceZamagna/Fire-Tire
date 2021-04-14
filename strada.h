#ifndef STRADA_H_INCLUDED
#define STRADA_H_INCLUDED
#include "ostacolo1.h"
#include "ostacolo2.h"
#include "ostacolo3.h"
#include "moneta.h"
#include "nemico.h"
#include "macchina.h"
#include "lista.h"

class strada {
private:
	ostacolo1* ost1 = new ostacolo1;
	ostacolo2* ost2 = new ostacolo2;
	ostacolo3* ost3 = new ostacolo3;

	moneta* m = new moneta;
	nemico* nem = new nemico;
	macchina* car = new macchina;

	lista* lst_ost1 = new lista;
	lista* lst_ost2 = new lista;
	lista* lst_ost3 = new lista;

	lista* monete = new lista;
	lista* maccnem = new lista;

	char str[20][80];

public:
	void inserisciBarriere();
	void stampa(int x, int row_m, int col_m, bool collisionOst, bool monetaPr, bool collisionNem, int liv, int vite);
	void pulisciStrada(char x[20][80]);
	int muovi_strada();
};

#endif // STRADA_H_INCLUDED
