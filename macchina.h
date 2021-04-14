#ifndef MACCHINA_H_INCLUDED
#define MACCHINA_H_INCLUDED

class macchina {
public:
	void genera_macchina(char x[20][80], int* c, int* y);
	void sposta_macchina(char x[20][80], char* key, int* c, int* y, bool b);
};

#endif // MACCHINA_H_INCLUDED
