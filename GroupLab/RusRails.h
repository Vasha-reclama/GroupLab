#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <string>

class Train {
private:
	unsigned id;
	short limit;
	time_t start = {};
	int curSt; //�� � �� �����, � ��� ��� ��� ���������.............
	int path;
	int arrivalTime;
	int stationId;
public:
	friend std::istream& operator >>(std::istream& in, Train& r);
	friend std::ostream& operator <<(std::ostream& out, const Train& r);
	void setId(int x);
	int getId();
	int getLim();
	std::time_t getStart();
	int getPath();
	void setPath();
	int getCurStation();
	void changeCurStation(int x);
	//Train();
	Train(int id, int arrivalTime, int stationId);
	int getId() const;
	int getArrivalTime() const;
	int getStationId() const;
};

class Ticket {
private:
	unsigned int id;
	char name[40] = {};//������� 40 �������� ��� ��� ������, �������
	int startSt;
	int trainId;
	int finish;
public:
	//Ticket();
	friend std::istream& operator >>(std::istream& in, Ticket& r);
	friend std::ostream& operator <<(std::ostream& out, const Ticket& r);
	void setId(int x);
	int getId();
	int getStart();
	int getFinish();
	int getTrain();
};
class Route {
private:
	int id;
	int trains[10];
	int stations[20];
	int trainCount;
	int stationCount;

public:
	Route() {};
	Route(int id, int* trains, int* stations, int trainCount, int stationCount);

	friend std::istream& operator>>(std::istream& is, Route& route);
	friend std::ostream& operator<<(std::ostream& os, const Route& route);

	int getId() const;
	const int* getTrains() const;
	const int* getStations() const;

	void addTrain(int trainId);
	void removeTrain(int trainId);
	void changeStations(int* newStations, int newStationCount);
	//void addStation(int stationId);
	//void removeStation(int stationId);  //����� ��� ����� 2 ��� �������?? ��� ����������� ������ Station?
};
class Station {
private:
	unsigned int id;    // id �������
	char name[50];      // �������� �������
	unsigned int number_station;    // ����� �������
	int distance;   // ��������� �� ������� �������

	std::vector<Station> stations;    // ��� �������
	std::vector<Station> adjacent_stations;  // ��� ������� �������

public:
	Station() {};
	friend std::istream& operator>>(std::istream& is, Station& station);
	friend std::ostream& operator<<(std::ostream& os, const Station& station);

	int getId();
	char* getName();
	Station* getAdjacentStations(int stationId, int adjacentId);
	int getDistance();

	void changeName(const char* newName);
	void addAdjacentStation(int stationId, char * name, int distance);
	void removeAdjacentStation(int stationId, int adjacentId);
	//void editAdjacentStation(int stationId, int adjacentId, char* name, int newDistance);
	void getTrainSchedule(const std::vector<Train>& trains);

	Station* getStation(int stationId);
	void addStation(char* name);
	//void editStation(int stationId, char* name);
	void removeStation(int stationId);
	void printALLStation();// ����� ���� �������, ������� �������
	void findStation(char* name);
};
