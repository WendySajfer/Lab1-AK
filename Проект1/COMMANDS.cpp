#include "COMMANDS.h"

void OUTPUT_PROP::prop(int* x, int* y, int* direct, int* markers, int** Field_state)
{
	cout << "Coordinates (" << *x << ";" << *y << "); Direction: " << *direct << "; Markers: " << *markers << "; Coordinate state: " << Field_state[*y][*x] << "." << endl;
}

void RIGTH::To_the_right(int* direct)
{
	if (*direct != 3) (*direct)++;
	else *direct = 0;
	cout << "Command completed." << endl;
}

void LEFT::To_the_left(int* direct)
{
	if (*direct != 0) (*direct)--;
	else *direct = 3;
	cout << "Command completed." << endl;
}

void MOVE::Move(int* x, int* y, int* direct, int** Field_state)
{
	int buf_x = *x;
	int buf_y = *y;
	switch (*direct) {
	case 0:
		buf_y++;
		break;
	case 1:
		buf_x--;
		break;
	case 2:
		buf_y--;
		break;
	case 3:
		buf_x++;
		break;
	default:
		cout << "Unknown direction." << endl;
	}
	if (buf_x < 0 || buf_x > 9 || buf_y < 0 || buf_y > 9) {
		cout << "Can't go outside the field." << endl;
		return;
	}
	else if (Field_state[buf_y][buf_x] == 2) {
		cout << ("Impossible, an obstacle in the way.") << endl;
		return;
	}
	else {
		*x = buf_x;
		*y = buf_y;
		cout << "Command completed." << endl;
	}
}

void TAKE_MARKER::Take_marker(int* x, int* y, int* markers, int** Field_state)
{
	if (Field_state[*y][*x] != 1) {
		cout << "There is no marker here." << endl;
		return;
	}
	else {
		(*markers)++;
		Field_state[*y][*x] = 0;
		cout << "Command completed." << endl;
	}
}

void PUT_MARKER::Put_marker(int* x, int* y, int* markers, int** Field_state)
{
	if (*markers == 0) {
		cout << "The robot has no markers." << endl;
		return;
	}
	else if (Field_state[*y][*x] != 0) {
		cout << "There is already a marker here." << endl;
		return;
	}
	else {
		Field_state[*y][*x] = 1;
		(*markers)--;
		cout << "Command completed." << endl;
	}
}

void TEST::Test(int** Field_state, int** Field_result, int* h)
{
	bool F = true;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (Field_state[i][j] != Field_result[i][j]) F = false;
		}
	}
	if (F) {
		cout << "\x1b[32mCongratulations! Result achieved.\x1b[0m" << endl;
		(*h)++;
	}
	else cout << "\x1b[31mThe result is not correct.\x1b[0m" << endl;
}
