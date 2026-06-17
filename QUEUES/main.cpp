//Queue  (This is not a Circular queue) ..

//1.Checking whether queue is empty or not
//2.Checking whether queue is full or not
//3.Adding elements to the queue
//4.Removing elements from the que
//5.Return size of the queue
//6.Return the front element of the queue
//7.Return the back element of the queue


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
            return -1;
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
    int n = 0;
    cout << "Enter the size of the queue: " << "\n";
    cin >> n;
    Queue *q = new Queue(n);
    while (true) {
        int ch = 0;
        cout << "Queue Data Structure" << "\n";
        cout << "0.empty" << "\n";
        cout << "1.Push" << "\n";
        cout << "2.Pop" << "\n";
        cout << "3.Size" << "\n";
        cout << "4.Front" << "\n";
        cout << "5.Back" << "\n";
        cout << "6.Exit" << "\n";
        cout << "Enter your choice: " << "\n";
        cin >> ch;
        switch (ch) {
            case 0:
                if (q->empty()) {
                    cout << "queue is empty" << "\n";
                }
                else {
                    cout << "queue is not empty" << "\n";
                }
                break;
            case 1:
                cout << "Enter the data to be pushed: " << "\n";
                int data;
                cin >> data;
                q->push(data);
                break;
            case 2:
                q->pop();
                break;
            case 3:
                cout << "Size of the queue: " << q->size() << "\n";
                break;
            case 4:
                cout << "Front element: " << q->frontele() << "\n";
                break;
            case 5:
                cout << "Back element: " << q->backele() << "\n";
                break;
            case 6:
                cout << "Thank you for using Queue Data Structure" << "\n";
                exit(0);
            default:
                cout << "You have entered an invalid choice" << "\n";
                break;
        }
    }
}