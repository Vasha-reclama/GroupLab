#pragma once
#include <vector>

class Station {
private:
	unsigned int id;
	char name[40] = {};
	int con[5] = {-1,-1,-1,-1,-1}; // соединение, -1 означает, что нет связи
	int dis[5] = {}; // дистанция, 0 означает, что нет связи
public:
	friend std::istream& operator >>(std::istream& in, Station& r);
	friend std::ostream& operator <<(std::ostream& out, const Station& r);
	void setId(int x);
	int getId();
	int* getCon();
	int* getDis();
	void getTrainsList();
};

class Path {
private:
	unsigned int id;
	int trains[10] = {};//список прикрепленных поездов
	int stations[20] = {};//маршрут
public:
	friend std::istream& operator >>(std::istream& in, Path& r);
	friend std::ostream& operator <<(std::ostream& out, const Path& r);
	void setId(int x);//
	int getId();//получение Id маршрута
	int* getTrains();//
	int* getStations();
};

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
	Route();
	Route(int id, int* trains, int* stations, int trainCount, int stationCount);

	friend std::istream& operator>>(std::istream& is, Route& route);
	friend std::ostream& operator<<(std::ostream& os, const Route& route);

	int getId() const;
	const int* getTrains() const;
	const int* getStations() const;

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

public:
	Station();
	Station(int id, const char* name, int* adjacentStations, int* distances);

	friend std::istream& operator>>(std::istream& is, Station& station);
	friend std::ostream& operator<<(std::ostream& os, const Station& station);

	int getId() const;
	const char* getName() const;
	const int* getAdjacentStations() const;
	const int* getDistances() const;

	void changeName(const char* newName);
	void addAdjacentStation(int adjacentId, int distance);
	void removeAdjacentStation(int adjacentId);
	void editAdjacentStation(int index, int newAdjacentId, int newDistance);
	void getTrainSchedule(const vector<Train>& trains) const;
};
