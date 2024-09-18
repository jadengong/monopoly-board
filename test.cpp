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

    bool isEqual(Student other) { // called in search function
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

    // Delete a node with a specific value -----------------
    void deleteSpecificNode(T value) {
        if (headNode == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return; // EMPTY RETURN is more graceful than a break; preserves call stack
        }

        // if first node is the value to be deleted. Mark head for deletion
        if (headNode->data.isEqual(value)) {
            Node<T>* toDelete = headNode; // mark headNode (first node) before deleting it!
            headNode = headNode->nextNode; // move the headNode pointer to the next one
            delete toDelete; // delete the mark (pointer)
            return;
        }


        // search the list till the end
        Node<T>* temp = headNode;
        while (temp->nextNode != nullptr && !temp->nextNode->data.isEqual(value)) { // iterating until we either hit the end or fall one before the one we want to delete
            temp = temp->nextNode;
        }

        if (temp->nextNode == nullptr) { // reached the end
            cout << "Value not found in the list." << endl;
        } else { // use the pointer to mark the node to delete, reconnect the pointer link and then delete
            Node<T>* toDelete = temp->nextNode;
            temp->nextNode = temp->nextNode->nextNode;
            delete toDelete;
        }
    }

    // Search for a node with a specific value -----------------
    bool search(T value) { // can also be a void search(T value)
        Node<T>* temp = headNode;
        while (temp != nullptr) {
            if (temp->data.isEqual(value)) {
                return true; // cout << "Element found."
            }
            temp = temp->nextNode;
        }
        return false; // cout << "Element not found."
    }

    // Insert at the head of the list -----------------
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

    // reverse the list --------------
    void reverseList() {
        Node<T>* prev;
        Node<T>* curr;
        Node<T>* next;
        prev = nullptr;
        curr = headNode;

        while(curr != nullptr) {
            next = curr->nextNode;
            curr->nextNode = prev;
            prev = curr;
            curr = next;
        }

        headNode = prev;

    }


    // Print the linked list -----------------
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
    list.insertAtHead(Student("L", 78));
    list.insertAtHead(Student("M", 512));



    list.insertAtTail(Student("L", 111));
    list.insertAtTail(Student("M", 51));
    list.insertAtTail(Student("N", 78));
    list.insertAtTail(Student("O", 155));
    list.insertAtTail(Student("P", 212));


    cout << "Linked List after insertions:" << endl;
    list.printList();


    Student deleteElement("A", 25);
    list.deleteSpecificNode(deleteElement);
    cout << "Linked List after deletion of A:" << endl;
    list.printList();

    list.reverseList();
    cout << "Linked list after reversal:" << endl;
    list.printList();


    return 0;
}