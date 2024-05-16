#include<iostream>
#include<vector>
#include<ctime>

#include"RusRails.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	vector<Route> routes;
	vector<Station> station;

	int routesCount;
	//rjd::create(&routes, &routesCount);
	rjd::read(&routes, &routesCount);
	rjd::edit(&routes, routesCount);

	int stationCount = 0;
	//rjd::create(&station, &stationCount);
	rjd::read(&station, &stationCount);
	//rjd::add(&station, &stationCount);
	//rjd::remove(&station, &stationCount);
	rjd::edit(&station, stationCount);

	int routesCount;
	//	rjd::create(&routes, &routesCount);
	rjd::read(&routes, &routesCount);
	rjd::edit(&routes, routesCount);
}

