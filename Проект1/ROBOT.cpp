#include "ROBOT.h"

int ROBOT::Start() {
	int f;
	cout << "Welcome to Robot Marker!" << endl << "1.Auto process" << endl << "2.Manual work" << endl;
	cin >> f;
	if (f == 1) {
		over.Cursor_hide();
	}
	return f;
}
void ROBOT::Begin(int way) {
	pro.new_state(way);
	pro.Over_state1(way);
}
int ROBOT::input(int way) {
	int key_n = 0;
	int ch = 0;

	if (way == 2) {
		over.Cursor(0, 18);
		key_n = key.Inkey();
	}
	else {
		do {
			ch = _getch();
		} while (ch != 13);
	}

	pro.Over_state(way);

	if (way == 2) {
		cout << endl;
	}
	return key_n;
}
void ROBOT::Work(int* h, int n) {
	if (n == 0) {
		pro.Commands(memory.get_Commands(), h);
		pro.Over_state1(1);
	}
	else {
		pro.Commands(n, h);
		pro.Over_state1(2);
	}
}
void ROBOT::Finish() {
	pro.del_state();
}
