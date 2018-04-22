#include "Wire.h"

//constructor
Wire::Wire(int v, vector<Gate *> d, string n, string h, int i) {
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

string Wire::getHistory() const {
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
	history = h;
}

void Wire::setIndex(int i) {
	index = i;
}
