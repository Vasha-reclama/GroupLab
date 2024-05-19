#include "RusRails.h"
#include <fstream>
#include <iostream>
#include<vector>
using namespace std;


namespace rjd {
	void write(vector<Route>* routes, int n) {
		ofstream out;
		out.open("stations", ios_base::binary);
		if (!out.is_open()) {
			cout << "cant open file" << endl;
			return;
		}
		out.write(reinterpret_cast<char*>(&n), sizeof(int));
		out.write(reinterpret_cast<char*>(&(routes->at(0))), sizeof(Route) * n);
		out.close();
	}

	void create(vector<Route>* routes, int* n) {
		cout << "n=";
		if (!(cin >> (*n)).good()) {
			cout << "Syntaxis error" << endl;
			return;
		}

		routes->resize((*n));
		for (int i = 0; i < *n; i++) {
			Route temp;
			if (!(cin >> temp).good() or temp.getStatinsCount() > 20 or temp.getTrainsCount() > 10) {

				cout << "×òî-òî ïîøëî íå òàê" << endl;
				return;
			}
			temp.setId(i);
			routes->at(i) = temp;
		}
		write(routes, *n);
	}

	void print(vector<Route>* routes, int n) {
		cout << n << endl;
		for (int i = 0; i < n; i++) {
			cout << routes->at(i) << endl;
		}
	}

	void read(vector<Route>* routes, int* n) {
		ifstream in;
		in.open("stations", ios_base::binary);
		if (!in.is_open()) {
			cout << "Ôàéë íå áûë îòêðûò êîððåêòíî" << endl;
			return;
		}
		in.read(reinterpret_cast<char*>(n), sizeof(int));

		routes->resize(*n);

		in.read(reinterpret_cast<char*>(&(routes->at(0))), sizeof(Route) * *n);
		print(routes, *n);
	}

	void add(vector<Route>* routes, int* n) {
		Route temp;
		if (!(cin >> temp).good() or temp.getStatinsCount() > 20 or temp.getTrainsCount() > 10) {
			cout << "×òî-òî ïîøëî íå òàê" << endl;
			return;
		}

		temp.setId(routes->at((*n) - 1).getId() + 1);

		routes->push_back(temp);
		(*n)++;
		write(routes, *n);
	}

	void remove(vector<Route>* routes, int* n) {
		print(routes, *n);
		cout << "Âûáåðèòå ìàðøðóò äëÿ óäàëåíèÿ" << endl;
		int id;
		if (!(cin >> id).good()) {
			cout << "Synctaxis error" << endl;
			return;
		}

		int x = -1;

		for (int i = 0; i < *n; i++) {
			if (routes->at(i).getId() == id) {
				x = i;
				break;
			}
		}
		if (x == -1) {
			cout << "Search failed" << endl;
			return;
		}
		routes->erase(routes->begin() + x);
		(*n)--;
		write(routes, *n);
	}

	void edit(vector<Route>* routes, int n) {
		print(routes, n);
		cout << "Âûáåðèòå ìàðøðóò äëÿ ðåäàêòèðîâàíèÿ" << endl;
		int id;
		if (!(cin >> id).good()) {
			cout << "Synctaxis error" << endl;
			return;
		}
		Route* temp = nullptr;
		for (int i = 0; i < n; i++) {
			if (routes->at(i).getId() == id) {
				temp = &(routes->at(i));
				break;
			}
		}
		if (temp == nullptr) {
			cout << "input error" << endl;
			return;
		}
		cout << *temp << endl;
		cout << "1-edit stations, 2-edit trains" << endl;
		cout << "key=";
		int key;
		if (!(cin >> key).good()) {
			cout << "Syntaxis error" << endl;
			return;
		}
		switch (key) {
		case 1: {
			int key1;
			cout << "1-äîáàâèòü ñòàíöèþ, 2-ïåðåçàïèñàòü ïîñëåäîâàòåëüíîñòü" << endl;
			if (!(cin >> key1).good()) {
				cout << "syntaxis error" << endl;
				return;
			}
			switch (key1) {
			case 1: {
				cout << "Âûáåðèòå ñòàíöèþ" << endl;//ïåðåäåëàòü, êîãäà áóäåò ãîòîâà òàáëèöà ñòàíöèé
				int x;
				if (!(cin >> x).good()) {
					cout << "Syntaxis error" << endl;
					return;
				}
				temp->addStation(x);
			}
				  break;
			case 2: {
				cout << "Ââåäèòå íîâîå êîë-âî ñòàíöèé" << endl;
				int newStationCount;
				int newStation[20];
				if (!(cin >> newStationCount).good()) {
					cout << "Syntaxis error" << endl;
					return;
				}
				for (int i = 0; i < newStationCount; i++) {
					if (!(cin >> newStation[i]).good()) {
						cout << "Syntaxis error" << endl;
						return;
					}
				}
				temp->changeStations(newStation, newStationCount);
			}
				  break;
			}
		}
			  break;
		case 2: {
			int key2;
			cout << "1-äîáàâèòü ïîåçä, 2-óäàëèòü ïîåçä" << endl;
			if (!(cin >> key2).good()) {
				cout << "Syntaxis error" << endl;
				return;
			}

			switch (key2) {

			case 1:
			{
				cout << "Âûáåðèòå äîñòïóíûé ïîåçä" << endl;
				int x;
				if (!(cin >> x).good()) {
					cout << "Syntaxis error" << endl;
					return;
				}
				temp->addTrain(x);
			}
			break;
			case 2: {
				for (int i = 0; i < temp->getTrainsCount(); i++) {

					cout << temp->getTrains()[i] << " ";

				}
				cout << endl;
				cout << "Âûáåðèòå ïîåçä, êîòîðûé õîòèòå óäàëèòü" << endl;
				int x;
				if (!(cin >> x).good()) {
					cout << "Syntaxis error" << endl;
					return;
				}
				temp->removeTrain(x);
			}
				  break;
			}
		}
			  break;
		}
		write(routes, n);
	}
}