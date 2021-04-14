#include "strada.h"
#include "control.h"
#include "macchina.h"
#include "nemico.h"
#include "ostacolo1.h"
#include "ostacolo2.h"
#include "ostacolo3.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#include "lista.h"

using namespace std;

void strada::inserisciBarriere() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 80; j++) {
			if (j == 0)
				str[i][j] = ')';
			else if (j == 49)
				str[i][j] = '(';
			else if (j == 79)
				str[i][j] = '|';
			else if (j < 49 && j>0)
				str[i][j] = '*';
			else
				str[i][j] = '?';
		}
	}

	for (int i = 0; i < 20; i++) {
		gotoxy(0, i);
		cout << ")";
		gotoxy(49, i);
		cout << "(";
		gotoxy(79, i);
		cout << "|";
	}
}

void strada::pulisciStrada(char x[20][80]) {
	for (int i = 1; i < 49; i++) {
		for (int j = 0; j < 20; j++) {
			x[j][i] = '*';
		}
	}

}
void strada::stampa(int x, int row_m, int col_m, bool collisionOst, bool monetaPr, bool collisionNem, int liv, int vita) {
	gotoxy(55, 8);
	cout << "Points:            ";
	gotoxy(64, 8);
	cout << x;
	gotoxy(55, 9);
	cout << "Level:   ";
	gotoxy(63, 9);
	cout << liv;
	gotoxy(55, 10);
	cout << "Lives: " << endl;
	gotoxy(62, 10);
	for (int i = 0; i < 5; i++) {
		cout << "   ";
	}
	gotoxy(62, 10);
	for (int i = 0; i < vita; i++) {
		cout << "<3 ";
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 1; j < 50; j++) {

			gotoxy(j, i);
			if (str[i][j] == '*' || str[i][j] == '?') {
				cout << " ";
			}
			if ((((i == row_m && j == col_m) || (i == row_m && j == col_m + 1) || (i == row_m && j == col_m + 2))
				|| ((i == row_m + 1 && j == col_m) || (i == row_m + 1 && j == col_m + 1) || (i == row_m + 1 && j == col_m + 2))
				|| ((i == row_m + 2 && j == col_m) || (i == row_m + 2 && j == col_m + 1) || (i == row_m + 2 && j == col_m + 2)))) {
				if (collisionOst)
					setColor(4);
				else if (collisionNem)
					setColor(13);
				else if (monetaPr)
					setColor(10);
				else
					setColor(3);
				cout << str[i][j] << endl;
				setColor(15);
			}
			else {
				if (str[i][j] == '$') {
					setColor(10);
					cout << str[i][j] << endl;
					setColor(15);
				}
				else
					cout << str[i][j];
			}
		}
		cout << endl;
	}
}

int strada::muovi_strada() {
	srand(time(NULL));

	int punti = 10, posizioneNem, col = 17, row = 25, liv = 1, vita = 5, posizione;
	int r = rand() % 20 + 1, w = rand() % 15 + 1, q = rand() % 50 + 4;
	char key;
	bool collisionOst, collisionNem, monetaPr, free_row;

	inserisciBarriere();
	car->genera_macchina(str, &col, &row);

	while ((vita > 0) && (punti > 0)) {
		//Sleep(100);
		if (punti <= 100)
			liv = 1;
		else if (punti > 100 && punti <= 200)
			liv = 2;
		else if (punti > 200)
			liv = 3;
		free_row = false;
		collisionOst = false;
		collisionNem = false;
		monetaPr = false;
		if (_kbhit()) {
			key = _getch();
			car->sposta_macchina(str, &key, &col, &row, true);
		}
		if (q >= 0 && q < 4) {
			free_row = true;
			if (q == 0) {
				if (liv == 1)
					q = rand() % 50 + 4;
				else if (liv == 2)
					q = rand() % 20 + 4;
				else if (liv == 3)
					q = rand() % 10 + 4;
			}
			if (q == 3) {
				posizioneNem = nem->generaPosizione(str);
				nem->inserisci_maccnem(str, q, posizioneNem);
			}
			if (q == 1)
				maccnem = inserisci(maccnem, posizioneNem, 2, 3, false);

		}
		if (r == 0) {
			if (liv == 1)
				r = rand() % 20 + 1;
			if (liv == 2)
				r = rand() % 5 + 1;
			if (liv == 3)
				r = rand() % 2 + 1;
			if (free_row == false) {
				free_row = true;
				if (ost1->genera_ostacolo() == 1) {
					posizione = ost1->genera_posizione(str);
					lst_ost1 = inserisci(lst_ost1, posizione, 0, 3, false);
				}
				else if (ost2->genera_ostacolo() == 2) {
					posizione = ost2->genera_posizione(str);
					lst_ost2 = inserisci(lst_ost2, posizione, 0, 5, false);
				}
				else if (ost3->genera_ostacolo() == 3) {
					posizione = ost3->genera_posizione(str);
					lst_ost3 = inserisci(lst_ost3, posizione, 0, 4, false);
				}
			}
		}
		if (w == 0) {
			if (liv == 1)
				w = rand() % 15 + 1;
			if (liv == 2)
				w = rand() % 16 + 1;
			if (liv == 3)
				w = rand() % 20 + 1;
			if (free_row == false) {
				free_row = true;
				posizione = m->generaMoneta(str);
				monete = inserisci(monete, posizione, 0, 1, false);
			}
		}
		ost1->ostacoloColpito(row, col, lst_ost1, collisionOst, punti);
		ost2->ostacoloColpito(row, col, lst_ost2, collisionOst, punti);
		ost3->ostacoloColpito(row, col, lst_ost3, collisionOst, punti);

		m->monetaPresa(row, col, monete, monetaPr, punti);
		nem->nemicoColpito(row, col, maccnem, collisionNem, vita);

		lst_ost1 = rimuovi(lst_ost1, str);
		lst_ost2 = rimuovi(lst_ost2, str);
		lst_ost3 = rimuovi(lst_ost3, str);

		monete = rimuovi(monete, str);
		maccnem = rimuovi(maccnem, str);

		stampa_ost1(lst_ost1, str);
		stampa_ost2(lst_ost2, str);
		stampa_ost3(lst_ost3, str);

		stampa_monete(monete, str);
		stampa_maccnem(maccnem, str);

		stampa(punti, col, row, collisionOst, monetaPr, collisionNem, liv, vita);
		r--;
		w--;
		q--;

		aggiornaOst3(lst_ost1, str);
		aggiornaOst5(lst_ost2, str);
		aggiornaOst3(lst_ost3, str);

		aggiornaMonete(monete, str);
		aggiornaMaccnem(maccnem, str);
	}

	lst_ost1 = azzera(lst_ost1);
	lst_ost2 = azzera(lst_ost2);
	lst_ost3 = azzera(lst_ost3);

	monete = azzera(monete);
	maccnem = azzera(maccnem);

	pulisciStrada(str);
	return punti;
}
