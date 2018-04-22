#include "Gate.h"
#include "Wire.h"
#include "Event.h"
#include "Queue.h"
#include <iostream>
#include <string>
#include <fstream>

int main() {
    // test change
    string filename;
    string vectorFileName;
    ifstream inFS;
    string circName;

    vector <Gate *> gates;
    vector <Wire *> wires;

    cout << "Please enter the full name of the circuit file. (ex: 'circuit0.txt')" << endl;
    cin >> filename;

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
        inFS >> delay >> dummy >> input1;
        if (type.compare("NOT") != 0) {
            inFS >> input2;
        }
        inFS >> output;
        gates.push_back(new Gate(gateType, delay, input1, input2, output));     
    }


    //NOTE: Create a helper function that searches through the vector of Gates to find it by its ID number
    //NOTE: remember your using pointers, so use the ->
    //Use that function to take the index you got from the file to grab the corresponding wire that was created
    //NOTE: If you search for an index but didn't get a wire (for the wires between gates)
    //create a wire and insert it into the wire vector, continue to use that wire and connect it up like normal
    
    inFS.close();

    cout << "Please enter the full name of the vector circuit file. (ex: 'circuit0_v.txt')" << endl;
    cin >> vectorFileName;

    inFS.open(filename);
        if (!inFS.is_open()) {
            cout << "Could not open the file  " << filename << "." << endl;
            return 1;
        }

    //t = 
    int t, v;
    string k, n;

    inFS >> k >> n >> t >> v;

    inFS.close();

	return 0;
}

