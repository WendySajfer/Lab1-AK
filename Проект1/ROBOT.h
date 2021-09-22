#pragma once
#include <iostream>
#include "COMMAND_PROCESS.h"
#include "MEMORY.h"
#include "OVERWRITE.h"
#include "KEYBOARD.h"

using namespace std;

class ROBOT {
private:
	MEMORY memory;
	KEYBOARD key;
	COMMAND_PROCESS pro;
	OVERWRITE over;
public:
	int Start();
	void Begin(int way);
	int input(int way);
	void Work(int* h, int n);
	void Finish();
};

