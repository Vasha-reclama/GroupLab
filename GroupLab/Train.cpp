#include "RusRails.h"
#include<iostream>
using namespace std;

Train::Train(int id, int arrivalTime, int stationId)
    : id(id), arrivalTime(arrivalTime), stationId(stationId) {}

int Train::getId() const {
    return id;
}

int Train::getArrivalTime() const {
    return arrivalTime;
}

int Train::getStationId() const {
    return stationId;
}