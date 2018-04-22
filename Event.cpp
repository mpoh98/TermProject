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

void Event::print() {
	/*for (int i = 0; i < t.size(); i++) {
		if (t.at(i) == 5) {
			cout << "5";
		}
		else if (t.at(i) == 10) {
			cout << "10";
		}
		else if (t.at(i) == 15) {
			cout << "15";
		}
		else if (t.at(i) == 20) {
			cout << "20";
		}			
		else if (t.at(i) == 25) {
			cout << "25";
		}
		else if (t.at(i) == 30) {
			cout << "30";
		}
		else if (t.at(i) == 35) {
			cout << "35";
		}
		else if (t.at(i) == 40) {
			cout << "40";
		}
		else if (t.at(i) == 45) {
			cout << "45";
		}
		else if (t.at(i) == 50) {
			cout << "50";
		}
		else if (t.at(i) == 55) {
			cout << "55";
		}
		else if (t.at(i) == 60) {
			cout << "60";
		}													
		else 
			cout << " ";
	}*/
}