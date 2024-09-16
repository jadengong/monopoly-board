#include <iostream>
#include <string>

using namespace std;

// Data class to store a string and an integer
class Student {
public:
    string name;
    int num;

    Student() {
        name = "";
        num = 0;
    }
    Student(string s, int n) {
        name = s;
        num = n;
    }

    bool isEqual(Student other) {
        return (name == other.name && num == other.num);
    }

    void print() { cout << "(" << name << ", " << num << ")"; }
};

// Template Node class
template <typename T> class Node {
public:
    T data;
    Node *nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// Template LinkedList class
template <typename T> class LinkedList {
private:
    Node<T> *headNode;

public:
    LinkedList() { headNode = nullptr; }

    // Insert at the head of the list
    void insertAtHead(T value) {
        Node<T> *newNode = new Node<T>(value);
        if (headNode == nullptr) {
            headNode = newNode;
        } else {
            newNode->nextNode = headNode;
            headNode = newNode;
        }
    }

    void insertAtTail(T value) {
        Node<T> *newNode = new Node<T>(value);
        if (headNode == nullptr) {
            headNode = newNode;
        } else {
            Node<T> *temp = headNode;
            while (temp->nextNode != nullptr) {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
        }
    }

    // Delete a node with a specific value

    // Print the linked list
    void printList() {
        Node<T> *temp = headNode;
        while (temp != nullptr) {
            temp->data.print();
            cout << " -> ";
            temp = temp->nextNode;
        }
        cout << "NULL" << endl;
    }
};

// Main function to demonstrate the LinkedList class
int main() {
    // Create a LinkedList of Data objects
    LinkedList<Student> list;

    // Insert elements at the end
    list.insertAtHead(Student("A", 25));
    list.insertAtHead(Student("B", 27));
    list.insertAtHead(Student("C", 12));
    list.insertAtHead(Student("D", 48));
    list.insertAtHead(Student("E", 28));
    list.insertAtHead(Student("F", 9));
    list.insertAtHead(Student("G", 11));
    list.insertAtHead(Student("H", 13));
    list.insertAtHead(Student("I", 99));
    list.insertAtHead(Student("J", 2));
    list.insertAtHead(Student("K", 1));



    list.insertAtTail(Student("L", 111));
    list.insertAtTail(Student("M", 51));
    list.insertAtTail(Student("N", 78));
    list.insertAtTail(Student("O", 155));
    list.insertAtTail(Student("P", 212));


    cout << "Linked List after insertions:" << endl;
    list.printList();

    return 0;
}