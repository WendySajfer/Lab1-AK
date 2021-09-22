#include "NEWARRAY.h"

void NEWARRAY::inArray(int** Field_state) {
	for (int i = 0; i < 10; i++) {
		Field_state[i] = new int[10];
	}
}
void NEWARRAY::Arrayfull(int** Field_state, bool File) {
	//Создаем файловый поток и связываем его с файлом
	string str;
	if (File == 0) str = "input.txt";
	else str = "result.txt";
	ifstream in(str);

	if (in.is_open())
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
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					in >> Field_state[i][j];
		}
		in.close();//под конец закроем файла
	}
	else
	{
		//Если открытие файла прошло не успешно
		cout << "Files not found.";
	}
}
void NEWARRAY::Out_Array(int** Field_state) {
	ofstream out("output.txt");
	//Выведем матрицу
	if (out.is_open()) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				out << Field_state[i][j] << " ";
			}
			if (i != 9) {
				out << "\n";
			}
		}
		out.close();
	}
	else
	{
		//Если открытие файла прошло не успешно
		cout << "Files not found.";
	}
}
void NEWARRAY::DestructorArray(int** Field_state) {
	for (int i = 0; i < 10; i++) {
		delete[] Field_state[i];
	}
	delete[] Field_state;
}
