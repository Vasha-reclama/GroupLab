#include "RusRails.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

namespace rjd {
    const char* filename = "tickets.dat";

    void write(const vector<Ticket>& tickets) {
        ofstream out(filename, ios::binary);
        if (!out.is_open()) {
            cout << "�� ������� ������� ���� ��� ������." << endl;
            return;
        }
        int n = tickets.size();
        out.write(reinterpret_cast<const char*>(&n), sizeof(int));
        out.write(reinterpret_cast<const char*>(&tickets[0]), sizeof(Ticket) * n);
        out.close();
    }

    void read(std::vector<Ticket>& tickets, int& ticketCount) {
        ifstream in(filename, ios::binary);
        if (!in.is_open()) {
            cout << "�� ������� ������� ���� ��� ������." << endl;
            return;
        }
        int n;
        in.read(reinterpret_cast<char*>(&n), sizeof(int));
        tickets.resize(n);
        in.read(reinterpret_cast<char*>(&tickets[0]), sizeof(Ticket) * n);
        in.close();
    }

    void create(vector<Ticket>& tickets, int& ticketCount) {
        cout << "������� ���������� �������: ";
        cin >> ticketCount;
        tickets.resize(ticketCount);
        for (int i = 0; i < ticketCount; ++i) {
            cout << "������� ������ ��� ������ " << i + 1 << ":\n";
            cin >> tickets[i];
        }
        write(tickets);
    }

    void add(vector<Ticket>& tickets, int& ticketCount) {
        Ticket newTicket;
        cout << "������� ������ ��� ������ ������:\n";
        cin >> newTicket;
        tickets.push_back(newTicket);
        ++ticketCount;
        write(tickets);
    }

    void remove(vector<Ticket>& tickets, int& ticketCount) {
        int ticketId;
        cout << "������� ����� ������ ��� ��������: ";
        cin >> ticketId;
        auto it = remove_if(tickets.begin(), tickets.end(), [ticketId](Ticket& t) { return t.getId() == ticketId; });
        if (it != tickets.end()) {
            tickets.erase(it, tickets.end());
            --ticketCount;
            write(tickets);
            cout << "����� ������." << endl;
        }
        else {
            cout << "����� � ����� ������� �� ������." << endl;
        }
    }

    void edit(std::vector<Ticket>& tickets, int& ticketCount) {
        int ticketId;
        cout << "������� ����� ������ ��� ��������������: ";
        cin >> ticketId;
        auto it = find_if(tickets.begin(), tickets.end(), [ticketId](Ticket& t) { return t.getId() == ticketId; });
        if (it != tickets.end()) {
            cout << "������� ����� ������ ��� ������:\n";
            cin >> *it;
            write(tickets);
            cout << "����� ��������������." << endl;
        }
        else {
            cout << "����� � ����� ������� �� ������." << endl;
        }
    }
}