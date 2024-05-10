/*#include "RusRails.h"  //Этот файл не нужен, всё можно написать в Station.cpp , чтобы было удобнее
#include <fstream>
#include <iostream>
using namespace std;

void addStation(const Station& station) {
    ofstream file("stations.dat", ios::binary | ios::app);
    if (!file.is_open()) {
        cout << "Error opening file for writing" << endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(&station), sizeof(Station));
    file.close();
}

void deleteStation(int stationId) {
   ifstream inFile("stations.dat", ios::binary);
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

    Station station;
    while (inFile.read(reinterpret_cast<char*>(&station), sizeof(Station))) {
        if (station.getId() != stationId) {
            outFile.write(reinterpret_cast<const char*>(&station), sizeof(Station));
        }
    }

    inFile.close();
    outFile.close();

    remove("stations.dat");
    rename("temp.dat", "stations.dat");
}
*/
