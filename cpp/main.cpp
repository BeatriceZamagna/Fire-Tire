#include "strada.h"
#include "control.h"
#include <iostream>
#include <time.h>
#include "menu.h"

using namespace std;

int main() {
	bool restart;
	int punti, max = 0;
	srand(time(NULL));
	hidecursor();
	strada* s = new strada();
	do {
		stampa_titolo();
		system("cls");
		punti = s->muovi_strada();
		if (punti > max) max = punti;
		system("cls");
		restart = ricomincia(punti, max);
		system("cls");
	} while (restart == true);

}

