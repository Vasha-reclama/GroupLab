#include "RusRails.h"
#include <fstream>
#include <iostream>
using namespace std;

void addRoute(const Route& route) {
    ofstream file("routes.dat", ios::binary | ios::app);
    if (!file.is_open()) {
        cout << "Error opening file for writing" << endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(&route), sizeof(Route));
    file.close();
}

void deleteRoute(int routeId) {
    ifstream inFile("routes.dat", ios::binary);
    if (!inFile.is_open()) {
        cout << "Error opening file for reading" << endl;
        return;
    }
    ofstream outFile("temp.dat", ios::binary);
    if (!outFile.is_open()) {
        cout << "Error opening temporary file for writing" << endl;
        inFile.close();
        return;
    }

    Route route;
    while (inFile.read(reinterpret_cast<char*>(&route), sizeof(Route))) {
        if (route.getId() != routeId) {
            outFile.write(reinterpret_cast<const char*>(&route), sizeof(Route));
        }
    }

    inFile.close();
    outFile.close();

    remove("routes.dat");
    rename("temp.dat", "routes.dat");
}