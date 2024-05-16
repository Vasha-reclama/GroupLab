#include<iostream>
#include <iomanip> 
#include <fstream>
#include<ctime>
#include<string>
#include <sstream>
#include "RusRails.h"
using namespace std;

Train::Train(int id, int arrivalTime, int stationId)
	: id(id), arrivalTime(arrivalTime), stationId(stationId) {}

int Train::getId() const {
	return id;
}

int Train::getLim() {
	return limit;
}

void Train::setPath() {
}

time_t Train::getStart() {
	return start;
}

int Train::setLim(int x) {
	limit = x;
}

int Train::getPath() {
	return path;
}

int Train::getArrivalTime() const {
	return arrivalTime;
}

int Train::getStationId() const {
	return stationId;
}

void Train::setId(int x) {
	id = x;

}

int Train::getCurStation() {
	return curSt;
}

void Train::changeCurStation(int x) {
	curSt = x;
}

ostream& operator <<(ostream& out, const Train& r) {
	tm timeStart;
	localtime_s(&timeStart, &parcel.sentTime);
	char start[80];
	strftime(start, 80, "%Y-%m-%d %H:%M:%S", &timeStart);
	out << r.id << " " << r.limit << " " << start << " " << r.curSt << " " << r.path;
	return out;
}

istream& operator >>(istream& in, Train& r) {
	string time;
	cout << "Лимит пассажиров: ";
	int limit;
	while (!(in >> limit).good() || r.limit < 1 || r.limit > 50) {
		cout << "Недопустимое значение, введите значение от 1 до 50 " << endl;;
	}
	cout << "Выберите начальную станцию: ";
	//Тут должны выводиться все начальные станции и их id


	cout << "Выберите конечную станцию: ";
	//Тут должны быть все смежные станции c начальной ,либо вместо этого будет выбор маршрута с уже имеющийся начальной и конечной станцией

	cout << "Введите дату и время отправки (в формате YYYY-MM-DD HH:MM:SS): ";
	cin >> time;
	tm tm = {};
	istringstream times(time);
	times >> get_time(&tm, "%Y-%m-%d %H:%M:%S");
	if (times.fail()) {
		std::cerr << "Ошибка: неверный формат ввода." << std::endl;
	}
	time_t timeStart = mktime(&tm);

	if (timeStart == -1) {
		std::cerr << "Ошибка: не удалось преобразовать в time_t." << std::endl; // На всякий оставила чтобы знать, чтобы узнать в чем проблема)
	}
	if (timeStart >= globalTime) : //globalTime это время ,которое сейчас
		r.start = timeStart;
	return in;
}
