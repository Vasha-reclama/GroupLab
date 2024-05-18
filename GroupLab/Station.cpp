#include<iostream>
#include "RusRails.h"

using namespace std;

Station::Station(int id, const char* name, int* adjacentStations, int* distances) : numAdjacent(0) {
	this->id = id;
	strcpy(this->name, name);
	for (int i = 0; i < 5; i++) {
		if (adjacentStations[i] != -1 && distances[i] != -1) {
			this->adjacentStations[i] = adjacentStations[i];
			this->distances[i] = distances[i];
			numAdjacent++;
		}
		else {
			break;
		}
	}
}

istream& operator>>(istream& is, Station& station) {
	//is >> station.id;

	cout << "������� �������� �������: ";
	is >> station.name;
	cout << endl;

	cout << "������� ���-�� ������� ������� = ";

	if (!(is >> station.numAdjacent).good())
		return is;
	if (station.numAdjacent > 5) {
		cout << "�������� ����� �������" << endl;
		return is;
	}

	for (int i = 0; i < station.numAdjacent; i++) {
		if (station.adjacentStations[i] != -1 && station.distances[i] != -1) {
			cout << "������� ������� �������: ";
			if (!(is >> station.adjacentStations[i]).good())
			{
				cout << "������� ������� ������ ���� ������" << endl;
				return is;
			}
			cout << "���������: ";
			if (!(is >> station.distances[i]).good())
			{
				cout << "��������� ������ ���� ������" << endl;
				return is;
			}
			cout << endl;
		}
	}

	return is;
}

ostream& operator<<(ostream& os, const Station& station) {

	os << "id= " << station.id << "  " << "name=" << station.name << endl;

	for (int i = 0; i < station.numAdjacent; i++) {
		if (station.adjacentStations[i] != -1 && station.distances[i] != -1) {
			os << i << ":";
			os << "������� �������: " << station.adjacentStations[i] << "  ";
			os << "���������: " << station.distances[i] << endl;
		}
	}

	return os;
}

int Station::getId() {
	return id;
}

void Station::setId(int _id) {
	id = _id;
}

const char* Station::getName() const {
	return name;
}

const int* Station::getAdjacentStations() const {
	return adjacentStations;
}

const int* Station::getDistances() const {
	return distances;
}

void Station::changeName(const char* newName) {
	strcpy(name, newName);
}

void Station::addAdjacentStation(int adjacentId, int distance) {
	if (numAdjacent < 5) {
		adjacentStations[numAdjacent] = adjacentId;
		distances[numAdjacent] = distance;
		numAdjacent++;
	}
	else {
		std::cout << "Cannot add more adjacent stations." << std::endl;
	}
}

void Station::removeAdjacentStation(int adjacentId) {
	int flag_del = 0;
	for (int i = 0; i < numAdjacent; i++) {
		if (adjacentStations[i] == adjacentId) {
			for (int j = i; j < numAdjacent - 1; j++) {
				adjacentStations[j] = adjacentStations[j + 1];
				distances[j] = distances[j + 1];
			}
			numAdjacent--;
			flag_del = 1;
			break;
		}
	}

	if (flag_del == 0)
	{
		std::cout << "��� ����� �������!" << std::endl;
	}
}

void Station::editAdjacentStation(int index, int newAdjacentId, int newDistance) {
	if (index >= 0 && index < numAdjacent) {
		adjacentStations[index] = newAdjacentId;
		distances[index] = newDistance;
	}
	else {
		std::cout << "Invalid index." << std::endl;
	}
}

void Station::getTrainSchedule(const Train* trains) {
	// ���������� ��������� ���������� ������� ��� �������
}

