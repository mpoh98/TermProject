#include <iostream>
#include <vector>

using namespace std;


class Gate;

class Wire {
	public:
		// constructor
		Wire(int v, vector<Gate *> d/*change to vector?*/, string n, string h, int i);
		Wire(string n, int i);

		// member functions
		//getters
		string getVal() const;
		vector<Gate *> getDrives() const;
		string getName() const;
		string getHistory() const;
		int getIndex() const;
		
		//setters
		void setVal(string v);
		void setDrives(Gate *d);
		void setName(string n);
		void setHistory(string h);
		void setIndex(int i);

	private:
		string val;
		vector<Gate *> drives;
		string name;
		string history;
		int index;
};
