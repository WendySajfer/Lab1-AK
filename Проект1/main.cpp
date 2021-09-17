#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

class MEMORY {
private:
	int** Field_state = new int*[10]; // состояние поля
	int** Field_result = new int*[10];
	int x = 0; // координата по горизонтали
	int y = 0; // координата по вертикали
	int direct = 0; // направление (0 - вниз, 1 - влево, 2 - вверх, 3 - вправо)
	int markers = 0;
	int Commands[206] = { 11,21,1,1,11,2,11,11,11,21,2,2,11,1,11,11,11,2,11,11,1,11,21,2,2,11,2,11,11,2,11,11,1,11,2,11,11,2,11,11,11,2,11,21,2,2,11,11,11,1,11,21,1,1,11,2,11,11,2,11,11,11,2,11,11,1,11,21,1,1,11,2,11,11,2,11,11,1,11,2,11,11,2,11,11,11,2,11,21,2,2,11,11,11,1,11,21,1,1,11,2,11,11,2,11,11,11,2,11,11,1,11,21,1,1,11,2,11,11,2,11,11,1,11,2,11,11,11,11,1,11,21,1,1,11,2,11,11,1,11,11,11,2,11,21,1,1,11,11,11,1,11,21,1,1,11,2,11,11,2,11,11,11,11,22,11,1,11,22,2,11,22,11,1,11,22,11,1,11,22,2,11,22,11,1,11,22,11,1,11,22,2,11,22,11,1,11,22,11,1,11,22,2,11,22,31 };
	int k = -1;
public:
	int get_Commands() {
		k++;
		return Commands[k];
	}
	int* get_x() {
		return &x;
	}
	int* get_y() {
		return &y;
	}
	int* get_direct() {
		return &direct;
	}
	int* get_markers() {
		return &markers;
	}
	int** get_Field_state() {
		return Field_state;
	}
	int** get_Field_result() {
		return Field_result;
	}
};

class OUTPUT_PROP {
public:
	void prop(int* x, int* y, int* direct, int *markers, int** Field_state) {
		cout << "Command completed. Coordinates (" << *x << ";" << *y << "); Direction: " << *direct << "; Markers: " << *markers << "; Coordinate state: " << Field_state[*y][*x] << "." << endl;
	}
};

class RIGTH {
public:
	void To_the_right(int *direct) {
		if (*direct != 3) (*direct)++;
		else *direct = 0;
		cout << "Command completed." << endl;
	}
};

class LEFT {
public:
	void To_the_left(int *direct) {
		if (*direct != 0) (*direct)--;
		else *direct = 3;
		cout << "Command completed." << endl;
	}
};

class MOVE{
public:
	void Move(int *x, int *y, int* direct, int **Field_state) {
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

};

class NEWARRAY {
public:
	void inArray(int **Field_state) {
		for (int i = 0; i < 10;i++) {
			Field_state[i] = new int[10];
		}
	}
	void Arrayfull(int **Field_state, bool File) {
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
	void Overwrite(int **Field_state) {
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
	void DestructorArray(int** Field_state){
		for (int i = 0; i < 10; i++) {
			delete[] Field_state[i];
		}
		delete[] Field_state;
	}
};

class TAKE_MARKER {
public:
	void Take_marker(int* x, int* y, int* markers, int** Field_state) {
		if (Field_state[*y][*x] != 1) {
			cout << "There is no marker here." << endl;
			return;
		}
		else {
			markers++;
			Field_state[*y][*x] = 0;
			cout << "Command completed." << endl;
		}
	}
};

class PUT_MARKER {
public:
	void Put_marker(int* x, int* y, int* markers, int** Field_state) {
		if (markers == 0) {
			cout << "The robot has no markers." << endl;
			return;
		}
		else if (Field_state[*y][*x] != 0) {
			cout << "There is already a marker here." << endl;
			return;
		}
		else {
			Field_state[*y][*x] = 1;
			markers--;
			cout << "Command completed." << endl;
		}
	}
};

class TEST {
public:
	void Test(int** Field_state,int** Field_result) {
		bool F = true;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (Field_state[i][j] != Field_result[i][j]) F = false;
			}
		}
		if (F) {
			cout << "Congratulations! Result achieved." << endl;
		}
		else cout << "The result is not correct." << endl;
	}
};

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
public:
	void new_state() {
		cout << "Start." << endl;
		create.inArray(memory.get_Field_state());
		create.Arrayfull(memory.get_Field_state(), 0);
		create.Overwrite(memory.get_Field_state());
		create.inArray(memory.get_Field_result());
		create.Arrayfull(memory.get_Field_result(), 1);
		create.Overwrite(memory.get_Field_result());
		output.prop(memory.get_x(), memory.get_y(), memory.get_direct(), memory.get_markers(), memory.get_Field_state());
		cout << "Welcome to Robot Marker! I present to you a list of commands :" << endl << "Direction (0 - down, 1 - left, 2 - up, 3 - right)" << endl << "1 - Turn left" << endl << "2 - Turn right" << endl << "11 - Step forward" << endl << "21 - Take the marker" << endl << "22 - Put the marker" << endl << "31 - Test " << endl;
	}
	void Commands(int n) {
		switch (n) {
		case 1:
			cout << "Command is executed to the left." << endl;
			left.To_the_left(memory.get_direct());
			break;
		case 2:
			cout << "Command is executed to the right." << endl;
			right.To_the_right(memory.get_direct());
			break;
		case 11:
			cout << "Command is executed step forward." << endl;
			move.Move(memory.get_x(), memory.get_y(), memory.get_direct(), memory.get_Field_state());
			break;
		case 21:
			cout << "Command is executed to take the marker." << endl;
			take.Take_marker(memory.get_x(), memory.get_y(), memory.get_markers(), memory.get_Field_state());
			create.Overwrite(memory.get_Field_state());
			break;
		case 22:
			cout << "Command is executedto put the marker." << endl;
			put.Put_marker(memory.get_x(), memory.get_y(), memory.get_markers(), memory.get_Field_state());
			create.Overwrite(memory.get_Field_state());
			break;
		case 31:
			cout << "Command is executed to test." << endl;
			test.Test(memory.get_Field_state(), memory.get_Field_result());
			break;
		default:
			cout << "Unknown command." << endl;
		}
		output.prop(memory.get_x(), memory.get_y(), memory.get_direct(), memory.get_markers(), memory.get_Field_state());
	}
	void del_state() {
		create.DestructorArray(memory.get_Field_state());
		create.DestructorArray(memory.get_Field_result());
	}
};
class ROBOT {
private:
	MEMORY memory;
	COMMAND_PROCESS pro;
public:
	void Begin() {
		pro.new_state();
	}
	void Work(int n) {
		if (n == 0) pro.Commands(memory.get_Commands());
		else pro.Commands(n);
	}
	void Finish() {
		pro.del_state();
	}
};


int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ROBOT robot;
	robot.Begin();

	for (int i = 0; i < 206; i++) {
		int t = 0;
		//t = getch();// как вводить
		cin.get();
		robot.Work(t);
	}
	robot.Finish();
	return 0;
}
