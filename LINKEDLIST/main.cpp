//Linked list

//1.Traversing a linked list
//2.Append a new node
//3.Prepend a new node
//4.Insert a new node at random location
//5.Deleting a node from the list
//6.Updating a node from the list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        data = 0;
        next = NULL;
    }
    Node(int d) {
        data = d;
    }
};
class LinkedList {
public:
    Node *head;
    LinkedList(Node *hd) {
        head = hd;
    }
    void view() {                      // view the whole linked list
        Node *temp = head;
        cout << "The linked list is :" << "\n";
        while (temp != NULL) {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }
    void append(int d) {               // add a node at the ending of the linkedlist
        Node *n = new Node(d);
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
    void preprend(int d) {              // add a node at the starting of the linkedlist
        Node *n = new Node(d);
        n->next = head;
        head = n;
    }
    void insert(int d , int pos) {       // inserts a node at random location , assuming pos as 0-indexed
        int i =0;
        Node *n = new Node(d);
        if (pos==0) {
            n->next = head;
            head = n;
            return;
        }
        Node *temp = head;
        while (i+1 < pos) {
            temp = temp->next;
            i++;
        }
        n->next = temp->next;
        temp->next = n;
    }
    void del(int pos){                  // deletes the node at a specific location
        if (pos==0) {
            head = head->next;
            return;
        }
        Node *temp =head;
        int i=0;
        while (i+1<pos) {
            temp = temp-> next;
            i++;
        }
        temp->next = temp->next->next;
    }
    void update(int d , int pos) {       //  updates the data of the node at specific location
        int i =0;
        Node *temp = head;
        while (i<pos) {
            temp = temp->next;
            i++;
        }
        temp->data = d;
    }
};

int main() {
    int d = 0;
    cout << "Enter data for the head node" << "\n";
    cin >> d;
    Node *n = new Node(d);
    LinkedList l(n);
    l.view();
    l.append(50);
    l.preprend(40);
    l.insert(20,0);
    l.view();
    l.update(0,0);
    l.del(0);
    l.view();
}