#include "control.h"
#include "windows.h"
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO info;
void hidecursor() {
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void gotoxy(int x, int y) {
	COORD coord;     //classe di Windows.hy
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  //mette il cursore nelle coord. x e y
}
void setColor(int c) {
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
	SetConsoleTextAttribute(consoleHandle, c);
}