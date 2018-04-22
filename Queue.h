#include <iostream>
#include <queue>

using namespace std;

class Event;

class Queue {
	public:
		// constructor
		Queue(Event e);

		//member functions
		//getters
		Event pop() const;

		//setters
		void push(Event e);

		//operators
		friend bool operator<(const Event &e1, const Event &e2);

	private:
		priority_queue<Event> q;
};
