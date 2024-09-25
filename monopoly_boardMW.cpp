#include <iostream>
#include <string>

using namespace std;

// Data class to store a string and an integer
class MonopolyBoard {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    // REMINDER: copy paste finalized code on replit and make sure it can run

    MonopolyBoard() : propertyName(""), propertyColor(""), value(0), rent(0) {}


    MonopolyBoard(string propertyName,string propertyColor,int value, int rent){
       /*Define overloaded constructor here*/
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;

    }


    bool isEqual(MonopolyBoard other) {
        /*Define is equal here*/
        return (propertyName == other.propertyName && propertyColor == other.propertyColor && value == other.value && rent == other.rent);
    }

    void print() {
        /*Define Print Here*/
        cout << "(" << propertyName << ", " << propertyColor << ", " << value << ", " << rent << ")" << endl;
    }
};

// Template Node class
template <typename T> class Node {
public:
    T data;
    Node* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// Template LinkedList class
template <typename T> class CircularLinkedList {
private:
    Node<T>* headNode;

public:
    CircularLinkedList() {
    headNode = nullptr;
    }

// Core Tasks
    void insertAtHead(T value) {

        Node<T> *newNode = new Node<T>(value);
        if(headNode == nullptr) { // if list is empty, set the headNode to be the newNode
            headNode = newNode;
        }else { // otherwise ...
            newNode->nextNode = headNode; // set the newNode's next pointer at the current first node of the list
            headNode = newNode; // after linking newNode to the list, update headNode to be this newNode
        }

      cout<<"Insert at head unwritten"<<endl;

    }


    void insertAtTail(T value) {

        Node<T> *newNode = new Node<T>(value);
        if(headNode == nullptr) {
            headNode = newNode; // if empty, just enter
        } else {
            Node<T> *temp = headNode; // use a pointer and traverse until next is the end
            while(temp->nextNode != nullptr) {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
        }

        cout<<"Insert at Tail unwritten"<<endl;
    }

    void insertAtPosition(T value, T position) {

        Node<T> *newNode = new Node<T>(value);
        if(headNode == nullptr) { // as always, if list is empty, just enter
            headNode = newNode;
        } else {
            Node<T> *temp = headNode; // using a pointer until we reach position desired
            while(temp->nextNode != position) { // iterate until we reach position wanted
                temp = temp->nextNode;
            }
            // insert newNode with the value at position
            temp->nextNode = newNode;
        }


        cout<<"Insert at Position unwritten"<<endl;
    }


    void deleteAtHead() {

        if(headNode == nullptr) { // all three delete methods will have a check for an empty list
            cout << "List is empty, can't delete" << endl;
            return;
        }

        // deleting at the head doesn't require a T value input or an if-statement other than if the list is empty:

        Node<T> *toDelete = headNode; // mark first node first
        headNode = headNode->nextNode; // moving headNode pointer to next
        delete toDelete;


        cout<<"Delete at head unwritten"<<endl;
    }


    void deleteAtTail() {

        if(headNode == nullptr) { // all three delete methods will have a check for an empty list
            cout << "List is empty, can't delete" << endl;
            return;
        }

        // deleting at the tail doesn't require a T value input or an if-statement other than if the list is empty: we can set the marker for delete to be the one previous from the tail

        // must iterate to get there first

        Node<T> *temp = headNode;
        while(temp->nextNode != nullptr && !temp->nextNode->nextNode == nullptr) { // added check if list hasn't reached end to be safe, could probably remove
            temp = temp->nextNode;
        }

        Node<T> *toDelete = temp->nextNode;
        temp->nextNode = toDelete->nextNode;
        delete toDelete;

        cout<<"Delete at Tail unwritten"<<endl;
    }

    void deleteAtPosition(T value, T position) {

        if(headNode == nullptr) { // all three methods will have a check for an empty list
            cout << "List is empty, can't delete at position: " << position << endl;
            return;
        }

        Node<T> *temp = headNode;
        while(temp->nextNode != nullptr && !temp->nextNode.isEqual(position)) { // iterate if haven't reached the end and if haven't reached our position
            temp = temp->nextNode;
        }

        if(temp->nextNode == nullptr) { // the end
            cout << "Reached end of list, position entered not possible" << endl;
        } else { // found
            Node<T> *toDelete = temp->nextNode; // mark for deletion
            temp->nextNode = temp->nextNode->nextNode; // connect prev to next
            delete toDelete;
        }
        cout<<"Delete at Position unwritten"<<endl;
    }


    void search(T value) {

          cout<<"Search unwritten"<<endl;
    }
    void printList() {
        Node<T> *temp = headNode;
        while(temp != nullptr) {
            temp->data.print();
            cout << " -> ";
            temp = temp->nextNode;
        }
        cout << "END" << endl;
        cout << "Print List unwritten" << endl;
    }

    //Optional Tasks
    //Level 1
    void reverseCLList() {
        cout << "Reverse List unwritten" << endl;
    } void sortCLList() {
        cout << "Sort List unwritten" << endl;
    } void printHeadNode() {
        cout << "Print Head Node unwritten" << endl;
    } void printLastNode() {
        cout << "Print Last Node unwritten" << endl;
    } void isListEmpty() {
        cout << "Is List Empty unwritten" << endl;
    }
    void countNodes() {
        cout << "Count Nodes unwritten" << endl;
    }

    //Optional Tasks
    // Level2
    void convertCLList() {
        cout << "Convert Circular List Unwritten." << endl;
    } void updateNodeValue() {
        cout << "update Node value unwritten" << endl;
    } void displaySpecificColorNode() {
        cout << "Display Specific color Node" << endl;
    } void mergeCLList() {
        cout << "Merge Circular Linked List Unwritten" << endl;
    }

};

// Main function to demonstrate the LinkedList class
int main() {
    // Create a LinkedList of Data objects
    CircularLinkedList<MonopolyBoard> list;

    // Insert elements at the end
    list.insertAtHead(MonopolyBoard("Boardwalk", "Dark Blue", 400, 50));

    list.insertAtTail(MonopolyBoard("Mayfair", "Dark Blue", 400, 50));

    list.deleteAtHead();
    list.deleteAtTail();

    // list.insertAtPosition(MonopolyBoard("Kentucky Avenue", "Red", 220, 18), 5);

    // list.deleteAtHead();
    //
    // list.deleteAtTail();

    // list.deleteAtPosition();

    //Optional Level 1 Tasks

    // list.reverseCLList();
    // list.sortCLList();
     // list.printHeadNode();
     // list.printLastNode();
    // list.isListEmpty();
    // list.countNodes();

    list.printList();

    // //Optional Level 2 Tasks
    // list.convertCLList();
    // list.updateNodeValue();
    // list.displaySpecificColorNode();
    // list.mergeCLList();

    return 0;
}