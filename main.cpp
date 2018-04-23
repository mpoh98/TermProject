//AUTHORS: MATTHEW OH & KYLE TILLINGHAST
//Term Project CS1220 Object-Oriented
//CEDARVILLE UNIVERSITY
//Spring 2018
//Professor: Dr. Shomper

#include "Gate.h"
#include "Wire.h"
#include "Event.h"
#include "Queue.h"
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>

Wire *findByIdOrCreate(vector <Wire *> &wires, int wireNum);


int main() {
    string filename;
    string vectorFileName;
    ifstream inFS;
    string circName;


    vector <Gate *> gates;
    vector <Wire *> wires;
    vector <Event *> e;
    
//Parse both the circuit and vector circuit files

//parse the circuit file
    cout << "Please enter the full name of the circuit file. (ex: 'circuit0')" << endl;
    cin >> filename;

//appends .txt to the filenames
    vectorFileName = filename;
    filename += ".txt";
    vectorFileName += "_v.txt";

    inFS.open(filename);
    //error message and exit if the file could not be opened
        if (!inFS.is_open()) {
            cout << "Could not open the file  " << filename << "." << endl;
            return 1;
        }
//iterates through the file until the end of the file
    while(!inFS.eof()) {
        string type;
        inFS >> type;
    //grabs the name of the circuit
        if (type.compare("CIRCUIT") == 0) {
            inFS >> circName;
            continue;
        }
    //grabs the inputs and outputs
        if (type.compare("INPUT") == 0 || type.compare("OUTPUT") == 0) {
            string wireName;
            int wireNum;
            inFS >> wireName >> wireNum;
            wires.push_back(new Wire(wireName, wireNum));
            continue;
        }
    //grabs the gates and its inputs and outputs, gets rid of the "ns" for the timing
        string dummy;
        string gateType;
        int delay, input1 = 0, input2 = 0, output;
        Wire *w1 = nullptr, *w2 = nullptr, *out = nullptr;
        inFS >> delay >> dummy >> input1;
    //grabs the NOT gate slightly differently due to only 1 input and output
        if (type.compare("NOT") != 0) {
            inFS >> input2;
            w2 = findByIdOrCreate(wires, input1);
        }
        inFS >> output;
        w1 = findByIdOrCreate(wires, input1);
        out = findByIdOrCreate(wires, output);
        Gate *gate = new Gate(gateType, delay, w1, w2, out);
        w1->addDrive(gate);
        w2->addDrive(gate);
        gates.push_back(gate);
    }
    
//close the file
    inFS.close();

//parse the vector circuit file
    cout << "Please enter the full name of the vector circuit file. (ex: 'circuit0_v.txt')" << endl;
    cin >> vectorFileName;

    inFS.open(vectorFileName);
    //error message and exit if the file could not be opened
        if (!inFS.is_open()) {
            cout << "Could not open the file  " << vectorFileName << "." << endl;
            return 1;
        }
 //iterates through the file until the end of the file
    while(!inFS.eof()) {
        string type;
        inFS >> type;
		string wire;
		int time;
		string val;
        int count = 0;
    //grabs the inputs with their wire name, time, and value
        if (type.compare("INPUT") == 0) {
            inFS >> wire >> time >> val;
        //pushes the inputs into a new Event
            e.push_back(new Event(wire, time, val, count));
        }
    }
//close the file
    inFS.close();

//push the events into the queue
    Queue q(e.at(0));
    for (int i = 0; i < e.size(); i++) {
        
    }

	return 0;
}

//Function to find and set a wire, if the wire is not there (example, wires between gates)
//create that wire and push it into the vector
Wire *findByIdOrCreate(vector <Wire *> &wires, int wireNum) {
    Wire *tempWire = nullptr;
    for(int i = 0; i < wires.size(); i++) {
        tempWire = wires.at(i);
        if (tempWire -> getIndex == wireNum) {
            return tempWire;
        }
    }
    tempWire = new Wire("", wireNum);
    wires.push_back(tempWire);
    return tempWire;
}

