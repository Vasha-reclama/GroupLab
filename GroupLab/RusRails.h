#pragma once


class Station {
private:
	unsigned int id;
	char name[40] = {};
	int con[5] = {-1,-1,-1,-1,-1}; // ����������, -1 ��������, ��� ��� �����
	int dis[5] = {}; // ���������, 0 ��������, ��� ��� �����
public:
	friend std::istream& operator >>(std::istream& in, Station& r);
	friend std::ostream& operator <<(std::ostream& out, const Station& r);
	void setId(int x);
	int getId();
	int* getCon();
	int* getDis();
	void getTrainsList();
};

class Path {
private:
	unsigned int id;
	int trains[10] = {};//������ ������������� �������
	int stations[20] = {};//�������
public:
	friend std::istream& operator >>(std::istream& in, Path& r);
	friend std::ostream& operator <<(std::ostream& out, const Path& r);
	void setId(int x);//
	int getId();//��������� Id ��������
	int* getTrains();//
	int* getStations();
};

class Train {
private:
	unsigned id;
	short limit;
	tm start = {};
	int curSt; //�� � �� �����, � ��� ��� ��� ���������.............
	int path;
public:
	friend std::istream& operator >>(std::istream& in, Train& r);
	friend std::ostream& operator <<(std::ostream& out, const Train& r);
	void setId(int x);
	int getId();
	int getLim();
	std::time_t getStart();
	int getPath();
	void setPath();
	int getCurStation();
	void changeCurStation(int x);
};

class Ticket {
private:
	unsigned int id;
	char name[40] = {};//������� 40 �������� ��� ��� ������, �������
	int startSt;
	int trainId;
	int finish;
public:
	friend std::istream& operator >>(std::istream& in, Ticket& r);
	friend std::ostream& operator <<(std::ostream& out, const Ticket& r);
	void setId(int x);
	int getId();
	int getStart();
	int getFinish();
	int getTrain();
};