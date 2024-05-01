#include "RusRails.h"
#include<iostream>
using namespace std;

Station::Station() : id(0) {}

Station::Station(int id, const char* name, int* adjacentStations, int* distances)
    : id(id) {
    strcpy(this->name, name);
    for (int i = 0; i < 5; ++i) {
        this->adjacentStations[i] = adjacentStations[i];
        this->distances[i] = distances[i];
    }
}

istream& operator>>(istream& is, Station& station) {
    is >> station.id >> station.name;
    for (int i = 0; i < 5; ++i) {
        is >> station.adjacentStations[i] >> station.distances[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const Station& station) {
    os << "Station ID: " << station.id << endl;
    os << "Name: " << station.name << endl;
    os << "Adjacent Stations: ";
    for (int i = 0; i < 5; ++i) {
        os << station.adjacentStations[i] << " ";
    }
    os << endl << "Distances: ";
    for (int i = 0; i < 5; ++i) {
        os << station.distances[i] << " ";
    }
    os << endl;
    return os;
}

int Station::getId() const {
    return id;
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
    for (int i = 0; i < 5; ++i) {
        if (adjacentStations[i] == 0) {
            adjacentStations[i] = adjacentId;
            distances[i] = distance;
            break;
        }
    }
}

void Station::removeAdjacentStation(int adjacentId) {
    for (int i = 0; i < 5; ++i) {
        if (adjacentStations[i] == adjacentId) {
            adjacentStations[i] = 0;
            distances[i] = 0;
            break;
        }
    }
}

void Station::editAdjacentStation(int index, int newAdjacentId, int newDistance) {
    adjacentStations[index] = newAdjacentId;
    distances[index] = newDistance;
}

void Station::getTrainSchedule(const vector<Train>& trains) const {
    cout << "Расписание движения поездов по станции " << id << ": " << endl;
    for (const Train& train : trains) {
        if (train.getStationId() == id) {
            cout << "ID поезда: " << train.getId() << "Время прибытия: " << train.getArrivalTime() << endl;
        }
    }
    
}