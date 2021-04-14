#ifndef NEMICO_H_INCLUDED
#define NEMICO_H_INCLUDED

class nemico {
private:
	int k;
public:
	int generaPosizione(char x[20][80]);
	void inserisci_maccnem(char x[20][80], int c, int k);
	void nemicoColpito(int y, int x, struct lista* e, bool& collisionNem, int& vita);
};

#endif // NEMICO_H_INCLUDED
