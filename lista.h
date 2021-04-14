#include <cstddef>
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct lista {
	int posx, posy, length;
	bool remove;
	lista* next = NULL;
};

lista* inserisci(lista* e, int posx, int posy, int length, bool remove);

void stampa_ost1(lista* e, char x[20][80]);
void stampa_ost2(lista* e, char x[20][80]);
void stampa_ost3(lista* e, char x[20][80]);
void stampa_monete(lista* e, char x[20][80]);
void stampa_maccnem(lista* e, char x[20][80]);

lista* rimuovi(lista* e, char x[20][80]);

void aggiornaOst3(lista* e, char x[20][80]);
void aggiornaOst5(lista* e, char x[20][80]);
void aggiornaMonete(lista* e, char x[20][80]);
void aggiornaMaccnem(lista* e, char x[20][80]);

lista* azzera(lista* e);

#endif // LISTA_H_INCLUDED

