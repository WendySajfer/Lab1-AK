#pragma once
#include <iostream>
#include <Windows.h>	

using namespace std;

class OVERWRITE {
public:
	void Overwrite(int** Field_state, int way);
	void Overwrite1(int** Field_state, int* x, int* y, int* direct, int way);
	void Cursor(int x1, int y1);
	void Cursor_hide();
	void Cursor_view();
};
