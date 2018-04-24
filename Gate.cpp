#include "Gate.h"
#include "Wire.h"

Gate::Gate(string t, int d, Wire *i1, Wire *i2, Wire *o) {
	type = t;
	delay = d;
	in1 = i1;
	in2 = i2;
	out = o;
}

string Gate::getType() const {
	return type;
}

int Gate::getDelay() const {
	return delay;
}

Wire * Gate::getIn1() const {
	return in1;
}

Wire * Gate::getIn2() const {
	return in2;
}

Wire * Gate::getOut() const {
	return out;
}

string Gate::gateLogic() {
	if (this->getType() == "AND") {
		if (in1->getVal() == "1" && in2->getVal() == "1") {
			return "1";
		}
		else if (in1->getVal() == "0" || in2->getVal() == "0") {
			return "0";
		}
		else {
			return "X";
		}
	}
	else if (this->getType() == "OR") {
		if (in1->getVal() == "1" || in2->getVal() == "1") {
			return "1";
		}
		else if (in1->getVal() == "0" && in2->getVal() == "0") {
			return "0";
		}
		else {
			return "X";
		}
	}
	else if (this->getType() == "NOT") {
		if (in1->getVal() == "0") {
			return "1";
		}
		else if (in1->getVal() == "1") {
			return "0";
		}
		else {
			return "X";
		}
	}
	else if (this->getType() == "NAND") {
		if (in1->getVal() == "1" && in2->getVal() == "1") {
			return "0";
		}
		else if (in1->getVal() == "0" || in2->getVal() == "0") {
			return "1";
		}
		else {
			return "X";
		}
	}
	else if (this->getType() == "NOR") {
		if (in1->getVal() == "1" || in2->getVal() == "1") {
			return "0";
		}
		else if (in1->getVal() == "0" && in2->getVal() == "0") {
			return "1";
		}
		else {
			return "X";
		}
	}
	else if (this->getType() == "XOR") {
		if (in1->getVal() == "1" && in2->getVal() == "0") {
			return "1";
		}
		else if (in1->getVal() == "0" && in2->getVal() == "1") {
			return "1";
		}
		else if (in1->getVal() == "X" || in2->getVal() == "X") {
			return "X";
		}
		else {
			return "0";
        }
	}
	else if (this->getType() == "XNOR") {
		if (in1->getVal() == "1" && in2->getVal() == "0") {
			return "0";
		}
		else if (in1->getVal() == "0" && in2->getVal() == "1") {
			return "0";
		}
		else if (in1->getVal() == "X" || in2->getVal() == "X") {
			return "X";
		}
		return "1";
	}
}

bool Gate::outputChange() {
	if (out->getVal() == gateLogic()) {
		return false;
	}
	else {
		return true;
	}
}
