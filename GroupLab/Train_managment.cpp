#include "RusRails.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

namespace rjd {
    void writeTrains(vector<Train>* trains, int n) {
        ofstream out;
        out.open("trains", ios_base::binary);
        if (!out.is_open()) {
            cout << "cant open file" << endl;
            return;
        }
        out.write(reinterpret_cast<char*>(&n), sizeof(int));
        out.write(reinterpret_cast<char*>(&(trains->at(0))), sizeof(Train) * n);
        out.close();
    }

    void createTrains(vector<Train>* trains, int* n) {
        cout << "n=";
        if (!(cin >> (*n)).good()) {
            cout << "Syntaxis error" << endl;
            return;
        }
        trains->resize((*n));
        for (int i = 0; i < *n; i++) {
            Train temp;
            if (!(cin >> temp).good()) {
                cout << "���-�� ����� �� ���" << endl;
                return;
            }
            temp.setId = i;
            trains->at(i) = temp;
        }
        writeTrains(trains, *n);
    }

    void printTrains(vector<Train>* trains, int n) {
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << trains->at(i) << endl;
        }
    }

    void readTrains(vector<Train>* trains, int* n) {
        ifstream in;
        in.open("trains", ios_base::binary);
        if (!in.is_open()) {
            cout << "���� �� ��� ������ ���������" << endl;
            return;
        }
        in.read(reinterpret_cast<char*>(n), sizeof(int));
        trains->resize(*n);
        in.read(reinterpret_cast<char*>(&(trains->at(0))), sizeof(Train) * (*n));
        printTrains(trains, *n);
    }

    void addTrain(vector<Train>* trains, int* n) {
        Train temp;
        if (!(cin >> temp).good()) {
            cout << "���-�� ����� �� ���" << endl;
            return;
        }
        trains->push_back(temp);
        (*n)++;
        writeTrains(trains, *n);
    }

    void removeTrain(vector<Train>* trains, int* n) {
        printTrains(trains, *n);
        cout << "�������� ����� ��� ��������" << endl;
        int id;
        if (!(cin >> id).good()) {
            cout << "Synctaxis error" << endl;
            return;
        }
        int x = -1;
        for (int i = 0; i < *n; i++) {
            if (trains->at(i).getId() == id) {
                x = i;
                break;
            }
        }
        if (x == -1) {
            cout << "Search failed" << endl;
            return;
        }
        trains->erase(trains->begin() + x);
        (*n)--;
        writeTrains(trains, *n);
    }

    void editTrain(vector<Train>* trains, int n) {
        printTrains(trains, n);
        cout << "�������� ����� ��� ��������������" << endl;
        int id;
        if (!(cin >> id).good()) {
            cout << "Synctaxis error" << endl;
            return;
        }
        Train* temp = nullptr;
        for (int i = 0; i < n; i++) {
            if (trains->at(i).getId() == id) {
                temp = &(trains->at(i));
                break;
            }
        }
        if (temp == nullptr) {
            cout << "input error" << endl;
            return;
        }
        cout << *temp << endl;
        cout << "��� �������������: " << endl;
        cout << "1 - ����� ���������  " << endl;
        cout << "������� ������ = ";
        int key;
        if (!(cin >> key).good()) {
            cout << "Syntaxis error" << endl;
            return;
        }
        if (key == 1) {
            cout << "������� ����� ��������� �� 1 �� 50: " << endl;//����������, ����� ����� ������ ������� �������
            int x;
            if (!(cin >> x).good()) {
                cout << "Syntaxis error" << endl;
                return;
            }
            if (x > 50 || x < 1) {
                cout << "������� ����� �� ��������� " << endl;
                return;
            }
        }




        // ���������� �������������� ������ � ������������ � ������ ������������
        // ��������, ������ ������������ � �������������� ���������� �����
        // � ���������� ��������������� ����� ������
        // ����� ����� writeTrains ��� ���������� ���������� � �����
    }
}
