#ifndef GATE_H
#define GATE_H
#include <iostream>
#include "Event.h"

using namespace std;

class Wire;

class Gate {
	public:
		//constructor
		Gate(string t, int d, Wire *i1, Wire *i2, Wire *o);

		//member functions
		//getters
		string getType() const;
		int getDelay() const;
		Wire * getIn1() const;
		Wire * getIn2() const;
		Wire * getOut() const;

		string gateLogic();
		bool outputChange();

	private:
		string type;
		int delay;
		Wire *in1, *in2;
		Wire *out;
};

#endif