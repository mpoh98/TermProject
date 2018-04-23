#include "Queue.h"
#include "Event.h"
#include <queue>

Queue::Queue(Event *e) {
    q.push(e);
}

Event *Queue::pop() {
    Event *e = q.top();
    q.pop();
    return e;
}

void Queue::push(Event *e) {
    q.push(e);
}

bool operator<(const Event &e1, const Event &e2) {
    if (e1.getTime() > e2.getTime()) {
        return false;
    }
    else if (e1.getTime() < e2.getTime()) {
        return true;
    }
    else if (e1.getTime() == e2.getTime()) {
        if (e1.getCnt() > e2.getCnt()) {
            return false;
        }
        else if (e1.getCnt() < e2.getCnt()) {
            return true;
        }
    }
}