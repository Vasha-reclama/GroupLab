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
	if (!direction) {
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
	direction = true;
	
}

ostream& operator <<(ostream& out, const Train& r) {
	tm* normalTime = localtime(&r.start);
	out << r.id << " " << r.limit << " " << normalTime->tm_year + 1900 << " " << normalTime->tm_mon + 1 << " " << normalTime->tm_mday << " " << normalTime->tm_hour << " " << r.curSt << " " << r.path;
	return out;
}

istream& operator >>(istream& in, Train& r) {
	//string time;
	cout << "Лимит пассажиров: ";
	int limit;
	while (!(in >> r.limit).good() || r.limit < 1 || r.limit > 50) {
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
	string inputTime;
	cout << "Введите дату и время отправки (в формате YYYY-MM-DD HH): ";
	cin.get();
	getline(cin, inputTime);
	tm tm = {};
	istringstream times(inputTime);
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
	int stid;
	if (!(cin >> stid).good()) {
		cout << "Syntax error" << endl;
		return 0;
	}
	Route* temp=nullptr;
	for (int i = 0; i < routesCount; i++) {
		if (routes->at(i).getId() == stid) {
			temp = &(routes->at(i));
			break;
		}
	}
	temp->addTrain(id);
	curSt = temp->getStations()[0];
	path = stid;

	return 1;
}

Train* Train::getPasAndTime(vector<Ticket>* tickets, int ticketCount, vector<Station>* stations, int stationCount, vector<Route>* routes, int routesCount, int stationA, int stationB) {
	;
	time_t pasTense = start;
	Route* tempRoute=nullptr;
	for (int i = 0; i < routesCount; i++) {
		if (routes->at(i).getId() == path) {
			tempRoute = &(routes->at(i));
			break;
		}
	}
	if (tempRoute == nullptr) {
		cout << "error" << endl;
		return NULL;
	}
	int a, b;
	for (int i = 0; i < tempRoute->getStatinsCount(); i++) {
		if (tempRoute->getStations()[i] == stationA) {
			a = i;
		}
		else if (tempRoute->getStations()[i] == stationB) {
			b = i;
		}
	}
	bool dir = true;
	if (a > b)
		dir = false;
	if (!dir) {
		for (int i = 0; i < tempRoute->getStatinsCount() - 1; i++) {
			int StId = (tempRoute->getStations())[i];
			int nextStId = (tempRoute->getStations())[i + 1];
			Station* tempSt = nullptr;
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
			pasTense += (tempSt->getDistances()[x]) * 3600;
		}
		int curPas = 0;
		for (int i = tempRoute->getStatinsCount() - 1; i > 0; i--) {
			for (int j = 0; j < ticketCount; j++) {
				if (tickets->at(j).getStart() == tempRoute->getStations()[i] && tickets->at(i).getTrain() == id)
					curPas++;
				else if (i != tempRoute->getStatinsCount() - 1) {
					if (tickets->at(j).getFinish() == tempRoute->getStations()[i] && tickets->at(i).getTrain() == id)
						curPas--;
				}
			}
			int StId = tempRoute->getStations()[i];
			int nextStId = tempRoute->getStations()[i - 1];
			Station* tempSt = nullptr;
			for (int j = 0; j < stationCount; j++) {
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
			if (tempRoute->getStations()[i] != stationA) {
				pasTense += (tempSt->getDistances()[x]) * 3600;
			}
			else {
				tm* normalTime = localtime(&pasTense);
				if (curPas < limit) {
					cout << id << " " << normalTime->tm_year+1900 << " " << normalTime->tm_mon << " " << normalTime->tm_mday << " " << normalTime->tm_hour << " " << curPas << endl;
					return this;
				}
			}

		}
	}
	else {
		int curPas = 0;
		for (int i = 0; i < tempRoute->getStatinsCount() - 1; i++) {
			for (int j = 0; j < ticketCount; j++) {
				if (tickets->at(j).getStart() == tempRoute->getStations()[i] && tickets->at(i).getTrain() == id)
					curPas++;
				else if (i != tempRoute->getStatinsCount() - 1) {
					if (tickets->at(j).getFinish() == tempRoute->getStations()[i] && tickets->at(i).getTrain() == id)
						curPas--;
				}
			}
			int StId = tempRoute->getStations()[i];
			int nextStId = tempRoute->getStations()[i + 1];
			Station* tempSt = nullptr;
			for (int j = 0; j < stationCount; j++) {
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
			if (tempRoute->getStations()[i] != stationA) {
				pasTense += (tempSt->getDistances()[x]) * 3600;
			}
			else {
				tm* normalTime = localtime(&pasTense);
				if (curPas < limit) {
					cout << id << " " << normalTime->tm_year+1900 << " " << normalTime->tm_mon << " " << normalTime->tm_mday << " " << normalTime->tm_hour << " " << curPas << endl;
					return this;
				}
			}
		}
	}
}