#ifndef MONETA_H_INCLUDED
#define MONETA_H_INCLUDED

class moneta {
private:
	int k;
public:
	int generaMoneta(char x[20][80]);
	void monetaPresa(int y, int x, struct lista* e, bool& collision, int& punti);
};

#endif // MONETA_H_INCLUDED
