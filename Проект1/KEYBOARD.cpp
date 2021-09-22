#include "KEYBOARD.h"

int KEYBOARD::keyboard()
{
	int ch = -1;
	ch = _getch();
	if (_kbhit()) { // когда нажата клавиша
		cout << ch;
	}
	return ch;
}

int KEYBOARD::Inkey()
{
	int buf = 4;
	bool stop = 0;
	int i = 0;
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
			case 13: stop = 1;
				cout << endl;
				break;
			}
		}
		else if (i == 1) {
			switch (symbol_index) {
			case 49: buf = buf * 10 + 1;
				cout << '1';
				break;
			case 50: buf = buf * 10 + 2;
				cout << '2';
				break;
			case 13: stop = 1;
				cout << endl;
				break;
			}
		}
		else {
			switch (symbol_index) {
			case 13: stop = 1;
				cout << endl;
				break;
			}
		}
		i++;
	}
	return buf;
}