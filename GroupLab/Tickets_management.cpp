#include "RusRails.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

namespace rjd {
    const char* filename = "tickets.dat";

    void write(const vector<Ticket>* tickets, int n) {
        ofstream out(filename, ios_base::binary);
        if (!out.is_open()) {
            cout << "�� ������� ������� ���� ��� ������." << endl;
            return;
        }
        out.write(reinterpret_cast<const char*>(&n), sizeof(int));
        out.write(reinterpret_cast<const char*>(&(tickets->at(0))), sizeof(Ticket) * n);
        out.close();
    }

    void read(std::vector<Ticket>* tickets, int* ticketCount) {
        ifstream in(filename, ios_base::binary);
        if (!in.is_open()) {
            cout << "�� ������� ������� ���� ��� ������." << endl;
            return;
        }
        in.read(reinterpret_cast<char*>(ticketCount), sizeof(int));
        tickets->resize(*ticketCount);
        in.read(reinterpret_cast<char*>(&(tickets->at(0))), sizeof(Ticket) * *ticketCount);
        in.close();
    }

    void create(vector<Ticket>* tickets, int* ticketCount) {
        cout << "������� ���������� �������: ";
        if (!(cin >> *ticketCount).good()) {
            cout << "Syntax error" << endl;
            return;
        }
        tickets->resize(*ticketCount);
        for (int i = 0; i < *ticketCount; ++i) {
            cout << "������� ������ ��� ������ " << i + 1 << ":\n";
            Ticket temp;
            if (!(cin >> temp).good()) {
                cout << "Syntax error" << endl;
                return;
            }
        }
        write(tickets, *ticketCount);
    }

    void add(vector<Ticket>* tickets, int* ticketCount) {
        Ticket newTicket;
        cout << "������� ������ ��� ������ ������:"<<endl;
        if (!(cin >> newTicket).good()) {
            cout << "Syntax error" << endl;
            return;
        }
        tickets->push_back(newTicket);
        (*ticketCount)++;
        write(tickets, *ticketCount);
    }

    void remove(vector<Ticket>* tickets, int* ticketCount) {
        int ticketId;
        cout << "������� ����� ������ ��� ��������: " << endl;
        if (!(cin >> ticketId).good()) {
            cout << "Syntax error" << endl;
            return;
        }
        auto it = remove_if(tickets->begin(), tickets->end(), [ticketId](Ticket& t) { return t.getId() == ticketId; });//����� ���� ������� �����������, � ��� ������ �� ����
        if (it != tickets->end()) {
            tickets->erase(it, tickets->end());
            --(*ticketCount);
            write(tickets, *ticketCount);
            cout << "����� ������." << endl;
        }
        else {
            cout << "����� � ����� ������� �� ������." << endl;
        }
    }

    void edit(std::vector<Ticket>* tickets, int ticketCount) {
        int ticketId;
        cout << "������� ����� ������ ��� ��������������: ";
        if (!(cin >> ticketId).good()) {
            cout << "Syntax error" << endl;
            return;
        }
        auto it = find_if(tickets->begin(), tickets->end(), [ticketId](Ticket& t) { return t.getId() == ticketId; });
        if (it != tickets->end()) {
            cout << "������� ����� ������ ��� ������:"<<endl;
            if (!(cin >> *it).good()) {
                cout<<"Syntax error"<<endl;
                return;
            }
            write(tickets, ticketCount);
            cout << "����� ��������������." << endl;
        }
        else {
            cout << "����� � ����� ������� �� ������." << endl;
        }
    }
}