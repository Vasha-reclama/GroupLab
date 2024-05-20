#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
class Train;



class Ticket {
private:
	unsigned int id;
	char name[40] = {};//íàäåþñü 40 ñèìâîëîâ äëÿ ôèî õâàòèò, õàõõàõà
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
	int trains[10] = {};
	int stations[20] = {};
	int trainCount = {};
	int stationCount = {};

public:

	friend std::istream& operator>>(std::istream& is, Route& route);
	friend std::ostream& operator<<(std::ostream& os, const Route& route);

	int getId() const;
	const int* getTrains() const;
	const int* getStations() const;
	void setId(int x);
	int getStatinsCount();
	int getTrainsCount();
	void addTrain(int trainId);
	void removeTrain(int trainId);
	void changeStations(int* newStations, int newStationCount);
	void addStation(int stationId);
	void removeStation(int stationId);
};
class Station {
private:
	int id;
	char name[20];
	int adjacentStations[5];
	int distances[5];
	int numAdjacent;

public:
	Station() : numAdjacent(0) {};
	Station(int id, const char* name, int* adjacentStations, int* distances);

	friend std::istream& operator>>(std::istream& is, Station& station);
	friend std::ostream& operator<<(std::ostream& os, const Station& station);

	int getId();
	void setId(int _id);
	const char* getName() const;
	const int* getAdjacentStations() const;
	const int* getDistances() const;

	void changeName(const char* newName);
	void addAdjacentStation(int adjacentId, int distance);
	void removeAdjacentStation(int adjacentId);
	void editAdjacentStation(int index, int newAdjacentId, int newDistance);
	void getTrainSchedule(const Train* trains);
	int getNumAdj();
};
class Train {
private:
	unsigned id;
	short limit;
	time_t start = {};
	int curSt; //ìá è íå íóæíî, ÿ âîò òàê ùàñ çàäóìàëñÿ.............
	int path;
	bool direction = true;
	//int arrivalTime;
	//int stationId;
public:
	friend std::istream& operator >>(std::istream& in, Train& r);
	friend std::ostream& operator <<(std::ostream& out, const Train& r);
	void setId(int x);
	int getLim();
	void setLim(int x);
	std::time_t getStart();
	int getPath();
	bool setPath(std::vector<Route>* routes, int routesCount);
	int getCurStation();
	void changeCurStation(time_t curTime, std::vector<Route>* routes, int routesCount, std::vector<Station>* stations);
	bool setStartTime(time_t globalTime);
	int getId() const;
	int getArrivalTime() const;
	int getStationId() const;
};


namespace rjd {
	void write(std::vector<Route>* routes, int n);
	void create(std::vector<Route>* routes, int* n, std::vector<Station>* stations, int stationCount);
	void read(std::vector<Route>* routes, int* n);
	void add(std::vector<Route>* routes, int* n);
	void remove(std::vector<Route>* routes, int* n);
	void edit(std::vector<Route>* routes, int n, std::vector<Station>* stations, int stationCount);

	void write(std::vector<Station>* station, int n);
	void create(std::vector<Station>* station, int* n);
	void read(std::vector<Station>* station, int* n);
	void add(std::vector<Station>* station, int* n);
	void remove(std::vector<Station>* station, int* n);
	void edit(std::vector<Station>* station, int n);
	void print(std::vector<Station>* station, int n);

	//void write(std::vector<Ticket>* tickets, int n);
	void create(std::vector<Ticket>* tickets, int* ticketCount);
	void read(std::vector<Ticket>* tickets, int* ticketCount);
	void add(std::vector<Ticket>* tickets, int* ticketCount);
	void remove(std::vector<Ticket>* tickets, int* ticketCount);
	void edit(std::vector<Ticket>* tickets, int ticketCount);

	void write(std::vector<Train>* trains, int n);
	void create(std::vector<Train>* trains, int* n, time_t globalTime, std::vector<Route>* routes, int routesCount);
	void read(std::vector<Train>* trains, int* n);
	void add(std::vector<Train>* trains, int* n);
	void remove(std::vector<Train>* trains, int* n);
	void edit(std::vector<Train>* trains, int n);

}

class Matrix{
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols);
    int getRows() const;
    int getCols() const;
    std::vector<int>& operator[](int index);
    const std::vector<int>& operator[](int index) const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix sumOfPowers(int n);
};
