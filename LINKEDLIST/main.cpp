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
        next = NULL;
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
    LinkedList *l = new LinkedList(new Node(20));  //Default linked list intialised with val of 20 as startind node
    cout << "Welcome to the linked list" << "\n";
    while (true) {                      //Adding choices to the linked list for user defined interface
        int ch = 0;
        cout << "1.View the linked list" << "\n";
        cout << "2.Append a new node" << "\n";
        cout << "3.Prepend a new node" << "\n";
        cout << "4.Insert a new node at random location" << "\n";
        cout << "5.Delete a node from the list" << "\n";
        cout << "6.Update a node from the list" << "\n";
        cout << "7.Exit" << "\n";
        cout << "Enter your choice" << "\n";
        cin >> ch;
        int d;
        int pos;
        switch (ch) {
            case 1:
                l->view();
                break;
            case 2:
                cout << "Enter the data to be appended" << "\n";
                cin >> d;
                l->append(d);
                break;
            case 3:
                cout << "Enter the data to be prepended" << "\n";
                cin >> d;
                l->preprend(d);
                break;
            case 4:
                cout << "Enter the data to be inserted" << "\n";
                cin >> d;
                cout << "Enter the position to be inserted" << "\n";
                cin >> pos;
                l->insert(d,pos);
                break;
            case 5:
                cout << "Enter the position to be deleted" << "\n";
                cin >> pos;
                l->del(pos);
                break;
            case 6:
                cout << "Enter the data to be updated" << "\n";
                cin >> d;
                cout << "Enter the position to be updated" << "\n";
                cin >> pos;
                l->update(d,pos);
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice" << "\n";
                break;
        }
    }
    cout << "Thank you for using this data structure" << "\n";
    return 0;
}