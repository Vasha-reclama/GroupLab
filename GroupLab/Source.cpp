#include<iostream>
#include<ctime>
#include"RusRails.h"
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	Station s; //������ ����������� �������
	s.addStation((char*)"Moscow"); //0
	s.addStation((char*)"Vnukovo"); //1
	s.addStation((char*)"Domodedovo�"); //2

	// ������� ������� � ���������
	s.addAdjacentStation(0, (char*)"Kazan", 322);
	s.addAdjacentStation(0, (char*)"Velikiy Novgorod", 994);
	s.addAdjacentStation(0, (char*)"Suzdal", 260);
	s.addAdjacentStation(0, (char*)"Rostov", 1050);
	s.addAdjacentStation(0, (char*)"Novosibirsk", 2414);

	s.addAdjacentStation(1, (char*)"Sochy", 1813);
	s.addAdjacentStation(1, (char*)"Orel", 791);
	s.addAdjacentStation(1, (char*)"Perm", 760);

	s.addAdjacentStation(2, (char*)"Nizhny Novgorod", 100);
	s.addAdjacentStation(2, (char*)"Ekaterinburg", 1016);


	string password;
	cout << "Enter password: ";
	cin >> password;

	if (password == "admin") {
		// Admin �������, ����������, ��������, ��������������, �����, �����
		//���������������� �������, ������ ����� ������� , ����� �� �����
		//������������ �� ����� ��� ���������, ������� � ������������� �������(�.�. � ���� ��� ����)
		int n = 0;
		string k = " ";
		int stop = 0;
		while (stop != 1) {
			char key;
			string input;
			bool valid_input = false;
			while (!valid_input) {
				cout << "1- search station, 2- print ALL station, 3 - edit station, 4 - add station, 5 - add Adjacent station, 6 - remove station, 7 - remove Adjacent station, 8 - exit" << endl;
				cin >> input;
				if (input.length() == 1 && isdigit(input[0]) && input[0] >= '1' && input[0] <= '8') {
					valid_input = true;
				}
				else {
					cout << "������! ������� ����� �� 1 �� 8" << endl;
				}
			}
			char* name = nullptr;
			char* newname = nullptr;
			int stationId = 0;
			int distance = 0;
			int adjacentId = 0;
			key = input[0];
			switch (key) {
			case'1':
				cout << "������� ������ �������: " << endl;
				if (name == nullptr) {
					name = new char[100]; 
				}
				cin >> name;
				s.findStation((char*)name);
				break;
			case'2':
				s.printALLStation();
				break;
			case'3':
				cout << "������� ������ �������: " << endl;
				if (name == nullptr) {
					name = new char[100]; 
				}
				cin >> name;
				s.findStation((char*)name);
				//���� �� �������� �������������� �������, ������ �����))...
				break;
			case '4':
				cout << "������� ��� ��� ����� �������: " << endl;
				if (name == nullptr) {
					name = new char[100]; 
				}
				cin >> name;
				s.addStation((char*)name);
				break;
			case '5':
				if (name == nullptr) {
					name = new char[100]; 
				}
				cout << "������� ID �������� �������: " << endl;
				cin >> stationId;
				cout << "������� ��� ����� ������� �������: " << endl;
				cin >> name;
				cout << "������� ��������� �� ����� ������� �������: " << endl;
				cin >> distance;
				s.addAdjacentStation(stationId, (char*)name, distance);
				break;
			case '6':
				cout << "������� ID �������: " << endl;
				cin >> stationId;
				s.removeStation(stationId);
				break;
			case '7':
				cout << "������� ID �������� �������: " << endl;
				cin >> stationId;
				cout << "������� ID ������� �������: " << endl;
				cin >> adjacentId;
				s.removeAdjacentStation(stationId, adjacentId);
				break;
			case '8':
				return 0;
				break;

			}
		}

	}
	else {
		//���������������� �������, ������ ����� ������� , ����� �� �����
		//������������ �� ����� ��� ���������, ������� � ������������� �������(�.�. � ���� ��� ����)
		int n = 0;
		string k = " ";
		int stop = 0;
		while (stop != 1) {
			char key;
			string input;
			bool valid_input = false;
			while (!valid_input) {
				cout << "1- search station, 2- print ALL station, 3 - exit" << endl;
				cin >> input;
				if (input.length() == 1 && isdigit(input[0]) && input[0] >= '1' && input[0] <= '3') {
					valid_input = true;
				}
				else {
					cout << "������! ������� ����� �� 1 �� 3" << endl;
				}
			}
			char* name = nullptr;
			key = input[0];
			switch (key) {
			case'1':
				cout << "������� ������ �������: " << endl;
				if (name == nullptr) {
					name = new char[100]; // �������� ������ ������ ���� name ����� nullptr
				}
				cin >> name;
				s.findStation((char*)name);
				break;
			case'2':
				s.printALLStation();
				break;
			case'3':
				return 0;

			}
		}
	}

	//������
	//Station* s_new = s.getStation(1); // ������� ������
	//Station* s_new_adj = s.getAdjacentStations(1, 1);  // ���
		//��������
		//s.removeStation(1); // ������ ������� 1
		//s.removeAdjacentStation(1,0); // ������� ������� ������� 0 ������� 1


	return 0;
}








