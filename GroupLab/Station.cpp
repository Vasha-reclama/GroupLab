
#include<iostream>
#include "RusRails.h"
using namespace std;

Station::Station(int id, const char* name, int* adjacentStations, int* distances)
    : id(id) {
    strcpy(this->name, name);
    for (int i = 0; i < 5; ++i) {
        this->adjacentStations[i] = adjacentStations[i];
        this->distances[i] = distances[i];
    }
}

istream& operator>>(istream& is, Station& station) {
    cout << "������� �������� �������: ";
    is.ignore(); 
    is.getline(station.name, 20);

    cout << "������� ������ � ������� �������� � ����������� �� ���:\n" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "������� ������� " << i + 1 << " ID: ";
        is >> station.adjacentStations[i];
        cout << "���������� �� ���: " << i + 1 << ": ";
        is >> station.distances[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const Station& station) {
    os << "������������� �������: " << station.id << "\n"
        << "��������: " << station.name << "\n"
        << "������� �������: ";
    for (int i = 0; i < 5; ++i) {
        os << station.adjacentStations[i] << " ";
    }
    os << "\n����������: ";
    for (int i = 0; i < 5; ++i) {
        os << station.distances[i] << " ";
    }
    os << "\n";
    return os;
}

int Station::getId() {
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

void Station::getTrainSchedule(const std::vector<Train>& trains)  {
    
    cout << "���������� �������� ������� �� ������� " << getId() << ": " << endl;
    for (const Train& train : trains) {
        if (train.getStationId() == getId()) {
            cout << "ID ������: " << train.getId() << "����� ��������: " << train.getArrivalTime() << endl;
        }
    }
    
}