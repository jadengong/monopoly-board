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

    // Constructor with default values
    MonopolyBoard() : propertyName(""), propertyColor(""), value(0), rent(0) {}


    // Constructor with given parameter values
    MonopolyBoard(string propertyName,string propertyColor,int value, int rent){
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;

    }


    // Determining if two objects are equal
    bool isEqual(const MonopolyBoard& other) const {
        return (propertyName == other.propertyName && propertyColor == other.propertyColor && value == other.value && rent == other.rent);
    }

    // Compact Node Information
    void print() const {
        cout << "(Name: " << propertyName << ", Color: " << propertyColor << ", Value: " << value << ", Rent: " << rent << ")" << endl;
    }
};


    // Operator overload for print
    std::ostream& operator<<(std::ostream& os, const MonopolyBoard& obj) {

        cout << "Property found! Details below: " << endl;
        cout << "Property Name: " << obj.propertyName << endl;
        cout << "Property Color: " << obj.propertyColor << endl;
        cout << "Value: $" << obj.value << endl;
        cout << "Rent: $" << obj.rent << endl;
        return os;
}



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

    /**
    * Insert a node at head of a CLL
    *
    * @param value Node to insert
    */
    void insertAtHead(T value) {
        Node<T> *newNode = new Node<T>(value); // Allocating memory for a new node to be inserted

        if(headNode == nullptr) {
            headNode = newNode; // Update headNode
            newNode->nextNode = headNode; // Link lastNode to the headNode
        }else {
            Node<T> *temp = headNode;
            while(temp->nextNode != headNode) { // Get tailNode
                temp = temp->nextNode;
            }
            newNode->nextNode = headNode; // Set newNode's next pointer to be the current Head
            temp->nextNode = newNode; // Link lastNode to headNode
            headNode = newNode; // update headNode
        }
        ++size;
    }


    /**
     * Insert a node at tail of CLL
     *
     *  @param value Node to insert
     */
    void insertAtTail(T value) {
        Node<T> *newNode = new Node<T>(value); // Allocate memory for a new node to be inserted

        if(headNode == nullptr) {
            headNode = newNode; // Update headNode
            newNode->nextNode = headNode; // Link back to itself
        } else {
            Node<T> *temp = headNode;
            while(temp->nextNode != headNode) { // Get tailNode
                temp = temp->nextNode;
            }
            temp->nextNode = newNode; // Set previous tailNode's next pointer to the new tailNode

            newNode->nextNode = headNode; // Circularize
        }
        ++size;
    }

    /** Insert a node between the head and tail of a CLL
     *
     * @param value Node to insert
     * @param position Index (0-based) to insert the Node
     */
    void insertAtPosition(T value, int position) {
        int index = 0; // Use index to stop one Node before desired

        Node<T> *newNode = new Node<T>(value);

        if(position == 0) {
            insertAtHead(value);
            return;
        }

        if(position == size) {
            insertAtTail(value);
            return;
        }

        if(position > size || position < 0) {
            throw invalid_argument("Position out of range!");
        }



        

        Node<T> *newNode = new Node<T>(value); // Allocate memory for a new node to be inserted


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

        // if one node
        if(headNode->nextNode == headNode) {
            delete headNode;
            headNode = nullptr;
        } else { // must traverse to last node (pointing to the head)
            Node<T> *temp = headNode;

            while(temp->nextNode != headNode) {
                temp = temp->nextNode;
            }

            Node<T> *toDelete = headNode;
            headNode = headNode->nextNode;
            temp->nextNode = headNode; // last's nextnode to be the new headnode

            delete toDelete;

        }
        --size;
    }


    void deleteAtTail() {

        if(headNode == nullptr) { // all three delete methods will have a check for an empty list
            cout << "List is empty, can't delete" << endl;
            return;
        }

        // if one node
        if(headNode->nextNode == headNode) {
            delete headNode;
            headNode = nullptr;
        } else {
            Node<T> *temp = headNode;

            while(temp->nextNode->nextNode != headNode) {
                temp = temp->nextNode;
            }

            Node<T> *toDelete = temp->nextNode; // mark tail for deletion
            temp->nextNode = headNode; // last's next node to point to head (circularize)
            delete toDelete;

        }
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
            while(temp->nextNode != headNode && index < position - 1) { // iterate if haven't reached the end and if haven't reached our position
                temp = temp->nextNode;
                ++index;
            }
            if(index != position - 1|| temp->nextNode == headNode) { // the end
                cout << "Position is not valid" << endl;
                

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
        bool found = false;
        do {
            if (temp->data.isEqual(value)) {
                cout << temp->data << std::endl;
                found = true;
            }
            temp = temp->nextNode;
        } while (temp != headNode);

        if(found == false) {
            cout << "Property not on the list." << endl;
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





    }

    //Optional Tasks
    //Level 1
    void reverseCLList() {
        cout << "Reverse List unwritten" << endl;
    } void sortCLList() {
        cout << "Sort List unwritten" << endl;
    }


    void printHeadNode() {
        if(isListEmpty()) {
            cout << "List is empty. Cannot print head node." << endl;
            return;
        }
        cout << headNode->data << endl; // Print headNode information

    }

    void printLastNode() {
        if(isListEmpty()) {
            cout << "List is empty. Cannot print last node." << endl;
            return;
        }

        Node<T> *temp = headNode;

        while(temp->nextNode != headNode) {
            temp = temp->nextNode;
        }

        cout << temp->data << endl; // Print tailNode information
    }

    /**
     * Determines if the list is empty.
     *
     * @return "true" if empty, "false" if not empty
     */
    bool isListEmpty() {
        return headNode == nullptr;
    }


    /**
     * Counts the number of nodes in the list.
     */
    void countNodes() {
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


    // Insert elements
    list.insertAtHead(MonopolyBoard("Mediterranean Avenue", "Brown", 60, 2));

    list.insertAtTail(MonopolyBoard("Park Place", "Dark Blue", 400, 50));

    list.insertAtPosition(MonopolyBoard("Baltic Avenue", "Brown", 60, 2), 1);
    list.insertAtPosition(MonopolyBoard("Oriental Avenue", "Light Blue", 100, 6), 2);
    list.insertAtPosition(MonopolyBoard("Vermont Avenue", "Light Blue", 100, 6), 3);
    list.insertAtPosition(MonopolyBoard("Connecticut Avenue", "Light Blue", 100, 6), 4);
    list.insertAtPosition(MonopolyBoard("St. Charles Place", "Pink", 140, 10), 5);
    list.insertAtPosition(MonopolyBoard("States Avenue", "Pink", 140, 10), 6);
    list.insertAtPosition(MonopolyBoard("Virginia Avenue", "Pink", 140, 10), 7);
    list.insertAtPosition(MonopolyBoard("St. James Place", "Orange", 180, 14), 8);
    list.insertAtPosition(MonopolyBoard("Tennessee Avenue", "Orange", 180, 14), 9);
    list.insertAtPosition(MonopolyBoard("New York Avenue", "Orange", 180, 14), 10);
    list.insertAtPosition(MonopolyBoard("Kentucky Avenue", "Red", 220, 18), 11);
    list.insertAtPosition(MonopolyBoard("Indiana Avenue", "Red", 220, 18), 12);
    list.insertAtPosition(MonopolyBoard("Illinois Avenue", "Red", 220, 18), 13);
    list.insertAtPosition(MonopolyBoard("Atlantic Avenue", "Yellow", 260, 22), 14);
    list.insertAtPosition(MonopolyBoard("Ventnor Avenue", "Yellow", 260, 22), 15);
    list.insertAtPosition(MonopolyBoard("Marvin Gardens", "Yellow", 260, 22), 16);
    list.insertAtPosition(MonopolyBoard("Pacific Avenue", "Green", 300, 26), 17);
    list.insertAtPosition(MonopolyBoard("North Carolina Avenue", "Green", 300, 26), 18);
    list.insertAtPosition(MonopolyBoard("Pennsylvania Avenue", "Green", 300, 26), 19);
    list.insertAtPosition(MonopolyBoard("Boardwalk", "Dark Blue", 400, 50), 20);




    // list.deleteAtHead();
    // list.deleteAtTail();

    list.search(MonopolyBoard("Boardwalk", "Dark Blue", 400, 50));



    //Optional Level 1 Tasks

    // list.reverseCLList();
    // list.sortCLList();
     // list.printHeadNode();
     // list.printLastNode();
    // list.isListEmpty();
    list.countNodes();

    //list.printList();

    // //Optional Level 2 Tasks
    // list.convertCLList();
    // list.updateNodeValue();
    // list.displaySpecificColorNode();
    // list.mergeCLList();

    return 0;
}