#include "Wire.h"

//constructor
Wire::Wire(int v, vector<Gate *> d, string n, vector<string> h, int i) {
	val = v;
	drives = d;
	name = n;
	history = h;
	index = i;
}

Wire::Wire(string n, int i) {
	name = n;
	index = i;
}

//getters
string Wire::getVal() const {
	return val;
}

vector<Gate *> Wire::getDrives() const {
	return drives;
}

string Wire::getName() const {
	return name;
}

vector<string> Wire::getHistory() const {
	return history;
}

int Wire::getIndex() const {
	return index;
}

//setters
void Wire::setVal(string v) {
	val = v;
}

void Wire::setDrives(Gate *d) {
	drives.push_back(d);
}

void Wire::setName(string n) {
	name = n;
}

void Wire::setHistory(string h) {
	history.push_back(h);
}

void Wire::setIndex(int i) {
	index = i;
}

void Wire::print() {
	vector<string> h;
	h = getHistory();
	for (int i = 0; i < h.size(); i++) {
		if (h.at(i) == "X") {
			cout << "X";
		}
		else if (h.at(i) == "0") {
			cout << "_";
		}
		else if (h.at(i) == "1") {
			cout << "-";
		}
	}
}