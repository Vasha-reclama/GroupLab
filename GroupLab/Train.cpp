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
	cout << "����� ����������: ";
	int limit;
	while (!(in >> limit).good() || r.limit < 1 || r.limit > 50) {
		cout << "������������ ��������, ������� �������� �� 1 �� 50 " << endl;;
	}
	cout << "�������� ��������� �������: ";
	//��� ������ ���������� ��� ��������� ������� � �� id


	cout << "�������� �������� �������: ";
	//��� ������ ���� ��� ������� ������� c ��������� ,���� ������ ����� ����� ����� �������� � ��� ��������� ��������� � �������� ��������

	cout << "������� ���� � ����� �������� (� ������� YYYY-MM-DD HH:MM:SS): ";
	cin >> time;
	tm tm = {};
	istringstream times(time);
	times >> get_time(&tm, "%Y-%m-%d %H:%M:%S");
	if (times.fail()) {
		std::cerr << "������: �������� ������ �����." << std::endl;
	}
	time_t timeStart = mktime(&tm);

	if (timeStart == -1) {
		std::cerr << "������: �� ������� ������������� � time_t." << std::endl; // �� ������ �������� ����� �����, ����� ������ � ��� ��������)
	}
	if (timeStart >= globalTime) : //globalTime ��� ����� ,������� ������
		r.start = timeStart;
	return in;
}
