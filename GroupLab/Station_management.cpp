#include "RusRails.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void rjd::saveStations(StationManager& s, const std::string& filename) {
	std::ofstream file(filename, std::ios::binary);

	if (file.is_open()) {
		if (s.getSize() == 0)
		{
			cout << "нет станций\n";
			return;
		}
		file.write(reinterpret_cast<char*>(&s), sizeof(StationManager));
		file.close();
	}
	else {
		std::cerr << "Ошибка открытия файла для записи!" << std::endl;
	}
}

void rjd::loadStations(StationManager& s, const std::string& filename) {
	std::ifstream file(filename, std::ios::binary);

	if (file.is_open()) {
		file.read(reinterpret_cast<char*>(&s), sizeof(StationManager));
		file.close();
	}
	else {
		std::cerr << "Ошибка открытия файла для чтения!" << std::endl;
	}
}

