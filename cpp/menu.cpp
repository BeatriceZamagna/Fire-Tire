#include "menu.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void stampa_titolo() {
	cout << endl << endl;
	cout << "++++++++     +++     ++++++++     ++++++++        ++++++++     +++     ++++++++     ++++++++" << endl;
	cout << "++++++++     +++     ++++++++     ++++++++        ++++++++     +++     ++++++++     ++++++++" << endl;
	cout << "+++          +++     +++   ++     +++                +++       +++     +++   ++     +++" << endl;
	cout << "++++++++     +++     ++++++++     ++++++++           +++       +++     ++++++++     ++++++++" << endl;
	cout << "++++++++     +++     +++ ++       ++++++++           +++       +++     +++ ++       ++++++++" << endl;
	cout << "+++          +++     +++  ++      +++                +++       +++     +++  ++      +++" << endl;
	cout << "+++          +++     +++   ++     ++++++++           +++       +++     +++   ++     ++++++++" << endl;
	cout << "+++          +++     +++    ++    ++++++++           +++       +++     +++    ++    ++++++++" << endl << endl;
	cout << "\t \t \t \t  DRIVE TO SURVIVE" << endl << endl;
	cout << "\t \t \t       Press any key to start" << endl;
	while (!_kbhit()) {}
	char m = _getch();
}

bool ricomincia(int punti, int max) {
	char m;
	cout << endl << endl;
	cout << "\t \t YOU LOOSE" << endl << endl;
	cout << "Points: " << punti << endl;
	cout << "Your record is: " << max << endl << endl;
	cout << "If you want to restart press any key, else press 1" << endl;
	Sleep(100);
	while (!_kbhit()) {}
	m = _getch();
	if (m == '1')
		return false;
	else
		return true;
}