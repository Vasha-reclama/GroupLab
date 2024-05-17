#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include"RusRails.h"

using namespace std;
namespace ticket {
    void createDatabase(const char* filename) {
        ofstream file(filename, ios::out | ios::binary);
    }

    void readDatabase(const char* filename) {
        ifstream file(filename, ios::in | ios::binary);
        if (!file) {
            cout << "Error opening file for reading." << endl;
            return;
        }

        Ticket ticket;
        while (file.read((char*)&ticket, sizeof(Ticket))) {
            cout << "Номер билета: " << ticket.getId() << endl;
            cout << "Откуда отбывает: " << ticket.getStart() << endl;
            cout << "Куда направляется: " << ticket.getFinish() << endl;
            cout << "Номер поезда:" << ticket.getTrain() << endl;
            cout << endl;
        }
        file.close();
    }

    void addTicket(const char* filename, const Ticket& newTicket) {
        ofstream file(filename, ios::out | ios::binary | ios::app);
        if (!file) {
            cout << "Error opening file for writing." << endl;
            return;
        }

        file.write((char*)&newTicket, sizeof(Ticket));
        file.close();
    }

    void deleteTicket(const char* filename, int ticketNumberToDelete) {
        ifstream inFile(filename, ios::in | ios::binary);
        if (!inFile) {
            cout << "Error opening file for reading." << endl;
            return;
        }

        ofstream outFile("temp.dat", ios::out | ios::binary);
        if (!outFile) {
            cout << "Error opening temp file for writing." << endl;
            inFile.close();
            return;
        }

        Ticket ticket;
        while (inFile.read((char*)&ticket, sizeof(Ticket))) {
            if (ticket.getId() != ticketNumberToDelete) {
                outFile.write((char*)&ticket, sizeof(Ticket));
            }
        }

        inFile.close();
        outFile.close();

        remove(filename);
        rename("temp.dat", filename);
    }

    void editTicket(const char* filename, int ticketNumberToEdit, const Ticket& updatedTicket) {
        ifstream inFile(filename, ios::in | ios::binary);
        if (!inFile) {
            cout << "Error opening file for reading." << endl;
            return;
        }

        ofstream outFile("temp.dat", ios::out | ios::binary);
        if (!outFile) {
            cout << "Error opening temp file for writing." << endl;
            inFile.close();
            return;
        }

        Ticket ticket;
        bool found = false;
        while (inFile.read((char*)&ticket, sizeof(Ticket))) {
            if (ticket.getId() == ticketNumberToEdit) {
                outFile.write((char*)&updatedTicket, sizeof(Ticket));
                found = true;
            }
            else {
                outFile.write((char*)&ticket, sizeof(Ticket));
            }
        }

        inFile.close();
        outFile.close();

        remove(filename);
        rename("temp.dat", filename);

        if (!found) {
            cout << "Билет с номером " << ticketNumberToEdit << " не найден." << endl;
        }
    }
}