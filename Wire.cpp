#include "Wire.h"
#include <string>

//constructor
Wire::Wire(string v, vector<Gate *> d, string n, string h, int i) {
	val = v;
	drives = d;
	name = n;
	history = h;
	index = i;
}

Wire::Wire(string n, int i, string v) {
	name = n;
	index = i;
	val = v;
}

//getters
string Wire::getVal() const {
	return val;
}

vector<Gate *> Wire::getDrives() const {
	return drives;
}

string Wire::getWireName() const {
	return name;
}

string Wire::getHistory() const {
	return history;
}

int Wire::getIndex() const {
	return index;
}

//setters
void Wire::setVal(int time, string v, string oldVal) {
	val = v;
	setHistory(time, oldVal);
}

void Wire::addDrive(Gate *d) {
	drives.push_back(d);
}

void Wire::setName(string n) {
	name = n;
}

void Wire::setHistory(int time, string h) {
	for (int i = 0; i < time; ++i) {
		history += h;
	}
}

void Wire::setIndex(int i) {
	index = i;
}

void Wire::print() {
	string h = getHistory();
	cout << getWireName();
	for (int i = 0; i < h.length(); i++) {
		if (h.at(i) == 'X') {
			cout << "X";
		}
		else if (h.at(i) == '0') {
			cout << "_";
		}
		else if (h.at(i) == '1') {
			cout << "-";
		}
	}
	cout << endl;
}