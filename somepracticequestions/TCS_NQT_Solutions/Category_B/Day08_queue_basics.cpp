#include <iostream>
using namespace std;

/**
 * Queue Implementation using Array
 */

#define MAX 100
struct Queue {
    int f, r, size;
    int arr[MAX];
    Queue() : f(0), r(-1), size(0) {}
    
    void enqueue(int x) {
        if (size >= MAX) return;
        arr[++r] = x;
        size++;
    }
    
    void dequeue() {
        if (size == 0) return;
        f++;
        size--;
    }
    
    int front() { return arr[f]; }
    bool empty() { return size == 0; }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    return 0;
}
