#pragma once
#include <iostream>
#include <conio.h>
#include "OVERWRITE.h"

using namespace std;

class KEYBOARD {
private:
	OVERWRITE over;
	int keyboard();
public:
	int Inkey();
};

