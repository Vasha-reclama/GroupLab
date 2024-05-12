#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Train {
private:
	unsigned id;
	short limit;
	time_t start = {};
	int curSt; //мб и не нужно, я вот так щас задумался.............
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
	char name[40] = {};//надеюсь 40 символов для фио хватит, хаххаха
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
	std::string name; // имя станции
	int distance; // дистанция до сдедующей станции путь в км

public:
	Station() {};
	Station(int index, std::string n, int d) : id(index), name(n), distance(d) {}

	friend std::istream& operator>>(std::istream& is, Station& station);
	friend std::ostream& operator<<(std::ostream& os, const Station& station);

	int getId();
	void setId(int id);
	std::string getName();
	void setName(std::string);
	int getDistance();
	void setDistance(int d);
};

class StationManager {
private:
	std::vector<Station> stations; // список станций. 

public:
	// функции для работы со станциями.
	void addStation(std::string name, int distance);
	void editStation(int index, std::string name, int distance);
	void deleteStation(int index);
	void printStations();
	int getSize(); // сколько станций
};


namespace rjd {
	void create(std::vector<Route>* routes, int* n);
	void read(std::vector<Route>* routes, int* n);
	void add(std::vector<Route>* routes, int* n);
	void remove(std::vector<Route>* routes, int* n);
	void edit(std::vector<Route>* routes, int n);

	// нужно только сохранять и загружать, и работать в памяти (ОЗУ) со станциями (add del edit)
	// работа с файлом это медленно если станций 1000
	void saveStations(StationManager& s, const std::string& filename);
	void loadStations(StationManager& s, const std::string& filename);
}