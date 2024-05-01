
#include<iostream>
#include "RusRails.h"
using namespace std;

Route::Route(int id, int* trains, int* stations, int trainCount, int stationCount)
    : id(id), trainCount(trainCount), stationCount(stationCount) {
    for (int i = 0; i < trainCount; ++i) {
        this->trains[i] = trains[i];
    }
    for (int i = 0; i < stationCount; ++i) {
        this->stations[i] = stations[i];
    }
}

istream& operator>>(istream& is, Route& route) {
    is >> route.id;
    for (int i = 0; i < route.trainCount; ++i) {
        is >> route.trains[i];
    }
    for (int i = 0; i < route.stationCount; ++i) {
        is >> route.stations[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const Route& route) {
    os << "Route ID: " << route.id << endl;
    os << "Trains: ";
    for (int i = 0; i < route.trainCount; ++i) {
        os << route.trains[i] << " ";
    }
    os << endl << "Stations: ";
    for (int i = 0; i < route.stationCount; ++i) {
        os << route.stations[i] << " ";
    }
    os << endl;
    return os;
}

int Route::getId() const {
    return id;
}

const int* Route::getTrains() const {
    return trains;
}

const int* Route::getStations() const {
    return stations;
}

void Route::addTrain(int trainId) {
    if (trainCount < 10) {
        trains[trainCount++] = trainId;
    }
}

void Route::removeTrain(int trainId) {
    for (int i = 0; i < trainCount; ++i) {
        if (trains[i] == trainId) {
            for (int j = i; j < trainCount - 1; ++j) {
                trains[j] = trains[j + 1];
            }
            trainCount--;
            break;
        }
    }
}

void Route::changeStations(int* newStations, int newStationCount) {
    stationCount = newStationCount;
    for (int i = 0; i < newStationCount; ++i) {
        stations[i] = newStations[i];
    }
}

void Route::addStation(int stationId) {
    if (stationCount < 20) {
        stations[stationCount++] = stationId;
    }
}

void Route::removeStation(int stationId) {
    for (int i = 0; i < stationCount; ++i) {
        if (stations[i] == stationId) {
            for (int j = i; j < stationCount - 1; ++j) {
                stations[j] = stations[j + 1];
            }
            stationCount--;
            break;
        }
    }
}
