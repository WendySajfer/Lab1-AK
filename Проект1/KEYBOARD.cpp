#include "KEYBOARD.h"

int KEYBOARD::keyboard()
{
	int ch = -1;
	ch = _getch();
	return ch;
}

int KEYBOARD::Inkey()
{
	int buf = 4;
	bool stop = 0;
	int i = 0;
	int buf1;
	int symbol_index;
	while (!stop) {
		symbol_index = keyboard();
		if (i == 0) {
			switch (symbol_index) {
			case 49: buf = 1;
				cout << '1';
				break;
			case 50: buf = 2;
				cout << '2';
				break;
			case 51: buf = 3;
				cout << '3';
				break;
			default:
				i--;
			}
			i++;
		}
		else if (i == 1) {
			switch (symbol_index) {
			case 49: buf1 = buf * 10 + 1;
				cout << '1';
				break;
			case 50: buf1 = buf * 10 + 2;
				cout << '2';
				break;
			case 13: stop = 1;
				cout << endl;
				break;
			case 8: over.Cursor(0, 18);
				cout << ' ';
				over.Cursor(0, 18);
				i--;
				break;
			default:
				i--;
			}
			i++;
		}
		else {
			switch (symbol_index) {
			case 13: stop = 1;
				cout << endl;
				i++;
				break;
			case 8: over.Cursor(1, 18);
				cout << ' ';
				over.Cursor(1, 18);
				buf1 = buf;
				i--;
				break;
			}
		}
	}
	if (i != 2) {
		buf = buf1;
	}
	return buf;
}