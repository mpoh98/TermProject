#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <queue>

using namespace std;

class Event;

class Queue {
	public:
		// constructor
		Queue(Event e);

		//pop the top event off the queue
		Event pop();

		//push an event onto the queue
		void push(Event e);

		bool empty();

		//operators
		friend bool operator<(const Event &e1, const Event &e2);

	private:
		priority_queue<Event> q;
};

#endif