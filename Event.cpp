#include "Event.h"

//constructor
Event::Event(string w, int t, string v, int c) {
	wire = w;
	time = t;
	val = v;
	cnt = c;
}

//getters
string Event::getWire() const {
	return wire;
}

int Event::getTime() const {
	return time;
}

string Event::getVal() const {
	return val;
}

int Event::getCnt() const {
	return cnt;
}

//setters
void Event::setWire(string w) {
	wire = w;
}

void Event::setTime(int t) {
	time = t;
}

void Event::setVal(int v) {
	val = v;
}

void Event::setCnt(int c) {
	cnt = c;
}
