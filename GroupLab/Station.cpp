
#include<iostream>
#include "RusRails.h"
using namespace std;

istream& operator>>(istream& is, Station& station) {
    return is;
}

ostream& operator<<(ostream& os, const Station& station) {
    os << "Идентификатор станции: " << station.id << " " << "Название: " << station.name << endl;
    os << "Смежные станции: " << endl;

    for (int s = 0; s < station.adjacent_stations.size(); s++)  // для конкретной станции её смежные и дистанция до них
    {
        os << station.adjacent_stations[s].id << ":" << station.adjacent_stations[s].name << " , ";
        os << station.adjacent_stations[s].distance << " km; " << endl;
    }
    return os;
}

int Station::getId() {
    return id;
}

char* Station::getName(){
    return name;
}

Station* Station::getAdjacentStations(int stationId, int adjacentId) {
    return &stations[stationId].adjacent_stations.at(adjacentId);
}

int Station::getDistance(){
    return distance;
}

void Station::changeName(const char* newName) {
    strcpy(name, newName);
}

void Station::addAdjacentStation(int stationId, char* name, int distance_path) {
    Station s;
    s.changeName(name); // задаём имя
    s.distance = distance_path;  //задаём дистанцию
    s.id = stations[stationId].adjacent_stations.size(); //Задаём ID
    stations[stationId].adjacent_stations.push_back(s);   // Записываем в конец
}
   
void Station::removeAdjacentStation(int stationId, int adjacentId) {
    if (stations[stationId].adjacent_stations.empty())
    {                                           // если нет смежных станций
        cout << "Нет смежных станций!" << endl;
        return;
    }
    stations[stationId].adjacent_stations.erase(stations[stationId].adjacent_stations.begin() + adjacentId); // удаляем по Id;
}
    

/*void Station::editAdjacentStation(int stationId, int adjacentId, char* name, int newDistance) {
    if (stations[stationId].adjacent_stations.empty())
    {                                           // если нет смежных станций
        cout << "Нет смежных станций!" << endl;
        return;
    }
    
}
*/

void Station::getTrainSchedule(const std::vector<Train>& trains)  {
    
    cout << "Расписание движения поездов по станции " << getId() << ": " << endl;
    for (const Train& train : trains) {
        if (train.getStationId() == getId()) {
            cout << "ID поезда: " << train.getId() << "Время прибытия: " << train.getArrivalTime() << endl;
        }
    }
    
}

void Station::addStation(char* name) {
    Station s;
    s.changeName(name);  //задаём имя
    s.id = stations.size();  //задаём Id
    stations.push_back(s);  // записываем в конец
}

void Station::removeStation(int stationId) {
    if (stations.empty())  // если нет станций
    {
        cout << "Нет станций!" << endl;
        return;
    }
    if (stationId > stations.size()) // Id не больше размера
    {
        cout << "Введённый ID превышает допустимые размеры!" << endl;
        return;
    }
    stations.erase(stations.begin() + stationId); // удаляем по Id
}

Station* Station::getStation(int stationId) {
    if (stations.empty())  // если нет станций
    {
        cout << "Нет станций!" << endl;
        return NULL;
    }
    if (stationId > stations.size()) // Id не больше размера
    {
        cout << "Введённый ID превышает допустимые размеры!" << endl;
        return NULL;
    }
    return &stations.at(stationId); // получаем данные станции по Id
}

void Station::printALLStation() {
    for (int s = 0; s < stations.size(); s++)
    {
        cout << stations[s];
    }
}

void Station::findStation(char* name) {
    if (stations.empty())  // если нет станций
    {
        cout << "Нет станций!" << endl;
        return;
    }
    for (int s = 0; s < stations.size(); s++) {
        if (strstr(stations[s].name, name) != nullptr) {
            cout << stations[s];
        }
        for (int i = 0; i < stations.size(); i++) {
            if (strstr(stations[s].adjacent_stations[s].name, name) != nullptr) {
                cout << stations[s].adjacent_stations[s];
            }
        }
    }
}
