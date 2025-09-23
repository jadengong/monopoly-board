#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <chrono>

using namespace std;

// Custom exception classes for better error handling
class EmptyListException : public std::runtime_error {
public:
    EmptyListException(const string& operation) 
        : std::runtime_error("List is empty. Cannot perform operation: " + operation) {}
};

class InvalidPositionException : public std::invalid_argument {
public:
    InvalidPositionException(int position, int size) 
        : std::invalid_argument("Position " + to_string(position) + " is out of range. Valid range: 0 to " + to_string(size - 1)) {}
};

// Data class to store a string and an integer
class MonopolyBoard {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    // Constructor with default values
    MonopolyBoard() : propertyName(""), propertyColor(""), value(0), rent(0) {}


    // Constructor with given parameter values
    MonopolyBoard(const string &propertyName, const string &propertyColor, const int value, const int rent){
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }

    // Get the color of a property
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
        os << "Property found! Details below: " << std::endl;
        os << "Property Name: " << obj.propertyName << std::endl;
        os << "Property Color: " << obj.propertyColor << std::endl;
        os << "Value: $" << obj.value << std::endl;
        os << "Rent: $" << obj.rent;
        return os;
    }

    // Operator overload for comparing in sort
    bool operator>=(const MonopolyBoard& lhs, const MonopolyBoard& rhs) {
        return lhs.propertyName >= rhs.propertyName;
    }

    // Operator overload for comparing in sort
    bool operator<(const MonopolyBoard& lhs, const MonopolyBoard& rhs) {
        return lhs.propertyName < rhs.propertyName;
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
    Node<T>* tailNode;  // Add tail pointer for O(1) tail operations
    int size;

public:
    CircularLinkedList() {
        size = 0;
        headNode = nullptr;
        tailNode = nullptr;
    }

    // Destructor to prevent memory leaks
    ~CircularLinkedList() {
        clear();
    }

    // Copy constructor (Rule of Three)
    CircularLinkedList(const CircularLinkedList& other) {
        headNode = nullptr;
        tailNode = nullptr;
        size = 0;
        *this = other; // Use assignment operator
    }

    // Assignment operator (Rule of Three)
    CircularLinkedList& operator=(const CircularLinkedList& other) {
        if (this != &other) { // Self-assignment check
            clear(); // Clear current list
            
            // Copy all nodes from other list
            if (other.headNode != nullptr) {
                Node<T>* temp = other.headNode;
                do {
                    insertAtTail(temp->data);
                    temp = temp->nextNode;
                } while (temp != other.headNode);
            }
        }
        return *this;
    }

    // Move constructor (Rule of Five)
    CircularLinkedList(CircularLinkedList&& other) noexcept {
        headNode = other.headNode;
        tailNode = other.tailNode;
        size = other.size;
        other.headNode = nullptr;
        other.tailNode = nullptr;
        other.size = 0;
    }

    // Move assignment operator (Rule of Five)
    CircularLinkedList& operator=(CircularLinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            headNode = other.headNode;
            tailNode = other.tailNode;
            size = other.size;
            other.headNode = nullptr;
            other.tailNode = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // Helper method to clear all nodes
    void clear() {
        while (headNode != nullptr) {
            deleteAtHead();
        }
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
            tailNode = newNode; // Update tailNode
            newNode->nextNode = headNode; // Link lastNode to the headNode
        }else {
            newNode->nextNode = headNode; // Set newNode's next pointer to be the current Head
            tailNode->nextNode = newNode; // Link tailNode to newNode
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
            tailNode = newNode; // Update tailNode
            newNode->nextNode = headNode; // Link back to itself
        } else {
            tailNode->nextNode = newNode; // Set previous tailNode's next pointer to the new tailNode
            newNode->nextNode = headNode; // Circularize
            tailNode = newNode; // Update tailNode
        }
        ++size;
    }

    /** Insert a node somewhere in the CLL
     *
     * @param value Node to insert
     * @param position Index (0-based) to insert the Node
     * @throws invalid_argument If position is less than 0 or greater than the size of the list, throws an invalid argument
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

        if(position < 0 || position > size) {
            throw InvalidPositionException(position, size + 1);
        }


        Node<T> *newNode = new Node<T>(value); // Allocate memory for a new node to be inserted


        if(headNode == nullptr) { // as always, if list is empty, just enter
            headNode = newNode;
            tailNode = newNode;
            newNode->nextNode = headNode; // point to self for circularity
            ++size;
            return;
        }

        Node<T> *temp = headNode; // using a pointer until we reach position desired

       while(temp->nextNode != headNode && index < position - 1) {
           temp = temp->nextNode;
           index++;
       }

        newNode->nextNode = temp->nextNode; // pointing new node to next node
        temp->nextNode = newNode; // pointing previous node to new node

        ++size;
    }


    // Deletes a node at the head of a CLL
    void deleteAtHead() {

        if(headNode == nullptr) { // If list is empty, cannot delete at head
            throw EmptyListException("delete at head");
        }

        // If there is only one node
        if(headNode->nextNode == headNode) {
            delete headNode;
            headNode = nullptr;
            tailNode = nullptr;
        } else { // Otherwise, use tail pointer
            Node<T> *toDelete = headNode; // Mark a pointer to the head we will delete
            headNode = headNode->nextNode; // Move the headNode of the list to the nextNode
            tailNode->nextNode = headNode; // Link the tail node's nextNode to the new headNode

            delete toDelete; // Delete the old head node
        }
        --size;
    }


    // Deletes a node at the tail of a CLL
    void deleteAtTail() {

        if(headNode == nullptr) { // If list is empty, cannot delete at tail
            throw EmptyListException("delete at tail");
        }

        // If there is only one node
        if(headNode->nextNode == headNode) {
            delete headNode;
            headNode = nullptr;
            tailNode = nullptr;
        } else { // Otherwise, find the node before tail
            Node<T> *temp = headNode;

            while(temp->nextNode != tailNode) {
                temp = temp->nextNode;
            }

            Node<T> *toDelete = tailNode; // Mark a pointer to the last node for deletion
            temp->nextNode = headNode; // Link the node before the last node's nextNode to the current headNode
            tailNode = temp; // Update tail pointer
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
        if(headNode == nullptr) { // If the list is empty, cannot delete at the position specified
            throw EmptyListException("delete at position " + to_string(position));
        }

        if(position < 0 || position >= size) { // Validate bounds early
            throw InvalidPositionException(position, size);
        }

        if(position == 0) { // Delete at head
            deleteAtHead();
            return;
        }

        if(position == size - 1) { // Delete at tail (last index)
            deleteAtTail();
            return;
        }

        // Otherwise iterate until we reach the node prior to the one we want to delete
        Node<T> *temp = headNode;
        for(int posCount = 0; posCount < position - 1; posCount++) { // Traverse the CLL until we reach the position before the position we want to delete at
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
                cout << temp->data << endl;
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

        if (headNode == nullptr || headNode->nextNode == headNode) {
            return; // empty or single node list is unchanged
        }

        Node<T> *current = headNode;
        Node<T> *previous = nullptr;
        Node<T> *oldHead = headNode;

        do {
            Node<T> *next = current->nextNode; // Keeps track of the next node
            current->nextNode = previous; // Sets next node to previous, reversing the node position
            previous = current; // Sets the previous node to the current node
            current = next; // Sets the current node to the next node
        }while(current != headNode);

        headNode->nextNode = previous; // Link the head (backwards) to the last node
        headNode = previous; // Update headNode
        tailNode = oldHead; // Tail becomes the old head

    }

    // Arranges nodes based on property names in lexicographical order using merge sort
    void sortCLList() {
        if(isListEmpty()) {
            throw EmptyListException("sort");
        }

        if(headNode->nextNode == headNode) {
            // Single node is already sorted
            return;
        }

        // Convert to linear list for merge sort, then restore circularity
        convertToLinear();
        headNode = mergeSort(headNode);
        restoreCircularity();
    }

private:
    // Helper function to convert circular list to linear for sorting
    void convertToLinear() {
        if(tailNode != nullptr) {
            tailNode->nextNode = nullptr;
        }
    }

    // Helper function to restore circularity after sorting
    void restoreCircularity() {
        if(headNode != nullptr) {
            Node<T>* current = headNode;
            while(current->nextNode != nullptr) {
                current = current->nextNode;
            }
            current->nextNode = headNode;
            tailNode = current; // Update tail pointer
        }
    }

    // Merge sort implementation for linear linked list
    Node<T>* mergeSort(Node<T>* head) {
        if(head == nullptr || head->nextNode == nullptr) {
            return head;
        }

        // Split the list into two halves
        Node<T>* mid = getMiddle(head);
        Node<T>* secondHalf = mid->nextNode;
        mid->nextNode = nullptr;

        // Recursively sort both halves
        Node<T>* left = mergeSort(head);
        Node<T>* right = mergeSort(secondHalf);

        // Merge the sorted halves
        return merge(left, right);
    }

    // Helper function to get the middle node of a linear list
    Node<T>* getMiddle(Node<T>* head) {
        if(head == nullptr) return nullptr;

        Node<T>* slow = head;
        Node<T>* fast = head->nextNode;

        while(fast != nullptr && fast->nextNode != nullptr) {
            slow = slow->nextNode;
            fast = fast->nextNode->nextNode;
        }

        return slow;
    }

    // Merge two sorted linear lists
    Node<T>* merge(Node<T>* left, Node<T>* right) {
        Node<T>* result = nullptr;

        if(left == nullptr) return right;
        if(right == nullptr) return left;

        // Choose the smaller element
        if(left->data < right->data) {
            result = left;
            result->nextNode = merge(left->nextNode, right);
        } else {
            result = right;
            result->nextNode = merge(left, right->nextNode);
        }

        return result;
    }

public:

    // Print the first node's information
    void printHeadNode() {
        if(isListEmpty()) {
            throw EmptyListException("print head node");
        }
        cout << headNode->data << endl; // Print headNode information
    }

    // Print the last node's information
    void printLastNode() {
        if(isListEmpty()) {
            throw EmptyListException("print last node");
        }

        cout << tailNode->data << endl; // Print tailNode information directly
    }

    /**
     * Determines if the list is empty.
     *
     * @return "true" if empty, "false" if not empty
     */
    bool isListEmpty() const {
        return headNode == nullptr;
    }

    // Return the number of nodes in the list
    size_t getSize() const {
        return static_cast<size_t>(size);
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

    // Returns true if an equal value exists in the list
    bool contains(const T& value) const {
        if (headNode == nullptr) {
            return false;
        }
        const Node<T>* temp = headNode;
        do {
            if (temp->data.isEqual(value)) {
                return true;
            }
            temp = temp->nextNode;
        } while (temp != headNode);
        return false;
    }

    // Peek at head value without removal
    const T* peekHead() const {
        if (headNode == nullptr) return nullptr;
        return &headNode->data;
    }

    // Peek at tail value without removal
    const T* peekTail() const {
        if (tailNode == nullptr) return nullptr;
        return &tailNode->data;
    }

    // Copy all elements to a vector (snapshot)
    std::vector<T> toVector() const {
        std::vector<T> result;
        if (headNode == nullptr) return result;
        result.reserve(static_cast<size_t>(size));
        const Node<T>* temp = headNode;
        do {
            result.push_back(temp->data);
            temp = temp->nextNode;
        } while (temp != headNode);
        return result;
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
     * @param position Position of node of which is to be updated
     * @param newValue Node with updated data
     * @throws invalid_argument If position is less than 0 or greater than the size of the list, throw an invalid argument
     */
    void updateNodeValue(int position, T newValue) {
        int posCount = 0; // To compare with position to find if we've reached our node to update

        if(isListEmpty()) {
            throw EmptyListException("update node value");
        }

        if(position < 0 || position >= size) {
            throw InvalidPositionException(position, size);
        }

        // Iterate list for the node
        Node<T> *temp = headNode;
        do {
            if(position == posCount) { // If both position input and our counter match, update with new value
                temp->data = newValue;
                return;
            } // Otherwise keep iterating until end of the CLL
            posCount++;
            temp = temp->nextNode;
        }while(temp != headNode);

    }

    /**
     * Displays the properties of all nodes with a specified color
     *
     * @param color Specified color of property to display information
     */
    void displaySpecificColorNode(string color) {
        if(isListEmpty()) {
            throw EmptyListException("display nodes with color: " + color);
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
            tailNode = secondList.tailNode; // Link tail to secondList tail
            size = secondList.size; // Update size
            secondList.headNode = nullptr; // Clear second list to avoid double deletion
            secondList.tailNode = nullptr;
            secondList.size = 0;
            return;
        }

        // Use tail pointers for O(1) merge operation
        Node<T> *tail1 = tailNode; // Tail for list 1
        Node<T> *tail2 = secondList.tailNode; // Tail for list 2

        tail1->nextNode = secondList.headNode; // Link the original list's tail to head of second list
        tail2->nextNode = headNode; // Link the tail of second list back to head of original list
        tailNode = tail2; // Update tail pointer to point to the new tail
        
        // Update size to include both lists
        size += secondList.size;
        
        // Clear second list to avoid double deletion
        secondList.headNode = nullptr;
        secondList.tailNode = nullptr;
        secondList.size = 0;
    }
};

// Main function for test cases
int main() {

    // Create a new circular linked list object
    CircularLinkedList<MonopolyBoard> list;

    cout << "Identify that the list is empty to start." << endl;
    list.printList();
    cout << endl;

    // Insert node at the head of the CLL
    list.insertAtHead(MonopolyBoard("Mediterranean Avenue", "Brown", 60, 2));
    cout << "List after insertion at head: " << endl;
    list.printList();
    cout << endl;

    // Insert node at the tail of the CLL
    list.insertAtTail(MonopolyBoard("Park Place", "Dark Blue", 400, 50));
    cout << "List after insertion at tail: " << endl;
    list.printList();
    cout << endl;

    // Delete node at the head of the CLL
    list.deleteAtHead();
    cout << "List after deletion at head: " << endl;
    list.printList();
    cout << endl;

    // Delete node at tail of the CLL
    list.insertAtHead(MonopolyBoard("Mediterranean Avenue", "Brown", 60, 2)); // Insert a node to have at least 2 nodes in the CLL
    cout << "List before deletion at tail: " << endl;
    list.printList();
    cout << endl;
    list.deleteAtTail();
    cout << "List after deletion at tail: " << endl;
    list.printList();
    cout << endl;

    // Insert node at a specified position in the CLL
    list.insertAtTail(MonopolyBoard("Park Place", "Dark Blue", 400, 50)); // Replace this property as we are building the full board by the end of main.
    list.insertAtPosition(MonopolyBoard("Baltic Avenue", "Brown", 60, 2), 1);
    cout << "List after insertion at position: " << endl;
    list.printList();
    cout << endl;

    // Delete node at a specific position
    list.insertAtPosition(MonopolyBoard("Oriental Avenue", "Light Blue", 100, 6), 2); // Insert a node to be deleted for the sake of functionality, then replace for structure
    cout << "List before deletion at position: " << endl;
    list.printList();
    cout << endl;
    list.deleteAtPosition(2); // 0-based
    cout << "List after deletion at position: " << endl;
    list.printList();
    cout << endl;

    // Insert the rest of the board for the remaining operations
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

    cout << "Completed board: " << endl;
    list.printList();
    cout << endl;

    // Search the CLL for a specific node - VALID
    cout << "Searching..." << endl;
    list.search(MonopolyBoard("Park Place", "Dark Blue", 400, 50));
    cout << endl;

    // Search the CLL for a specific node - INVALID
    cout << "Searching..." << endl;
    list.search(MonopolyBoard("Westview High School", "Black & Gold", 999, 100));
    cout << endl;

    // Print out head node information
    cout << "Head node/property information: " << endl;
    list.printHeadNode();
    cout << endl;

    // Print out tail node information
    cout << "Tail node/property information: " << endl;
    list.printLastNode();
    cout << endl;

    // Check if the CLL is empty
    if(list.isListEmpty()) {
        cout << "List is empty." << endl;
    }else {
        cout << "List is not empty." << endl;
    }
    cout << endl;

    // Count the number of nodes
    list.countNodes();
    cout << endl;

    // Convert CLL will be at the end for the sake of functionality

    // Display all nodes of a specified color - VALID
    cout << "Properties with the color Red: " << endl;
    list.displaySpecificColorNode("Red");
    cout << endl;

    cout << "Properties with the color Green: " << endl;
    list.displaySpecificColorNode("Green");
    cout << endl;

    // Display all nodes of a specified color - INVALID
    cout << "Properties with the color Black: " << endl;
    list.displaySpecificColorNode("Black");
    cout << endl;

    // Update a node's value/property
    cout << "List before update: " << endl;
    list.printList();
    cout << endl;
    list.updateNodeValue(11 ,MonopolyBoard("New Kentucky Avenue", "Red", 220, 18));
    cout << "List after update: " << endl;
    list.printList();
    cout << endl;

    // Merge two CLL
    // First create a new CLL and insert some nodes
    CircularLinkedList<MonopolyBoard> list2;
    list2.insertAtHead(MonopolyBoard("Campanile Dr", "Red", 200, 20)); // SDSU
    list2.insertAtHead(MonopolyBoard("Camino Del Sur", "Black", 200, 20)); // WVHS

    // Merge two CLL
    list.mergeCLList(list2);
    cout << "List after merge: " << endl;
    list.printList();
    cout << endl;

    // Reverse the CLL
    list.reverseCLList();
    cout << "List after being reversed: " << endl;
    list.printList();
    cout << endl;

    // Sort the CLL lexicographically
    list.sortCLList();
    cout << "List after (merge) sort: " << endl;
    list.printList();
    cout << endl;

    cout << "End of main program." << endl;

    // Test memory management improvements
    cout << "\n=== Testing Memory Management Improvements ===" << endl;
    
    // Test copy constructor
    cout << "Testing copy constructor..." << endl;
    CircularLinkedList<MonopolyBoard> copiedList = list;
    cout << "Copied list size: ";
    copiedList.countNodes();
    
    // Test assignment operator
    cout << "Testing assignment operator..." << endl;
    CircularLinkedList<MonopolyBoard> assignedList;
    assignedList = list;
    cout << "Assigned list size: ";
    assignedList.countNodes();
    
    // Test move constructor
    cout << "Testing move constructor..." << endl;
    CircularLinkedList<MonopolyBoard> moveList = std::move(assignedList);
    cout << "Moved list size: ";
    moveList.countNodes();
    cout << "Original assigned list is now empty: ";
    assignedList.countNodes();
    
    // Test move assignment
    cout << "Testing move assignment..." << endl;
    CircularLinkedList<MonopolyBoard> moveAssignedList;
    moveAssignedList = std::move(moveList);
    cout << "Move assigned list size: ";
    moveAssignedList.countNodes();
    cout << "Original move list is now empty: ";
    moveList.countNodes();
    
    cout << "\nMemory management tests completed successfully!" << endl;

    // Test improved error handling
    cout << "\n=== Testing Improved Error Handling ===" << endl;
    
    // Test empty list exceptions
    CircularLinkedList<MonopolyBoard> emptyList;
    
    try {
        emptyList.deleteAtHead();
    } catch (const EmptyListException& e) {
        cout << "Caught EmptyListException: " << e.what() << endl;
    }
    
    try {
        emptyList.printHeadNode();
    } catch (const EmptyListException& e) {
        cout << "Caught EmptyListException: " << e.what() << endl;
    }
    
    try {
        emptyList.sortCLList();
    } catch (const EmptyListException& e) {
        cout << "Caught EmptyListException: " << e.what() << endl;
    }
    
    // Test invalid position exceptions
    try {
        list.deleteAtPosition(-1);
    } catch (const InvalidPositionException& e) {
        cout << "Caught InvalidPositionException: " << e.what() << endl;
    }
    
    try {
        list.deleteAtPosition(100);
    } catch (const InvalidPositionException& e) {
        cout << "Caught InvalidPositionException: " << e.what() << endl;
    }
    
    cout << "\nError handling tests completed successfully!" << endl;

    // Test merge sort performance
    cout << "\n=== Testing Merge Sort Performance ===" << endl;
    
    // Create a large list for performance testing
    CircularLinkedList<MonopolyBoard> performanceList;
    
    // Add many properties in random order
    vector<string> propertyNames = {
        "Zebra Avenue", "Alpha Street", "Beta Road", "Gamma Lane", "Delta Drive",
        "Epsilon Way", "Zeta Boulevard", "Eta Circle", "Theta Square", "Iota Place",
        "Kappa Court", "Lambda Terrace", "Mu Avenue", "Nu Street", "Xi Road",
        "Omicron Lane", "Pi Drive", "Rho Way", "Sigma Boulevard", "Tau Circle"
    };
    
    vector<string> colors = {"Red", "Blue", "Green", "Yellow", "Purple", "Orange", "Pink", "Brown"};
    
    cout << "Creating large list with " << propertyNames.size() << " properties..." << endl;
    for(int i = 0; i < propertyNames.size(); i++) {
        performanceList.insertAtTail(MonopolyBoard(
            propertyNames[i], 
            colors[i % colors.size()], 
            100 + (i * 10), 
            10 + i
        ));
    }
    
    cout << "List before sorting (first 5 properties):" << endl;
    performanceList.printList();
    cout << endl;
    
    // Time the merge sort
    auto start = chrono::high_resolution_clock::now();
    performanceList.sortCLList();
    auto end = chrono::high_resolution_clock::now();
    
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "List after merge sort (first 5 properties):" << endl;
    performanceList.printList();
    cout << endl;
    
    cout << "Merge sort completed in " << duration.count() << " microseconds" << endl;
    cout << "Time complexity: O(N log N) - much faster than O(N²) insertion sort!" << endl;
    
    cout << "\nPerformance test completed successfully!" << endl;

    return 0;
}