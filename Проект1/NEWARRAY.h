#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class NEWARRAY {
public:
	void inArray(int** Field_state);
	void Arrayfull(int** Field_state, bool File);
	void Out_Array(int** Field_state);
	void DestructorArray(int** Field_state);
};

