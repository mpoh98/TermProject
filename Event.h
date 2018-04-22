#include <iostream>
#include <vector>

using namespace std;

class Event {
	public:
		// constructor
		Event(string w, int t, string v, int c);

		// member functions
		//getters
		string getWire() const;
		int getTime() const;
		string getVal() const;
		int getCnt() const;

		//setters
		void setWire(string w);
		void setTime(int t);
		void setVal(int v);
		void setCnt(int v);

		void print();

	private:
		string wire;
		int time;
		string val;
		int cnt;
};
