#include <windows.h>
#include <iostream>
#include <fstream>

using namespace std;

class ROBOT {
public:
	int Field_state[10][10]; // состояние поля
	int x; // координата по горизонтали
	int y; // координата по вертикали
	int direct; // направление (0 - вправо, 1 - вниз, 2 - вправо, 3 - вверх)
	
};

int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ROBOT robot;
	robot.x = 0;
	robot.y = 0;
	robot.direct = 0;
	
	//Создаем файловый поток и связываем его с файлом
	ifstream in("input.txt");
	ofstream out("output.txt");

	if (in.is_open() && out.is_open())
	{
		//Если открытие файла прошло успешно

		//Вначале посчитаем сколько чисел в файле
		int count = 0;// число чисел в файле
		int temp;//Временная переменная

		while (!in.eof())// пробегаем пока не встретим конец файла eof
		{
			in >> temp;
			count++;
		}
		//посчитаем число пробелов до знака перевода на новую строку 

		//Вначале переведем каретку в потоке в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//Число пробелов в первой строчке вначале равно 0
		int count_space = 0;
		char symbol;
		while (!in.eof())//на всякий случай цикл ограничиваем концом файла
		{
			//теперь нам нужно считывать не числа, а посимвольно считывать данные
			in.get(symbol);//считали текущий символ
			if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
			if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
		}

		//Опять переходим в потоке в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		if (count == 100 && count_space == 9) {
			//Считаем матрицу из файла
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					in >> robot.Field_state[i][j];
		}


		//Выведем матрицу
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				out << robot.Field_state[i][j] << " ";
			}
			if (i != 9) {
				out << "\n";
			}
		}


		in.close();//под конец закроем файла
		out.close();
	}
	else
	{
		//Если открытие файла прошло не успешно
		cout << "Files not found.";
	}
	system("pause");
	return 0;
}