#include<iostream>
#include<vector>
#include<ctime>

#include"RusRails.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	vector<Route> routes;

	StationManager stationManager;

	stationManager.addStation("Station A", 10);
	stationManager.addStation("Station B", 20);

	std::cout << "Stations:" << std::endl;
	stationManager.printStations();

	stationManager.editStation(0, "Station A (edited)", 15);

	std::cout << "\nStations after editing:" << std::endl;
	stationManager.printStations();

	stationManager.deleteStation(1);
	stationManager.addStation("Station C", 25);

	std::cout << "\nStations after del:" << std::endl;
	stationManager.printStations();

	// сохранить
	rjd::saveStations(stationManager, "station_data.dat");
	// загрузить
	StationManager stationManagerLoad;
	rjd::loadStations(stationManagerLoad, "station_data.dat");
	std::cout << "\nStations after SAVE and LOAD:" << std::endl;
	stationManagerLoad.printStations();


	int routesCount;
	//rjd::create(&routes, &routesCount);
	rjd::read(&routes, &routesCount);
	rjd::edit(&routes, routesCount);
}

