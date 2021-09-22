#include "NEWARRAY.h"

void NEWARRAY::inArray(int** Field_state) {
	for (int i = 0; i < 10; i++) {
		Field_state[i] = new int[10];
	}
}
void NEWARRAY::Arrayfull(int** Field_state, bool File) {
	//������� �������� ����� � ��������� ��� � ������
	string str;
	if (File == 0) str = "input.txt";
	else str = "result.txt";
	ifstream in(str);

	if (in.is_open())
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
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					in >> Field_state[i][j];
		}
		in.close();//��� ����� ������� �����
	}
	else
	{
		//���� �������� ����� ������ �� �������
		cout << "Files not found.";
	}
}
void NEWARRAY::Out_Array(int** Field_state) {
	ofstream out("output.txt");
	//������� �������
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
		//���� �������� ����� ������ �� �������
		cout << "Files not found.";
	}
}
void NEWARRAY::DestructorArray(int** Field_state) {
	for (int i = 0; i < 10; i++) {
		delete[] Field_state[i];
	}
	delete[] Field_state;
}
