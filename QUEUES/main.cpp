#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int maxsize;           // max capacity a queue can hold
    int front;
    int rear;
public:
    Queue(int size) {      // constructor
        maxsize = size;
        arr = new int[size];
        front = -1;        //when no element present , front and rear are -1
        rear = -1;
        for (int i=0;i<size;i++) {
            arr[i] = 0;
        }
    }
    bool empty() {          // returns true if queue is empty
        if (front == -1 && rear == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    bool full() {           // returns true if queue is full
        if (rear == maxsize-1) {
            return true;
        }
        return false;
    }
    void push(int data) {   //add the data to the end of the queue
        if (full()) {
            cout << "Queue is full" << "\n";
        }
        else if (empty()) {
            front  = rear = 0;
            arr[rear] = data;
        }
        else {
            arr[++rear] = data;
        }
    }
    void pop() {             // remvoes the front element from the queue
        if (empty()) {
            cout << "Queue is empty" << "\n";
        }
        else if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
    }
    int size() {              // returns the current size of the queue
        if (empty()) {
            return 0;
        }
        return rear - front +1;
    }
    int frontele() {          // returns the front element in the queue (earlier added element)
        if (empty()) {
            cout << "Queue is empty" << "\n";
        }
        else {
            return arr[front];
        }
    }
    int backele() {            // returns the back element in the queue (latest added element)
        if (empty()) {
            cout << "Queue is empty" << "\n";
        }
        else {
            return arr[rear];
        }
    }
};
int main() {
    int a = 0;
    cout << "Enter the size of the queue:";
    cin >> a;
    Queue q(a);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    cout << q.frontele() << "\n";
    cout << q.backele() << "\n";
    cout << q.size() << "\n";
    cout <<q.full() << "\n";
    q.pop();
    q.pop();
    q.pop();
    cout << q.size() << "\n";
}