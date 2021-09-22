#include <iostream>
#include <windows.h>
#include <conio.h>
#include "ROBOT.h"

using namespace std;

int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ROBOT robot;
	int way;
	int h = 0;
	way = robot.Start();
	robot.Begin(way);
	cin.get();
	while (h == 0) {
		int t = robot.input(way);
		robot.Work(&h, t);
	}

	robot.Finish();

	system("pause");
	return 0;
}
