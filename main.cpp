#include "Gate.h"
#include "Wire.h"
#include "Event.h"
#include "Queue.h"
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>

Wire *findID(vector <Wire *> wires, int wireNum);

int main() {
    string filename;
    string vectorFileName;
    ifstream inFS;
    string circName;


    vector <Gate *> gates;
    vector <Wire *> wires;
    vector <Event *> e;
    

    cout << "Please enter the full name of the circuit file. (ex: 'circuit0')" << endl;
    cin >> filename;

    vectorFileName = filename;
    filename += ".txt";
    vectorFileName += "_v.txt";

    inFS.open(filename);
        if (!inFS.is_open()) {
            cout << "Could not open the file  " << filename << "." << endl;
            return 1;
        }

    while(!inFS.eof()) {
        string type;
        inFS >> type;
        if (type.compare("CIRCUIT") == 0) {
            inFS >> circName;
            continue;
        }
        if (type.compare("INPUT") == 0 || type.compare("OUTPUT") == 0) {
            string wireName;
            int wireNum;
            inFS >> wireName >> wireNum;
            wires.push_back(new Wire(wireName, wireNum));
            continue;
        }
        string dummy;
        string gateType;
        int delay, input1 = 0, input2 = 0, output;
        Wire *w1, *w2, *out;
        inFS >> delay >> dummy >> input1;
        if (type.compare("NOT") != 0) {
            inFS >> input2;
        }
        inFS >> output;
        if (findID(wires, w1->getIndex()) != nullptr) {
            
        }

//        gates.push_back(new Gate(gateType, delay, input1, input2, output));
    }
    


    //NOTE: Create a helper function that searches through the vector of Wires to find it by its ID number
    //NOTE: remember your using pointers, so use the ->
    //Use that function to take the index you got from the file to grab the corresponding wire that was created
    //NOTE: If you search for an index but didn't get a wire (for the wires between gates)
    //create a wire and insert it into the wire vector, continue to use that wire and connect it up like normal
    
    inFS.close();

    cout << "Please enter the full name of the vector circuit file. (ex: 'circuit0_v.txt')" << endl;
    cin >> vectorFileName;

    inFS.open(vectorFileName);
        if (!inFS.is_open()) {
            cout << "Could not open the file  " << vectorFileName << "." << endl;
            return 1;
        }

    while(!inFS.eof()) {
        string type;
        inFS >> type;
		string wire;
		int time;
		string val;
        int count = 0;
        if (type.compare("INPUT") == 0) {
            inFS >> wire >> time >> val;
            e.push_back(new Event(wire, time, val, count));
            //Event push(Event //e(wire, time, val, count));
        }
    }

    inFS.close();

    Queue q(e->at(0));
    for (int i = 0; i < e.size(); i++) {
        
    }

	return 0;
}

Wire *findID(vector <Wire *> wires, int wireNum) {
    for(int i = 0; i < wires.size(); i++) {
        Wire *tempWire = wires.at(i);
        if (tempWire -> getIndex == wireNum) {
            return tempWire;
        }
    }    
    return nullptr;
}

