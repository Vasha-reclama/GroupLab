
#include<iostream>
#include "RusRails.h"
using namespace std;


istream& operator>>(istream& is, Route& route) {
    //is >> route.id;
    /*cout << "trainCount=";
    if (!(is >> route.trainCount).good())
        return is;*/
    //if (route.trainCount > 10) {//ïåðåäåëàòü ïîñëå òîãî êàê áóäåò ãîòîâà òàáëèöà ïîåçäîâ
    //    cout << "Ïðåâûøåí ëèìèò ïîåçäîâ";
    //    return is;
    //}
    //for (int i = 0; i < route.trainCount; ++i) {
    //    cout << "Ââåäèòå ïîåçä íîìåð " << i + 1 << endl;
    //    if (!(is >> route.trains[i]).good())
    //        return is;
    //}
    /*cout << "station count=";
    if (!(is >> route.stationCount).good())
        return is;*/
   /* if (route.stationCount > 20) {
        cout << "Ïðåâûøåí ëèìèò ñòàíöèé";
        return is;
    }
    for (int i = 0; i < route.stationCount; ++i) {
        cout << "Ââåäèòå ñòàíöèþ íîìåð " << i + 1 << endl;
        if (!(is >> route.stations[i]).good()) {
            cout << "Syntaxis error" << endl;
            return is;
        }
    }*/
    return is;
}

ostream& operator<<(ostream& os, const Route& route) {
    if (route.trainCount > 0)
        os << route.id << " " << route.stationCount << " " << route.stations[0] << "..." << route.stations[route.stationCount - 1] << " " << route.trainCount << " " <<
        route.trains[0] << "..." << route.trains[route.trainCount - 1];
    else
        os << route.id << " " << route.stationCount << " " << route.stations[0] << "..." << route.stations[route.stationCount - 1] << " " << route.trainCount;
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
        trainCount++;
        trains[trainCount-1] = trainId;
    }
    else {
        cout << "cant add train" << endl;
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

    else {
        cout << "cant add station" << endl;
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

int Route::getStatinsCount() {
    return stationCount;
}

int Route::getTrainsCount() {
    return trainCount;
}


void Route::setId(int x) {
    id = x;
}

