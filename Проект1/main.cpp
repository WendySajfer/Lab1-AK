#include <windows.h>
#include <iostream>
#include <fstream>

using namespace std;

class ROBOT {
public:
	int Field_state[10][10]; // состояние поля
	int x; // координата по горизонтали
	int y; // координата по вертикали
	int direct; // направление (0 - вниз, 1 - влево, 2 - вверх, 3 - вправо)
	int markers;
	
	void To_the_left(){
		if(direct!=3) direct++;
		else direct = 0;
		cout << "Command completed. Coordinates (" << x << ";" << y << "); Direction: " << direct << "; Markers: " << markers << "; Coordinate state: " << Field_state[x][y] << "." << endl;
	}
	void To_the_right(){
		if(direct!=0) direct--;
		else direct = 3;
		cout << "Command completed. Coordinates (" << x << ";" << y << "); Direction: " << direct << "; Markers: " << markers << "; Coordinate state: " << Field_state[x][y] << "." << endl;
	}
	void Move(){
		int buf_x = x;
		int buf_y = y;
		Switch(direct){
			case 0:
			buf_y ++;
			break;
			case 1:
			buf_x --;
			break;
			case 2:
			buf_y --;
			break;
			case 3:
			buf_x ++;
			break;
			default:
			cout << "Unknown direction." << endl;
		}
		if (buf_x < 0 || buf_x > 9 || buf_y < 0 || buf_y > 9) {
			cout << "Can't go outside the field." << endl;
			break;
		}
		else if (Field_state[buf_x][buf_y] == 2){
			cout ("Impossible, an obstacle in the way.") << endl;
			break;
		     }
		     else {
			     x = buf_x;
			     y = buf_y;
			     cout << "Command completed. Coordinates (" << x << ";" << y << "); Direction: " << direct << "; Markers: " << markers << "; Coordinate state: " << Field_state[x][y] << "." << endl;
		     }
	}
	void Take_marker(){
		if (Field_state[x][y] != 1){
			cout << "There is no marker here." << endl;
			break;
		}
		else {
			markers++;
			Field_state[x][y] = 0;
			cout << "Command completed. Coordinates (" << x << ";" << y << "); Direction: " << direct << "; Markers: " << markers << "; Coordinate state: " << Field_state[x][y] << "." << endl;
		}
	}
	void Put_marker(){
		if(markers == 0){
			cout << "The robot has no markers." << endl;
			break;
		}
		else if(Field_state[x][y] != 0){
			cout << "There is already a marker here." << endl;
			break;
		}
		else {
			Field_state[x][y] = 1;
			markers--;
			cout << "Command completed. Coordinates (" << x << ";" << y << "); Direction: " << direct << "; Markers: " << markers << "; Coordinate state: " << Field_state[x][y] << "." << endl;
		}
	}
	void Command(int n){
		Switch(n){
			case 1:
			To_the_left();
			break;
			case 2:
			To_the_right();
			break;
			case 11:
			Move();
			break;
			case 21:
			Take_marker();
			break;
			case 21:
			Put_marker();
			break;
			default:
			cout << "Unknown command." << endl;
		}
		}
	}
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
