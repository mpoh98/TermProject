//AUTHORS: MATTHEW OH & KYLE TILLINGHAST
//Term Project CS1220 Object-Oriented
//CEDARVILLE UNIVERSITY
//Spring 2018
//Professor: Dr. Shomper

//tessting 123
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
	Queue q;
    
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
       if (!inFS) {
            string data;
            inFS >> data;
            cout << "Could not open the FILE  " << filename << "." << endl;
            return 1;
        } else {
            cout << "File was opened\n";
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
        int delay, input1 = 0, input2 = 0, output;
        Wire *w1 = nullptr, *w2 = nullptr, *out = nullptr;
        inFS >> delay >> dummy >> input1;
    //grabs the NOT gate slightly differently due to only 1 input and output
        if (type.compare("NOT") != 0) {
            inFS >> input2;
            w2 = findByIdOrCreate(wires, input2);
        }
        inFS >> output;
        w1 = findByIdOrCreate(wires, input1);
        out = findByIdOrCreate(wires, output);
        Gate *gate = new Gate(type, delay, w1, w2, out);
        w1->addDrive(gate);
        if (w2 != nullptr) {
            w2->addDrive(gate);
        }
        gates.push_back(gate);
    }

//close the file
    inFS.close();

//parse the vector circuit file
    inFS.open(vectorFileName);
    //error message and exit if the file could not be opened
        if (!inFS.is_open()) {
            cout << "Could not open the file  " << vectorFileName << "." << endl;
            return 1;
        }
 //iterates through the file until the end of the file
    int count = 0;
    while(!inFS.eof()) {
        string type;
        inFS >> type;
		string wire;
		int time;
		string val;

    //grabs the inputs with their wire name, time, and value
        if (type.compare("INPUT") == 0) {
            inFS >> wire >> time >> val;
        //pushes the inputs into a new Event
            q.push(Event(wire, time, val, count++));
        }
    }
//close the file
    inFS.close();

	while (!q.empty() && count <= 60) {
		Event event = q.pop(); // pop off top event
		string wireName = event.getWire(); //find the wire effected by the event
		string val = event.getVal(); // get the value that the affected wire is being changed to
		for (int i = 0; i < wires.size(); ++i) {
			if (wireName == wires.at(i)->getWireName()) { // find the actual wire being affected in the wires vector
				wires.at(i)->setVal(event.getTime(), val); // set the value of the wire
				for (int j = 0; j < wires.at(i)->getDrives().size(); ++j) { // finding the driven gates of the wire
						Gate g = *wires.at(i)->getDrives().at(j);
						if (g.outputChange()) { // if there is an output change...
							string outputName = g.getOut()->getWireName(); // get the output wire affected
							q.push(Event(outputName, event.getTime() + g.getDelay(), g.gateLogic(), count++)); // push new event onto queue

						}
				}

				break;
			}
			else {
				continue;
			}
		}
		
		if (q.empty()) { // extends values a bit
			for (int i = 0; i < wires.size(); ++i) {
				wires.at(i)->setVal(event.getTime() * 2, "X");
			}

		}
	}

	for (int i = 0; i < wires.size(); ++i) { // printing waveforms
		wires.at(i)->print();
	}
	cout << " 0    5" << endl;
	return 0;
}

//Function to find and set a wire, if the wire is not there (example, wires between gates)
//create that wire and push it into the vector
Wire *findByIdOrCreate(vector <Wire *> &wires, int wireNum) {
    Wire *tempWire = nullptr;
    for(int i = 0; i < wires.size(); i++) {
        tempWire = wires.at(i);
        if (tempWire -> getIndex() == wireNum) {
            return tempWire;
        }
    }
    tempWire = new Wire("", wireNum);
    wires.push_back(tempWire);
    return tempWire;
}
