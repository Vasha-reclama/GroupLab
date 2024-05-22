#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
#include"RusRails.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "Ru");
	time_t globalTime;
	int password;
	vector<Route> routes;
	vector<Train> trains;
	vector<Station> stations;
	vector<Ticket> tickets;
	int routesCount=0;
	int trainsCount=0;
	int stationCount=0;
	int ticketsCount=0;
	ifstream in;
	in.open("settings", ios_base::binary);
	if (!in.is_open()) {
		cout << "Файл настроек не был обнаружен, применение стандратных настроек" << endl;
		ofstream out;
		out.open("settings", ios_base::binary);
		if (!out.is_open()) {
			cout << "Что-то пошло не так" << endl;
			return 1;
		}
		password = 1234;
		out.write(reinterpret_cast<char*>(&password), sizeof(int));
		globalTime = time(NULL);
		cout << globalTime << endl;
		out.write(reinterpret_cast<char*>(&globalTime), sizeof(time_t));
		out.close();
	}
	else {
		in.read(reinterpret_cast<char*>(&password), sizeof(int));
		in.read(reinterpret_cast<char*>(&globalTime), sizeof(time_t));
		in.close();
		
	}
	tm* normalTime = localtime(&globalTime);
	cout << normalTime->tm_year+1900<<" " << normalTime->tm_mon+1<<" " << normalTime->tm_mday<<" " << normalTime->tm_hour << endl;
	
	bool work0 = true;
	while (work0) {
		cout << "1-Вход для администрации 2-Вход для пользователей" << endl;
		int key;
		if (!(cin >> key).good()) {
			cout << "syntax error" << endl;
			return 1;
		}
		switch (key)
		{
		case 1: {
			cout << "Введите пароль" << endl;
			int pasCheck;
			if (!(cin >> pasCheck).good()) {
				cout << "Syntax error" << endl;
				break;
			}
			if (pasCheck != password) {
				cout << "Пароль введен неверено" << endl;
				break;
			}
			bool work1 = true;
			while (work1) {
				int key1;
				cout << "1-Изменение настроек 2-Работа с БД" << endl;
				if (!(cin >> key1).good()) {
					cout << "Syntax error" << endl;
					break;
				}
				switch (key1)
				{
				case 1:
				{
					cout << "1-изменить пароль, 2-работа со временем" << endl;
					int key2;
					if (!(cin >> key2).good()) {
						cout << "syntax error" << endl;
						break;
					}
					switch (key2)
					{
					case 1: {
						int newPassword;
						if (!(cin >> newPassword).good()) {
							cout << "Syntax error" << endl;
							break;
						}
						password = newPassword;
						ofstream out;
						out.open("settings", ios_base::binary);
						out.write(reinterpret_cast<char*>(&password), sizeof(int));
						out.write(reinterpret_cast<char*>(&globalTime), sizeof(time_t));
						out.close();
					}
						  break;
					case 2: {
						cout << "Введите сколько добавить часов" << endl;
						int hours;
						if (!(cin >> hours).good()) {
							cout << "Syntax error" << endl;
							break;
						}
						globalTime += hours * 3600;
						normalTime = localtime(&globalTime);
						cout << normalTime->tm_year + 1900 << " " << normalTime->tm_mon + 1 << " " << normalTime->tm_mday << " " << normalTime->tm_hour << endl;
						ofstream out;
						out.open("settings", ios_base::binary);
						out.write(reinterpret_cast<char*>(&password), sizeof(int));
						out.write(reinterpret_cast<char*>(&globalTime), sizeof(time_t));
						out.close();
						for (int i = 0; i < trainsCount; i++) {
							trains[i].changeCurStation(globalTime, &routes, routesCount, &stations);
						}
						rjd::write(&trains, trainsCount);
					}
						  break;
					default:
						break;
					}
				}
				break;
				case 2: {
					bool work2 = true;
					while (work2) {
						cout << "1-Поезда 2-Маршруты 3-Станции" << endl;
						int key2;
						if (!(cin >> key2).good()) {
							cout << "Syntax error" << endl;
							break;
						}
						switch (key2)
						{
							int key3;
						case 1:
						{
							cout << "1-create 2-read 3-add 4-remove 5-edit" << endl;
							if (!(cin >> key3).good()) {
								cout << "Syntax error" << endl;
								break;
							}
							switch (key3)
							{
							case 1: {
								rjd::create(&trains, &trainsCount, globalTime, &routes, routesCount);
							}
								  break;
							case 2: {
								rjd::read(&trains, &trainsCount);
							}
								  break;
							case 3:
							{
								rjd::add(&trains, &trainsCount, globalTime, &routes, routesCount);
							}
							break;
							case 4: {
								rjd::remove(&trains, &trainsCount, &routes, routesCount);
							}
								  break;
							case 5: {
								rjd::edit(&trains, trainsCount);
							}
								  break;
							default:
								break;
							}
						}
						break;
						case 2: {
							cout << "1-create 2-read 3-add 4-remove 5-edit" << endl;
							if (!(cin >> key3).good()) {
								cout << "Syntax error" << endl;
								break;
							}
							switch (key3)
							{
							case 1: {
								rjd::create(&routes, &routesCount, &stations, stationCount);
							}
								  break;
							case 2: {
								rjd::read(&routes, &routesCount);
							}
								  break;
							
							case 3:
							{
								rjd::add(&routes, &routesCount, &stations, stationCount);
							}
							break;
							case 4: {
								rjd::remove(&routes, &routesCount);
							}
								  break;
							case 5: {
								rjd::edit(&routes, routesCount, &stations, stationCount);
							}
								  break;
								  
							default:
								break;
							}
						

						}
							  break;
						case 3: {
							cout << "1-create 2-read 3-add 4-remove 5-edit" << endl;
							if (!(cin >> key3).good()) {
								cout << "Syntax error" << endl;
								break;
							}
							switch (key3)
							{
							case 1: {
								rjd::create(&stations, &stationCount);
							}
								  break;
							case 2: {
								rjd::read(&stations, &stationCount);
							}
								  break;

							case 3:
							{
								rjd::add(&stations, &stationCount);
							}
							break;
							case 4: {
								rjd::remove(&stations, &stationCount, &routes, routesCount);
							}
								  break;
							case 5: {
								rjd::edit(&stations, stationCount);
							}
								  break;

							default:
								break;
							}
						}
						break;
						default:
							work2 = false;
							break;
						}
					}
				}
					  break;
				default:
					work1 = false;
					break;
				}
			}
		}
			  break;
		case 2: {
			if (stationCount == 0)
				rjd::read(&stations, &stationCount);
			if (routesCount == 0)
				rjd::read(&routes, &routesCount);
			if (trainsCount == 0)
				rjd::read(&trains, &trainsCount);
			Matrix matrix(stationCount, stationCount);
			for (int i = 0; i < stationCount; i++) {
				for (int j = 0; j < stationCount; j++) {
					int x = 0;
					for (int k = 0; k < stations[i].getNumAdj(); k++) {
						if (j == stations[i].getAdjacentStations()[k]) {
							x = 1;
							break;
						}
					}
					matrix[i][j] = x;
				}
			}
			Matrix powerMatrix = matrix.sumOfPowers(stationCount);
			cout << "Выберите первую станцию" << endl;
			int stA;
			int a;
			if (!(cin >> stA).good()) {
				cout << "Syntax error" << endl;
				break;
			}
			bool inside = false;
			for (int i = 0; i < stationCount; i++) {
				if (stA == stations[i].getId()) {
					a = i;
					inside = true;
					break;
				}
			}
			if (!inside) {
				cout << "error" << endl;
				break;
			}
			cout << "Выберите вторую станцию" << endl;
			int stB;
			int b;
			if (!(cin >> stB).good()) {
				cout << "Syntax error" << endl;
				break;
			}
			inside = false;
			for (int i = 0; i < stationCount; i++) {
				if (stB == stations[i].getId()) {
					b = i;
					inside = true;
					break;
				}
			}
			if (!inside) {
				cout << "error" << endl;
				break;
			}
			if (powerMatrix[a][b] == 0) {
				cout << "Не существует пути от " << stA << " до " << stB << endl;
				break;
			}
			vector<Route> correct;
			for (int i = 0; i < routesCount; i++) {
				bool insideA=false;
				bool insideB=false;
				for (int j = 0; j < routes[i].getStatinsCount(); j++) {
					if (routes[i].getStations()[j] == stA) {
						insideA = true;
					}
					else if (routes[i].getStations()[j] == stB) {
						insideB = true;
					}
				}
				if (insideA && insideB) {
					correct.push_back(routes[i]);
				}
			}
			if (correct.empty() == true) {
				cout << "В данный момент не существует маршрута для соответсвующих станций" << endl;
				break;
			}
			vector<Train*> fin;
			for (int i = 0; i < correct.size(); i++) {
				bool inside=false;
				for (int j = 0; j < correct[i].getTrainsCount(); j++) {
					for (int k = 0; k < trainsCount; k++) {
						if (trains[k].getId() == correct[i].getTrains()[j]) {
							inside = true;
							Train* temp = trains[k].getPasAndTime(&tickets, ticketsCount, &stations, stationCount, &routes, routesCount, stA, stB);
							fin.push_back(temp);
							break;
						}
					}
					/*if (inside)
						break;*/
				}
			}
			cout << "Выберите поезд" << endl;
			int trainId;
			if (!(cin >> trainId).good()) {
				cout << "Syntax error" << endl;
				break;
			}
			inside = false;
			for (int i = 0; i < fin.size(); i++) {
				if (fin[i]->getId() == trainId) {
					inside = true;
					break;
				}
			}
			if (!inside) {
				cout << "error" << endl;
				break;
			}
			Ticket newTicket;
			cin >> newTicket;
			rjd::add(&tickets, &ticketsCount, newTicket);
		}
			  break;
		default:
			break;
		}
	}
}

