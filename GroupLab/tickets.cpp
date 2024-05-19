#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include"RusRails.h"

using namespace std;

istream& operator >>(istream& in, Ticket& r) {
	cout << "ФИО=";
	string str;
	getline(in, str);
	if (str.length() <= 40) {
		for (int i = 0; i < str.length(); i++) {
			r.name[i] = str[i];
		}
		for (int i = str.length(); i < 40; i++) {
			r.name[i] = NULL;
		}
	}
	else {
		for (int i = 0; i < 40; i++) {
			r.name[i] = str[i];
		}
	}
	cout << "список станций" << endl; //(сделать после того, как будет обработаны методы станций)
	if ((in >> r.startSt).good()) {
		/*else {
			in.clear();
			cout << "Syntaxis error" << endl;
			return in;
		}*/
		cout << "До какой станции вы хотите доехать?" << endl;//Вывести список допустимых станций(можно реализовать через матрицу достижимости)
		if ((in >> r.finish).good()) {
			/*else {
				cout << "Syntaxis error" << endl;
				in.clear();
				return in;
			}*/
			cout << "Список поездов и время прибытие" << endl;// сделать после реализации методов
			if ((in >> r.trainId).good());
		}
	}
	/*else {
		in.clear();
		cout << "Syntaxis error" << endl;
		return in;
	}*/

	return in;
}

ostream& operator <<(ostream& out, const Ticket& r) {
	out << r.id << " " << r.name << " " << r.startSt << " " << r.trainId << " " << r.finish;
	return out;
}

void Ticket::setId(int x) {
	id = x;
}

int Ticket::getId() {
	return id;
}

int Ticket::getFinish() {
	return finish;
}

int Ticket::getStart() {
	return startSt;
}

int Ticket::getTrain() {
	return trainId;
}

