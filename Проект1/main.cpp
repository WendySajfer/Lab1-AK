#include <windows.h>
#include <iostream>
#include <fstream>

using namespace std;

class ROBOT {
public:
	int Field_state[10][10]; // ��������� ����
	int x; // ���������� �� �����������
	int y; // ���������� �� ���������
	int direct; // ����������� (0 - ������, 1 - ����, 2 - ������, 3 - �����)
	
};

int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ROBOT robot;
	robot.x = 0;
	robot.y = 0;
	robot.direct = 0;
	
	//������� �������� ����� � ��������� ��� � ������
	ifstream in("input.txt");
	ofstream out("output.txt");

	if (in.is_open() && out.is_open())
	{
		//���� �������� ����� ������ �������

		//������� ��������� ������� ����� � �����
		int count = 0;// ����� ����� � �����
		int temp;//��������� ����������

		while (!in.eof())// ��������� ���� �� �������� ����� ����� eof
		{
			in >> temp;
			count++;
		}
		//��������� ����� �������� �� ����� �������� �� ����� ������ 

		//������� ��������� ������� � ������ � ������ �����
		in.seekg(0, ios::beg);
		in.clear();

		//����� �������� � ������ ������� ������� ����� 0
		int count_space = 0;
		char symbol;
		while (!in.eof())//�� ������ ������ ���� ������������ ������ �����
		{
			//������ ��� ����� ��������� �� �����, � ����������� ��������� ������
			in.get(symbol);//������� ������� ������
			if (symbol == ' ') count_space++;//���� ��� ������, �� ����� �������� �����������
			if (symbol == '\n') break;//���� ����� �� ����� ������, �� ������� �� �����
		}

		//����� ��������� � ������ � ������ �����
		in.seekg(0, ios::beg);
		in.clear();

		if (count == 100 && count_space == 9) {
			//������� ������� �� �����
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					in >> robot.Field_state[i][j];
		}


		//������� �������
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				out << robot.Field_state[i][j] << " ";
			}
			if (i != 9) {
				out << "\n";
			}
		}


		in.close();//��� ����� ������� �����
		out.close();
	}
	else
	{
		//���� �������� ����� ������ �� �������
		cout << "Files not found.";
	}
	system("pause");
	return 0;
}