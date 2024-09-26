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
        cout << "(Name: " << propertyName << ", Color: " << propertyColor << ", Value: " << value << ", Rent: " << rent << ")" << endl;
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
    int size;

public:
    CircularLinkedList() {
        size = 0;
    headNode = nullptr;
    }




// Core Tasks
    void insertAtHead(T value) {

        Node<T> *newNode = new Node<T>(value);
        if(headNode == nullptr) { // if list is empty, set the headNode to be the newNode
            headNode = newNode;
            newNode->nextNode = headNode;
        }else {
            Node<T> *temp = headNode;
            while(temp->nextNode != headNode) {
                temp = temp->nextNode;
            }
            newNode->nextNode = headNode; // set the newNode's next pointer at the current first node of the list
            temp->nextNode = newNode;
            headNode = newNode; // after linking newNode to the list, update headNode to be this newNode
        }

        ++size;
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
            newNode->nextNode = headNode;
        }

        ++size;


    }

    void insertAtPosition(T value, int position) {
        int index = 0; // using index makes sure we stop one node before

        Node<T> *newNode = new Node<T>(value);

        if(position == 0) {
            insertAtHead(value); // save some lines by calling our insert at head
            return;
        }

        if(position > size || position < 0) {
            throw out_of_range("Position out of range");
        }

        if(headNode == nullptr) { // as always, if list is empty, just enter
            headNode = newNode;
            newNode->nextNode = headNode; // point to self for circularity
            ++size;
            return;
        }

        Node<T> *temp = headNode; // using a pointer until we reach position desired

       while(temp->nextNode != headNode && index < position - 1) {
           temp = temp->nextNode;
           index++;
       }

        newNode->nextNode = temp->nextNode; // pointing newnode to next node
        temp->nextNode = newNode; // pointing previous node to new node

        ++size;


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

        --size;


    }


    void deleteAtTail() {

        if(headNode == nullptr) { // all three delete methods will have a check for an empty list
            cout << "List is empty, can't delete" << endl;
            return;
        }

        // deleting at the tail doesn't require a T value input or an if-statement other than if the list is empty: we can set the marker for delete to be the one previous from the tail

        // must iterate to get there first

        Node<T> *temp = headNode;
        while(temp->nextNode != nullptr && temp->nextNode->nextNode != nullptr) { // added check if list hasn't reached end to be safe, could probably remove
            temp = temp->nextNode;
        }

        Node<T> *toDelete = temp->nextNode;
        temp->nextNode = toDelete->nextNode;
        delete toDelete;

        size--;


    }

    void deleteAtPosition(T value, int position) {
        int index = 0;

        if(headNode == nullptr) { // all three methods will have a check for an empty list
            cout << "List is empty, can't delete at position: " << position << endl;
            return;
        }

        if(position == 0) {
            deleteAtHead();
        }else {
            Node<T> *temp = headNode;
            while(temp->nextNode != nullptr && index < position - 1) { // iterate if haven't reached the end and if haven't reached our position
                temp = temp->nextNode;
                ++index;
            }
            if(temp->nextNode == nullptr) { // the end
                cout << "Reached end of list, position entered not possible" << endl;
            } else { // found
                Node<T> *toDelete = temp->nextNode; // mark for deletion
                temp->nextNode = temp->nextNode->nextNode; // connect prev to next
                delete toDelete;
            }
        }
        size--;
    }


    void search(T value) {
        Node<T> *temp = headNode;
        while(temp != nullptr) {
            if(temp->data.isEqual(value)) {
                cout << "Property: " << temp->data << endl;
                cout << "Value: " << temp->data << endl;
            }

        }
    }

    void printList() { // loop the circular list from head to tail, and then loop back to the head
        Node<T> *temp = headNode;

        if(temp == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        do {
            temp->data.print();
            temp = temp->nextNode;

            if(temp != headNode) {
                cout << " -> ";
            }

        } while(temp != headNode);



        cout << "Head" << endl;

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
        // if list is empty
        // temp pointer to traverse
        //do while loop while temp != headNode
        //return count

        if(headNode == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node<T> *temp = headNode;
        int count = 0; // for the head

        do {
            temp = temp->nextNode;
            count++;
        }while(temp != headNode);

        cout << "Total count of nodes is: " << count << endl;

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
    list.insertAtHead(MonopolyBoard("Mediterranean Avenue", "Brown", 60, 2));
    // list.insertAtHead(MonopolyBoard("Test Avenue", "Brown", 60, 2));

    // list.insertAtTail(MonopolyBoard("Park Place", "Dark Blue", 400, 50));

    // list.insertAtPosition(MonopolyBoard("Baltic Avenue", "Brown", 60, 2), 1);
    // list.insertAtPosition(MonopolyBoard("Oriental Avenue", "Light Blue", 100, 6), 2);
    // list.insertAtPosition(MonopolyBoard("Vermont Avenue", "Light Blue", 100, 6), 3);
    // list.insertAtPosition(MonopolyBoard("Connecticut Avenue", "Light Blue", 100, 6), 4);
    // list.insertAtPosition(MonopolyBoard("St. Charles Place", "Pink", 140, 10), 5);
    // list.insertAtPosition(MonopolyBoard("States Avenue", "Pink", 140, 10), 6);
    // list.insertAtPosition(MonopolyBoard("Virginia Avenue", "Pink", 140, 10), 7);
    // list.insertAtPosition(MonopolyBoard("St. James Place", "Orange", 180, 14), 8);
    // list.insertAtPosition(MonopolyBoard("Tennessee Avenue", "Orange", 180, 14), 9);
    // list.insertAtPosition(MonopolyBoard("New York Avenue", "Orange", 180, 14), 10);
    // list.insertAtPosition(MonopolyBoard("Kentucky Avenue", "Red", 220, 18), 11);
    // list.insertAtPosition(MonopolyBoard("Indiana Avenue", "Red", 220, 18), 12);
    // list.insertAtPosition(MonopolyBoard("Illinois Avenue", "Red", 220, 18), 13);
    // list.insertAtPosition(MonopolyBoard("Atlantic Avenue", "Yellow", 260, 22), 14);
    // list.insertAtPosition(MonopolyBoard("Ventnor Avenue", "Yellow", 260, 22), 15);
    // list.insertAtPosition(MonopolyBoard("Marvin Gardens", "Yellow", 260, 22), 16);
    // list.insertAtPosition(MonopolyBoard("Pacific Avenue", "Green", 300, 26), 17);
    // list.insertAtPosition(MonopolyBoard("North Carolina Avenue", "Green", 300, 26), 18);
    // list.insertAtPosition(MonopolyBoard("Pennsylvania Avenue", "Green", 300, 26), 19);
    // list.insertAtPosition(MonopolyBoard("Boardwalk", "Dark Blue", 400, 50), 20);



    //
    //
    //



    // list.deleteAtHead();
    //
    // list.deleteAtTail();

    // list.deleteAtPosition(MonopolyBoard("Mayfair", "Dark Blue", 400, 50), 1);


    //Optional Level 1 Tasks

    // list.reverseCLList();
    // list.sortCLList();
     // list.printHeadNode();
     // list.printLastNode();
    // list.isListEmpty();
     list.countNodes();

    // list.printList();

    // //Optional Level 2 Tasks
    // list.convertCLList();
    // list.updateNodeValue();
    // list.displaySpecificColorNode();
    // list.mergeCLList();

    return 0;
}