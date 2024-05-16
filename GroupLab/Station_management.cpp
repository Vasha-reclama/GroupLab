#include "RusRails.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

namespace rjd {
	void write(vector<Station>* station, int n) {
		ofstream out;
		out.open("stations.bin", ios_base::binary);
		if (!out.is_open()) {
			cout << "cant open file" << endl;
			return;
		}
		out.write(reinterpret_cast<char*>(&n), sizeof(int));
		out.write(reinterpret_cast<char*>(&(station->at(0))), sizeof(Station) * n);
		out.close();
	}

	void create(vector<Station>* station, int* n) {
		cout << "n=";
		if (!(cin >> (*n)).good()) {
			cout << "Syntaxis error" << endl;
			return;
		}
		station->resize((*n));
		for (int i = 0; i < *n; i++) {
			Station temp;
			if (!(cin >> temp).good()) {
				cout << "„то-то пошло не так" << endl;
				return;
			}
			temp.setId(i);
			station->at(i) = temp;
		}
		write(station, *n);
	}

	void print(vector<Station>* station, int n) {
		cout << n << endl;
		for (int i = 0; i < n; i++) {
			cout << station->at(i) << endl;
		}
	}

	void read(vector<Station>* station, int* n) {
		ifstream in;
		in.open("stations.bin", ios_base::binary);
		if (!in.is_open()) {
			cout << "‘айл не был открыт корректно" << endl;
			return;
		}
		in.read(reinterpret_cast<char*>(n), sizeof(int));
		station->resize(*n);
		in.read(reinterpret_cast<char*>(&(station->at(0))), sizeof(Station) * *n);
		print(station, *n);
	}

	void add(vector<Station>* station, int* n) {
		Station temp;
		if (!(cin >> temp).good()) {
			cout << "„то-то пошло не так" << endl;
			return;
		}
		temp.setId(station->at((*n) - 1).getId() + 1);
		station->push_back(temp);
		(*n)++;
		write(station, *n);
	}

	void remove(vector<Station>* station, int* n) {
		print(station, *n);
		cout << "¬ыберите id станции дл€ удалени€" << endl;
		int id = 0;
		if (!(cin >> id).good()) {
			cout << "Syntaxis error" << endl;
			return;
		}
		int x = -1;
		for (int i = 0; i < *n; i++) {
			if (station->at(i).getId() == id) {
				x = i;
				break;
			}
		}
		if (x == -1) {
			cout << "Search failed" << endl;
			return;
		}
		station->erase(station->begin() + x);
		(*n)--;
		write(station, *n);
	}

	void edit(vector<Station>* station, int n) {
		//print(station, n);
		cout << "¬ыберите id станции дл€ редактировани€" << endl;
		int id;
		if (!(cin >> id).good()) {
			cout << "Syntaxis error" << endl;
			return;
		}
		Station* temp = nullptr;
		for (int i = 0; i < n; i++) {
			if (station->at(i).getId() == id) {
				temp = &(station->at(i));
				break;
			}
		}
		if (temp == nullptr) {
			cout << "input error" << endl;
			return;
		}
		//cout << *temp << endl;

		int stop = 0;
		while (stop != 1) {

			int key1 = 0;
			cout << "1-добавить смежную станцию, 2-удалить смежную станцию, 3-редактировать смежную станцию, 4-редактировать название основной станции, 5-печать станции, 6-выход(с сохранением)" << endl;
			if (!(cin >> key1).good()) {
				cout << "syntax error" << endl;
				//return;
			}
			switch (key1) {
			case 1: {
				cout << "¬ведите номер смежной станции дл€ добавлени€: ";
				int num = 0;
				if (!(cin >> num).good()) {
					cout << "Syntaxis error" << endl;
					return;
				}
				cout << "¬ведите дистанцию смежной станции дл€ добавлени€: ";
				int distance = 0;
				if (!(cin >> distance).good()) {
					cout << "Syntaxis error" << endl;
					return;
				}
				temp->addAdjacentStation(num, distance);
				break;
			}

			case 2: {
				cout << "¬ведите id смежной станции дл€ удалени€: ";
				int num = 0;
				if (!(cin >> num).good()) {
					cout << "Syntaxis error" << endl;
					return;
				}

				int index = -1;
				const int* adj = temp->getAdjacentStations();
				for (int i = 0; i < 5; i++)
				{
					if (i == num)
					{
						index = adj[i];
						break;
					}
				}

				if (index == -1)
				{
					cout << "нет id смежной станции - " << num << endl;
					break;
				}

				temp->removeAdjacentStation(index);
				break;
			}
			case 3: {
				cout << "¬ведите id смежной станции дл€ редактировани€: ";
				int index = 0;
				if (!(cin >> index).good()) {
					cout << "Syntaxis error" << endl;
					return;
				}

				cout << "¬ведите новый номер смежной станции: ";
				int num_new = 0;
				if (!(cin >> num_new).good()) {
					cout << "Syntaxis error" << endl;
					return;
				}
				cout << "¬ведите новую дистанцию дл€ смежной станции: ";
				int distance_new = 0;
				if (!(cin >> distance_new).good()) {
					cout << "Syntaxis error" << endl;
					return;
				}
				temp->editAdjacentStation(index, num_new, distance_new);
				break;
			}
			case 4: {
				cout << "—тарое название станции: " << temp->getName() << endl;
				cout << "¬ведите новое название дл€ станции: ";
				char name[100];
				if (!(cin >> name).good()) {
					cout << "Syntaxis error" << endl;
					return;
				}

				temp->changeName(name);
				break;
			}
			case 5: {
				cout << *temp << endl;
				break;
			}


			case 6: {
				stop = 1;
				break;
			}

			}
		} // end while
		write(station, n);
	}
}
