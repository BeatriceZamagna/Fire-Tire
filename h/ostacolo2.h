#ifndef OSTACOLO2_H_INCLUDED
#define OSTACOLO2_H_INCLUDED
#include "ostacolo.h"

class ostacolo2 : public ostacolo {
public:
	lista* ostacoloColpito(int y, int x, lista* e, bool& collision, int& punti);
	void ins_ostacolo(char x[20][80], int posx, int posy);
};

#endif // OSTACOLO2_H_INCLUDED