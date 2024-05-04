
#include<iostream>
#include "RusRails.h"
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