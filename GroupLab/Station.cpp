
#include<iostream>
#include "RusRails.h"
using namespace std;

istream& operator>>(istream& is, Station& station) {
    return is;
}

ostream& operator<<(ostream& os, const Station& station) {
    os << "������������� �������: " << station.id << " " << "��������: " << station.name << endl;
    os << "������� �������: " << endl;

    for (int s = 0; s < station.adjacent_stations.size(); s++)  // ��� ���������� ������� � ������� � ��������� �� ���
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
    s.changeName(name); // ����� ���
    s.distance = distance_path;  //����� ���������
    s.id = stations[stationId].adjacent_stations.size(); //����� ID
    stations[stationId].adjacent_stations.push_back(s);   // ���������� � �����
}
   
void Station::removeAdjacentStation(int stationId, int adjacentId) {
    if (stations[stationId].adjacent_stations.empty())
    {                                           // ���� ��� ������� �������
        cout << "��� ������� �������!" << endl;
        return;
    }
    stations[stationId].adjacent_stations.erase(stations[stationId].adjacent_stations.begin() + adjacentId); // ������� �� Id;
}
    

/*void Station::editAdjacentStation(int stationId, int adjacentId, char* name, int newDistance) {
    if (stations[stationId].adjacent_stations.empty())
    {                                           // ���� ��� ������� �������
        cout << "��� ������� �������!" << endl;
        return;
    }
    
}
*/

void Station::getTrainSchedule(const std::vector<Train>& trains)  {
    
    cout << "���������� �������� ������� �� ������� " << getId() << ": " << endl;
    for (const Train& train : trains) {
        if (train.getStationId() == getId()) {
            cout << "ID ������: " << train.getId() << "����� ��������: " << train.getArrivalTime() << endl;
        }
    }
    
}

void Station::addStation(char* name) {
    Station s;
    s.changeName(name);  //����� ���
    s.id = stations.size();  //����� Id
    stations.push_back(s);  // ���������� � �����
}

void Station::removeStation(int stationId) {
    if (stations.empty())  // ���� ��� �������
    {
        cout << "��� �������!" << endl;
        return;
    }
    if (stationId > stations.size()) // Id �� ������ �������
    {
        cout << "�������� ID ��������� ���������� �������!" << endl;
        return;
    }
    stations.erase(stations.begin() + stationId); // ������� �� Id
}

Station* Station::getStation(int stationId) {
    if (stations.empty())  // ���� ��� �������
    {
        cout << "��� �������!" << endl;
        return NULL;
    }
    if (stationId > stations.size()) // Id �� ������ �������
    {
        cout << "�������� ID ��������� ���������� �������!" << endl;
        return NULL;
    }
    return &stations.at(stationId); // �������� ������ ������� �� Id
}

void Station::printALLStation() {
    for (int s = 0; s < stations.size(); s++)
    {
        cout << stations[s];
    }
}

void Station::findStation(char* name) {
    if (stations.empty())  // ���� ��� �������
    {
        cout << "��� �������!" << endl;
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
