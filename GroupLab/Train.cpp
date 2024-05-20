#include<iostream>
#include <iomanip> 
#include <fstream>
#include<ctime>
#include<string>
#include <sstream>
#include "RusRails.h"
using namespace std;



int Train::getId() const {
	return id;
}

int Train::getLim() {
	return limit;
}

time_t Train::getStart() {
	return start;
}

void Train::setLim(int x) {
	limit = x;
}

int Train::getPath() {
	return path;
}

//int Train::getArrivalTime() const {
//	return arrivalTime;
//}

//int Train::getStationId() const {
//	return stationId;
//}

void Train::setId(int x) {
	id = x;

}

int Train::getCurStation() {
	return curSt;
}

void Train::changeCurStation(time_t curTime, vector<Route>* routes, int routesCount, vector<Station>* stations) {
	Route* temp=nullptr;
	time_t pastTense=start;
	for (int i = 0; i < routesCount; i++) {
		if (routes->at(i).getId() == path) {
			temp = &(routes->at(i));
			break;
		}
	}
	if (temp == nullptr) {
		cout << "Что-то пошло не так" << endl;
		return;
	}
	if (direction) {
		for (int i = 0; i < temp->getStatinsCount()-1; i++) {
			int StId = (temp->getStations())[i];
			int nextStId = (temp->getStations())[i + 1];
			Station* tempSt=nullptr;
			for (int j = 0; j < stations->size(); j++) {
				if (stations->at(j).getId() == StId) {
					tempSt = &(stations->at(j));
					break;
				}
			}
			int x;
			for (int j = 0; j < tempSt->getNumAdj(); j++) {
				if (tempSt->getAdjacentStations()[j] == nextStId) {
					x = j;
					break;
				}
			}
			if (pastTense + (tempSt->getDistances()[x]) * 3600 < curTime) {
				pastTense += (tempSt->getDistances()[x]) * 3600;
			}
			else {
				curSt = nextStId;
				return;
			}
		}
		direction = false;
	}
	else {
		pastTense = start;
		for (int i = 0; i < temp->getStatinsCount()-1; i++) {
			int StId = (temp->getStations())[i];
			int nextStId = (temp->getStations())[i + 1];
			Station* tempSt=nullptr;
			for (int j = 0; j < stations->size(); j++) {
				if (stations->at(j).getId() == StId) {
					tempSt = &(stations->at(j));
					break;
				}
			}
			int x;
			for (int j = 0; j < tempSt->getNumAdj(); j++) {
				if (tempSt->getAdjacentStations()[j] == nextStId) {
					x = j;
					break;
				}
			}
			pastTense += (tempSt->getDistances()[x]) * 3600;
		}
		for (int i = temp->getStatinsCount() - 1; i > 0; i--) {
			int StId = (temp->getStations())[i];
			int nextStId = (temp->getStations())[i -1];
			Station* tempSt=nullptr;
			for (int j = 0; j < stations->size(); j++) {
				if (stations->at(j).getId() == StId) {
					tempSt = &(stations->at(j));
					break;
				}
			}
			int x;
			for (int j = 0; j < tempSt->getNumAdj(); j++) {
				if (tempSt->getAdjacentStations()[j] == nextStId) {
					x = j;
					break;
				}
			}
			if (pastTense + (tempSt->getDistances()[x]) * 3600 < curTime) {
				pastTense += (tempSt->getDistances()[x]) * 3600;
			}
			else {
				curSt = nextStId;
				return;
			}
		}
	}
	start = curTime + 86400;
	
}

ostream& operator <<(ostream& out, const Train& r) {
	/*tm timeStart;
	localtime_s(&timeStart, &parcel.sentTime);*/
	char start[80];
	//strftime(start, 80, "%Y-%m-%d %H:%M:%S", &timeStart);
	out << r.id << " " << r.limit << " " << start << " " << r.curSt << " " << r.path;
	return out;
}

istream& operator >>(istream& in, Train& r) {
	//string time;
	cout << "Лимит пассажиров: ";
	int limit;
	while (!(in >> limit).good() || r.limit < 1 || r.limit > 50) {
		cout << "Недопустимое значение, введите значение от 1 до 50 " << endl;;
	}
	//cout << "Выберите начальную станцию: ";
	//Тут должны выводиться все начальные станции и их id


	//cout << "Выберите конечную станцию: ";
	//Тут должны быть все смежные станции c начальной ,либо вместо этого будет выбор маршрута с уже имеющийся начальной и конечной станцией

	/*cout << "Введите дату и время отправки (в формате YYYY-MM-DD HH): ";
	in >> time;
	tm tm = {};
	istringstream times(time);
	times >> get_time(&tm, "%Y-%m-%d %H");
	if (times.fail()) {
	std::cerr << "Ошибка: неверный формат ввода." << std::endl;
	}
	time_t timeStart = mktime(&tm);

	if (timeStart == -1) {*/
	//	std::cerr << "Ошибка: не удалось преобразовать в time_t." << std::endl; // На всякий оставила чтобы знать, чтобы узнать в чем проблема)
	//}
	////if (timeStart >= globalTime) //globalTime это время ,которое сейчас
	////	r.start = timeStart;
	return in;
}

bool Train::setStartTime(time_t globalTime) {
	string time;
	cout << "Введите дату и время отправки (в формате YYYY-MM-DD HH): ";
	cin >> time;
	tm tm = {};
	istringstream times(time);
	times >> get_time(&tm, "%Y-%m-%d %H");
	if (times.fail()) {
	std::cerr << "Ошибка: неверный формат ввода." << std::endl;
	return 0;
	}
	time_t timeStart = mktime(&tm);

	if (timeStart == -1) {
		std::cerr << "Ошибка: не удалось преобразовать в time_t." << std::endl; // На всякий оставила чтобы знать, чтобы узнать в чем проблема)
		return 0;
	}
	if (timeStart >= globalTime) //globalTime это время ,которое сейчас
		start = timeStart;
	return 1;
}

bool Train::setPath(vector<Route>* routes, int routesCount) {
	for (int i = 0; i < routesCount; i++) {
		cout << routes->at(i) << endl;
	}
	cout << "Введите id маршрута" << endl;
	int id;
	if (!(cin >> id).good()) {
		cout << "Syntax error" << endl;
		return 0;
	}
	Route* temp=nullptr;
	for (int i = 0; i < routesCount; i++) {
		if (routes->at(i).getId() == id) {
			temp = &(routes->at(i));
			break;
		}
	}
	temp->addTrain(id);
	curSt = temp->getStations()[0];
	path = id;

	return 1;
}