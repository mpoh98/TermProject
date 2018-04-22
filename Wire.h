#include <iostream>
#include <vector>

using namespace std;


class Gate;

class Wire {
	public:
		// constructor
		Wire(int v, vector<Gate *> d, string n, vector<string> h, int i);
		Wire(string n, int i);

		// member functions
		//getters
		string getVal() const;
		vector<Gate *> getDrives() const;
		string getName() const;
		vector<string> getHistory() const;
		int getIndex() const;
		
		//setters
		void setVal(string v);
		void setDrives(Gate *d);
		void setName(string n);
		void setHistory(string h);
		void setIndex(int i);

		void print();

	private:
		string val;
		vector<Gate *> drives;
		string name;
		vector<string> history;
		int index;
};
