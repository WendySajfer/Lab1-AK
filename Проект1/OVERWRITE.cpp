#include "OVERWRITE.h"

void OVERWRITE::Overwrite(int** Field_state, int way) {
	system("cls"); // отчистка консоли
	for (int i = 0; i < 5; i++) {
		cout << "\n" << endl;
	}
	if (way == 2) cout << "List of commands :" << endl << "Direction (0 - down, 1 - left, 2 - up, 3 - right)" << endl << "1 - Turn left" << endl << "2 - Turn right" << endl << "11 - Step forward" << endl << "21 - Take the marker" << endl << "22 - Put the marker" << endl << "31 - Test " << endl;
	else cout << "Press the Enter." << endl;
}
void OVERWRITE::Overwrite1(int** Field_state, int* x, int* y, int* direct, int way) {
	Cursor_hide();
	Cursor(0, 0);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char symbol = ' ';
			if (j == *x && i == *y) {
				switch (*direct) {
				case 0: symbol = 'v';
					break;
				case 1: symbol = '<';
					break;
				case 2: symbol = '^';
					break;
				case 3: symbol = '>';
					break;
				default: symbol = '?';
				}
			}
			switch (Field_state[i][j]) {
			case 0:
				cout << "\x1b[47;30m" << symbol << "\x1b[0m";
				break;
			case 1:
				cout << "\x1b[42;30m" << symbol << "\x1b[0m";
				break;
			case 2:
				cout << "\x1b[41;30m" << symbol << "\x1b[0m";
				break;
			default:
				cout << "\x1b[45;30m" << symbol << "\x1b[0m";
				break;
			}
		}
		cout << "\n";
	}
	if (way == 2) {
		Cursor_view();
	}
}
void OVERWRITE::Cursor(int x1, int y1) {
	HANDLE hCon;
	COORD cPos;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE); // позиция курсора
	cPos.X = x1;
	cPos.Y = y1;
	SetConsoleCursorPosition(hCon, cPos);
}
void OVERWRITE::Cursor_hide() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(consoleHandle, &info);
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void OVERWRITE::Cursor_view() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(consoleHandle, &info);
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
