#include <iostream>
using namespace std;

class Stack {
    private:
        int top;
        int* arr;
        int maxsize;
    public:
        Stack(int n) {
            top = -1;
            arr = new int[n];
            maxsize =n;
            for (int i=0;i<n;i++) {
                arr[i] = 0;
            }
        }
        bool empty() {                  // returns true if the stack is empty
            if (top == -1) return true;
            return false;
        }
        bool ifFull() {                   // returns true if the stack is full
            if (top== maxsize-1) return true;
            return false;
        }
        void push(int x) {                // pushes a element to the stack , if size more , overflows
            if (ifFull()) {
                cout << "Stack Overflow" << "\n";
            }
            else {
                top++;
                arr[top] =x;
            }
        }
        void pop() {                     // pops a element from the stack , if size less , underflows
            if (empty()) {
                cout << "Stack Underflow" << "\n";
            }
            else {
                top--;
            }
        }
        int topele() {
            return arr[top];
        }
        int size() {
            return top+1;
        }
};
int main() {
    int a;
    cout << "Enter the max size of the stack : " << "\n";
    cin >> a;
    Stack st(a);
    st.push(20);
    st.push(30);
    cout << "top element is: " << st.topele() << "\n";
    cout << "size is: " << st.size() << "\n";
    st.pop();
    cout << "size is: " << st.size() << "\n";
    cout << st.empty() << "\n";
    cout << st.ifFull() << "\n";
    st.pop();
    st.pop();
    return 0;
}