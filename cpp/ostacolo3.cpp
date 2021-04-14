#include "ostacolo3.h"

void ostacolo3::ins_ostacolo(char x[20][80], int posx, int posy) {
	for (k = posy; k < posy + 3; k++) {
		if (k == posy) {
			x[posx][k] = '[';
		}
		else if (k == posy + 2) {
			x[posx][k] = ']';
		}
		else {
			x[posx][k] = '@';
		}
	}
}
