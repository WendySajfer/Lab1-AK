#pragma once
#include <iostream>

using namespace std;

class OUTPUT_PROP {
public:
	void prop(int* x, int* y, int* direct, int* markers, int** Field_state);
};

class RIGTH {
public:
	void To_the_right(int* direct);
};

class LEFT {
public:
	void To_the_left(int* direct);
};

class MOVE {
public:
	void Move(int* x, int* y, int* direct, int** Field_state);

};

class TAKE_MARKER {
public:
	void Take_marker(int* x, int* y, int* markers, int** Field_state);
};

class PUT_MARKER {
public:
	void Put_marker(int* x, int* y, int* markers, int** Field_state);
};

class TEST {
public:
	void Test(int** Field_state, int** Field_result, int* h);
};

