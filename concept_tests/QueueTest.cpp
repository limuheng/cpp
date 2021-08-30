#include <iostream>
#include <queue>
#include "QueueTest.h"

using namespace std;

static void queueTest() {
    queue<int> q;

    cout << "[START] Size of q: " << q.size() << endl;

    // enqueue
    q.push(5);
    q.push(2);
    q.push(7);
    q.push(9);
    q.push(6);

    cout << "[BEFORE POP] Size of q: " << q.size() << endl;
    // dequeue
    int count = 0;
    while (!q.empty()) {
        int i = q.front(); // Get the next element in queue (Not Removed)
        cout << "The " << ++count << "th element: " << i << endl;
        q.pop(); // Remove the next element in queue
    }

    cout << "[END] Size of q: " << q.size() << endl;
}

void QueueTest::start() {
    cout << ">>> QueueTest" << endl;
    queueTest();
}

void QueueTest::stop() {
    cout << "<<< QueueTest" << endl;
}