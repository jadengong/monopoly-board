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

    // Get the color of a propertyt
    string getColor() {
        return propertyColor;
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

    /** Insert a node somewhere in the CLL
     *
     * @param value Node to insert
     * @param position Index (0-based) to insert the Node
     */
    void insertAtPosition(T value, int position) {
        int index = 0; // Use index to stop one Node before desired

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


    // Deletes a node at the head of a CLL
    void deleteAtHead() {

        if(headNode == nullptr) { // If list is empty, cannot delete at head
            cout << "List is empty, can't delete at head." << endl;
            return;
        }

        // If there is only one node
        if(headNode->nextNode == headNode) {
            delete headNode;
            headNode = nullptr;
        } else { // Otherwise, get last node
            Node<T> *temp = headNode;

            while(temp->nextNode != headNode) {
                temp = temp->nextNode;
            }

            Node<T> *toDelete = headNode; // Mark a pointer to the head we will delete
            headNode = headNode->nextNode; // Move the headNode of the list to the nextNode
            temp->nextNode = headNode; // Link the last node's nextNode to the new headNode

            delete toDelete; // Delete the old head node
        }
        --size;
    }


    // Deletes a node at the tail of a CLL
    void deleteAtTail() {

        if(headNode == nullptr) { // If list is empty, cannot delete at tail
            cout << "List is empty, can't delete at tail." << endl;
            return;
        }

        // If there is only one node
        if(headNode->nextNode == headNode) {
            delete headNode;
            headNode = nullptr;
        } else { // Otherwise, get last node
            Node<T> *temp = headNode;

            while(temp->nextNode->nextNode != headNode) {
                temp = temp->nextNode;
            }

            Node<T> *toDelete = temp->nextNode; // Mark a pointer to the last node for deletion
            temp->nextNode = headNode; // Link the node before the last node's nextNode to the current headNode
            delete toDelete; // Safely delete the old tail node
        }
        size--;
    }


    /**
     * Deletes a node somewhere in the CLL
     *
     *  @param position Index (0-based) to delete the Node
     *  @throws invalid_argument If the input position is less than 0 or greater than the current size of the CLL
     */
    void deleteAtPosition(int position) {
        int index = 0;

        if(headNode == nullptr) { // If the list is empty, cannot delete at the position specified
            cout << "List is empty, can't delete at position: " << position << endl;
            return;
        }

        if(position == 0) { // If the position specified is at the head ...
            deleteAtHead();
        }else if(position == size) { // Or tail
            deleteAtTail();
        }else if(position < 0 || position >= size) { // Throw an invalid argument for non-acceptable positions
            throw invalid_argument("Position out of range! Position must be LESS than the size of the list or GREATER than or EQUAL to zero");
        }
            // Otherwise iterate until we reach the node prior to the one we want to delete
            Node<T> *temp = headNode;
            int posCount = 0; // Initialize a position count to compare with position input

        for(posCount = 0; posCount < position - 1; posCount++) { // Traverse the CLL until we reach the position before the position we want to delete at
            temp = temp->nextNode;
        }

        Node<T> *toDelete = temp->nextNode; // Mark node at position for deletion
        temp->nextNode = temp->nextNode->nextNode; // Link the previous node to the one after the position we want to delete at
        delete toDelete;

        size--;
    }

    /**
     * Searches for a specific Monopoly object/property in a CLL
     *
     * @param value The node/property to search for
     *
     */
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

    // Prints the CLL by looping from head to tail, then back to head
    void printList() {
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

    // Reverses the nodes in a CLL
    void reverseCLList() {
        // Reverse by keeping track of the current and previous node while iterating
        // And setting previous to current, and current to nextNode

        Node<T> *current = headNode;
        Node<T> *previous = nullptr;

        do {
            Node<T> *next = current->nextNode; // Keeps track of the next node
            current->nextNode = previous; // Sets next node to previous, reversing the node position
            previous = current; // Sets the previous node to the current node
            current = next; // Sets the current node to the next node
        }while(current != headNode);

        headNode->nextNode = previous; // Link the head (backwards) to the last node
        headNode = previous; // Update headNode

    }

    // Arranges nodes based on property names in lexicographical order
    void sortCLList() {





    }

    // Print the first node's information
    void printHeadNode() {
        if(isListEmpty()) {
            cout << "List is empty. Cannot print head node." << endl;
            return;
        }
        cout << headNode->data << endl; // Print headNode information
    }

    // Print the last node's information
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
        int count = 0; // Initialize a counter to be printed

        do {
            temp = temp->nextNode;
            count++;
        }while(temp != headNode);

        cout << "Total count of nodes is: " << count << endl;
    }

    //Optional Tasks
    // Level2

    // De-circularize a CLL
    void convertCLList() {
        if(isListEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        Node<T> *temp = headNode; // Get last node
        while(temp->nextNode != headNode) {
            temp = temp->nextNode;
        }

        temp->nextNode = nullptr; // Set the last node to null, effectively de-circularizing the CLL
    }


    /**
     * Updates the data of a specified node in a CLL
     *
     * @param value Node of which data is to be updated
     * @param newValue Node with updated data
     */
    void updateNodeValue(T value, T newValue) {
        if(isListEmpty()) {
            cout << "List is empty. Cannot update node value." << endl;
        }

        // Iterate list for the node
        Node<T> *search = search(value);
        if(search == nullptr) {
            cout << "Property is not on the list. Cannot update." << endl;
            return;
        }

        search->data = newValue;
    }

    /**
     * Displays the properties of all nodes with a specified color
     *
     * @param color Specified color of property to display information
     */
    void displaySpecificColorNode(string color) {
        if(isListEmpty()) {
            cout << "List is empty. Cannot display nodes with the color: " << color << endl;
            return;
        }

        bool found = false; // Flag to check if properties are found with the specified color
        Node<T> *temp = headNode;

        do {

            if(temp->data.getColor() == color) { // Check if node has the specified color
                cout << temp->data << endl; // Print headNode data
                found = true;
            }
            temp = temp->nextNode;

        }while(temp != headNode);

        // If no nodes match the specified color
        if(!found) cout << "There are no properties on the list with this color." << endl;
    }

    // Merges two CLL
    void mergeCLList(CircularLinkedList<T> &secondList) {
        // If the second list is empty
        if(secondList.headNode == nullptr) {
            cout << "Second list is empty. There is nothing to merge." << endl;
            return;
        }

        // If the original list is empty, merge
        if(isListEmpty()) {
            headNode = secondList.headNode; // Link head to secondList head
            return;
        }

        // Get the tail of both lists and link them to the respective heads
        Node<T> *temp = headNode;

        while(temp->nextNode != headNode) {
            temp = temp->nextNode;
        }

        Node<T> *tail1 = temp; // Tail for list 1

        Node<T> *temp2 = secondList.headNode;

        while(temp2->nextNode != secondList.headNode) {
            temp2 = temp2->nextNode;
        }

        Node<T> *tail2 = temp2; // Tail for list 2

        tail1->nextNode = secondList.headNode; // Link the original list's tail to head of second list
        tail2->nextNode = headNode; // Link the tail of second list back to head of original list
    }
};

// Main function for test cases
int main() {

    // Create a new circular linked list object
    CircularLinkedList<MonopolyBoard> list;

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
    // list.deleteAtPosition(2);

    list.search(MonopolyBoard("Boardwalk", "Dark Blue", 400, 50));



    //Optional Level 1 Tasks

    // list.reverseCLList();
    // list.sortCLList();
     // list.printHeadNode();
     // list.printLastNode();
    // list.isListEmpty();
    list.countNodes();

    list.printList();



    //Optional Level 2 Tasks

    // list.convertCLList();
    // list.updateNodeValue();
    //list.displaySpecificColorNode("Green");

    // Create a new circular linked list object to merge
    CircularLinkedList<MonopolyBoard> list2;
    list2.insertAtHead(MonopolyBoard("Campanile Drive", "Red", 220, 18)); // SDSU
    list2.insertAtTail(MonopolyBoard("Camino Del Sur", "Black", 220, 18)); // WVHS

    // Merging the two circular linked lists
    list.mergeCLList(list2);
    cout << "The list after merge is: " << endl;
    list.printList();
    cout << endl;

    return 0;
}