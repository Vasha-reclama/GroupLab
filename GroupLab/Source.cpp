#include<iostream>
#include<vector>
#include<ctime>

#include"RusRails.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	vector<Route> routes;
	int routesCount;
	//rjd::create(&routes, &routesCount);
	rjd::read(&routes, &routesCount);
	rjd::edit(&routes, routesCount);
}

