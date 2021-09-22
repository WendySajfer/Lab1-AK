#pragma once
#include <iostream>
#include "COMMANDS.h"
#include "NEWARRAY.h"
#include "MEMORY.h"
#include "OVERWRITE.h"

using namespace std;

class COMMAND_PROCESS {
private:
	LEFT left;
	RIGTH right;
	MOVE move;
	NEWARRAY create;
	TAKE_MARKER take;
	PUT_MARKER put;
	TEST test;
	OUTPUT_PROP output;
	MEMORY memory;
	OVERWRITE over;
public:
	void Over_state(int way);
	void Over_state1(int way);
	void new_state(int way);
	void Commands(int n, int* h);
	void del_state();
};