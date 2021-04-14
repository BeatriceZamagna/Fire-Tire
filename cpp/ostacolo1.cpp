#include "ostacolo1.h"

void ostacolo1::ins_ostacolo(char x[20][80], int posx, int posy) {
	for (k = posy; k < posy + 3; k++) {
		x[posx][k] = '#';
	}
}
