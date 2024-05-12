
#include<iostream>
#include "RusRails.h"

using namespace std;

istream& operator>>(istream& is, Station& station) {
	return is;
}

ostream& operator<<(ostream& os, const Station& station) {
	os << "Идентификатор станции: " << station.id << "\n"
		<< "Название: " << station.name << "\n";
	os << "Расстояния: ";
	os << station.distance << " ";
	os << "\n";
	return os;
}

int Station::getId() {
	return id;
}

void Station::setId(int id) {
	this->id = id;
}

void Station::setDistance(int d) {
	distance = d;
}

int Station::getDistance() {
	return distance;
}

std::string Station::getName() {
	return name;
}

void Station::setName(std::string name)
{
	this->name = name;
}

void StationManager::addStation(std::string name, int distance) {
	int tempId = stations.size(); // следующий id это кол-во эл-тов в списке
	Station newStation(tempId, name, distance);
	stations.push_back(newStation); // вставляем в конец
}

void StationManager::editStation(int index, std::string name, int distance) {
	stations[index].setName(name);
	stations[index].setDistance(distance);
}

void StationManager::deleteStation(int index) {
	stations.erase(stations.begin() + index);
}

void StationManager::printStations() {
	for (int i = 0; i < stations.size(); i++) {
		cout << stations[i];
	}
}

int StationManager::getSize()
{
	return stations.size();
}