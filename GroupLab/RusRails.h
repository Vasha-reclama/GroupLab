#pragma once
#include <vector>

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
namespace route {
	void addRoute(const Route& route);
	void deleteRoute(int routeId);

}
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
	void getTrainSchedule(const std::vector<Train>& trains) const;

};
namespace station {
	void addStation(const Station& station);
	void deleteStation(int stationId);
}
namespace rjd {
	void create(std::vector<Route>* routes, int* n);
	void read(std::vector<Route>* routes, int* n);
	void add(std::vector<Route>* routes, int* n);
	void remove(std::vector<Route>* routes, int* n);
	void edit(std::vector<Route>* routes, int n);


	void create(std::vector<Station>* station, int* n);
	void read(std::vector<Station>* station, int* n);
	void add(std::vector<Station>* station, int* n);
	void remove(std::vector<Station>* station, int* n);
	void edit(std::vector<Station>* station, int n);
	void print(std::vector<Station>* station, int n);

	void write(const vector<Ticket>& tickets);
	void create(std::vector<Ticket>& tickets, int& ticketCount);
	void read(std::vector<Ticket>& tickets, int& ticketCount);
	void add(std::vector<Ticket>& tickets, int& ticketCount);
	void remove(std::vector<Ticket>& tickets, int& ticketCount);
	void edit(std::vector<Ticket>& tickets, int& ticketCount);
}