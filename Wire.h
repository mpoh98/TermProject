#ifndef WIRE_H
#define WIRE_H
#include <iostream>
#include <vector>

using namespace std;


class Gate;

class Wire {
	public:
		// constructor
		Wire(string v, vector<Gate *> d, string n, string h, int i);
		Wire(string n, int i, string v = "X");

		// member functions
		//getters
		string getVal() const;
		vector<Gate *> getDrives() const;
		string getWireName() const;
		string getHistory() const;
		int getIndex() const;
		
		//setters
		void setVal(int time, string v);
		void addDrive(Gate *d);
		void setName(string n);
		void setHistory(int time);
		void setIndex(int i);

		void print();
	private:
		string val;
		vector<Gate *> drives;
		string name;
		string history;
		int index;
		int timeOfLastEvent = 0;
};

#endif