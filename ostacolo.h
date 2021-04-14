#ifndef OSTACOLO_H_INCLUDED
#define OSTACOLO_H_INCLUDED

class ostacolo {
protected:
	int tipo;
	int k;
public:
	int genera_posizione(char x[20][80]);
	int genera_ostacolo();
	void ostacoloColpito(int y, int x, struct lista* e, bool& collision, int& punti);
};


#endif // OSTACOLO_H_INCLUDED
