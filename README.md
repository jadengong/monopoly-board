# Monopoly Board

## Overview
This project implements a Monopoly game board simulation using a circular linked list, with operations such as:
- Insert
- Delete
- Search
- Print
- Reverse
- Sort
- Merge
- Update
- Count
- Convert

Each node represents a property on the board.
The program is written in C++ and can be executed from the CLion IDE, although it can be run on most IDEs or code editors.

# How to Run the Code
### Prerequisites
In order for the code to run, make sure that you have the appropriate environemnt for C++. Ensure that you have:
- **Compiler/IDE**
  - CLion
  - IntelliJ
  - VSCode
- **Libraries**
  - Standard Template Library for C++
- **Operating System**
  - Developed on Windows/macOS
- **Other**
  - CMake and Makefile
 
### Instructions
1. Clone the Repository
2. Open the Project
  - Launch your IDE of choice and open the cloned directory
3. Build the project (with CMake)
  1. Execute these commands in a terminal to create and navigate into a build directory
- ```
     mkdir build 
     cd build
  ```
  2. Then configure the project with CMake:
- ```
     cmake ..
  ```
  3. Lastly, build the project using make:
- ```
     make
     ```
If the project is built successfully, run the executable file named Monopoly_Board with the following command:
- ```
  ./sdsu_projects
  ```

The code will execute in the main function, and the CMake configuration that generate the build files are included in the repository. 

# Operations
## Insertion
### Insert at Head
```
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
            headNode = newNode; // Update headNode
        }
        ++size;
    }
```
Description: Inserts a node at the head of a circular linked list. Using a generic value, insertAtHead first handles if the CLL is empty, then iterates to the last node in order to insert the new node after the last node. Best case is O(1) is the list is empty, where we can insert without traversal. Worse case is O(N) since if the list is not empty, traversal must occur to reach the last node. 

Time Complexity: 
- Best Case: O(1)
- Worst Case: **O(N)** 

### Insert at Tail
```
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
```
Description: Inserts a node at the tail of a circular linked list. Using a generic value, insertAtTail first handles if the CLL is empty, then iterates to the last node in order to insert the new node there. The best case is O(1) is the list is empty, since a new node can be created and just adjust pointers. Worse case is O(N) if the list is not empty, and traversal must happen. 

Time Complexity: 
- Best Case: O(1)
- Worst Case: **O(N)**  

### Insert at Position
```
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

        newNode->nextNode = temp->nextNode; // pointing new node to next node
        temp->nextNode = newNode; // pointing previous node to new node

        ++size;
    }
```
Description: Inserts a node at a specified position of a circular linked list. Also using a generic value, insertAtPosition requires a position to insert a new node at. This method utilizes an invalid_argument if the position entered is inapplicable, and has base cases for inserting at the head or tail of the list. Best case of O(1) can be achieved if desired position is first or out of bounds. Worse case of O(N) can be achieved in most other cases, where a traversal must occur to reach the desired position. Average time complexity would be O(N) in most cases anyways. 

Time Complexity: 
- Best Case: O(1)
- Worst Case: **O(N)**

## Deletion
### Delete at Head
```
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
```
Description: Deletes a node at the head of a circular linked list. First checks if the list is empty, then if there is only one node in the list. Otherwise iterate to the last node and link the previous and next nodes prior to deletion. Best case of O(1) can be achieved if there is only one node in the list, or if the list is empty. Worse case of O(N) can be achieved if the list has more than one node, then traversal must happen. 

Time Complexity: 
- Best Case: O(1)
- Worst Case: **O(N)**

### Delete at Tail
```
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
```
Description: Deletes a node at the tail of a circular linked list. First checks if the list is empty, then if there is only one node in the list. Otherwise iterate to the node before the last node and link the previous and next nodes prior to deletion. Best case of O(1) can be achieved if the list has one or less nodes since a constant statement would check those cases. Worse case of O(N) can be achieved otherwise, when the list must traverse to the node before the last (N-2). 

Time Complexity: 
- Best Case: O(1)
- Worst Case: **O(N)**

### Delete at Position
```
void deleteAtPosition(int position) {
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
```
Description: Deletes a node at a specified position of a circular linked list. First checks if the list is empty, then if the position is at the head of the list. Otherwise iterate to the node desired using a counter and link previous and next nodes prior to deletion. Best case of O(1) can be achieved if position is the first in the list or if the bounds provided are invalid. Worse case of O(N) is achieved otherwise when the list must be traversed in order to get to the position specified. 

Time Complexity: 
- Best Case: O(1)
- Worst Case: **O(N)**

### Search
```
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
```
Description: Searches for a specific Monopoly property in a circular linked list. Requires a generic value to search for in the generic type list. Utilizes a bool flag as a checker if property has been found or not. Best case of O(1) can be achieved if value is found at the first node. Worst case of O(N) is achieved otherwise if we have to iterate through N elements to get to the one we want. Assignment and comparison operations are constant time, so anything that isn't the first node requires a traversal, and therefore a O(N) worse case time complexity. 

Time Complexity: 
- Best Case: O(1)
- Worst Case: **O(N)**

### Print List
```
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
```
Description: Prints the circular linked list by iterating from head to tail, and then looping back to the head.

Time Complexity:
- Best Case: O(1)
- Worst Case: **O(N)**

### Reverse the Circular Linked List
```
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
```
Description: Reverses the circular linked list by keeping track of the current and previous nodes while iterating, and setting previous to current, and current to next node. After reversal, the method also links the head to the last node, effectively re-circularizing the list. 

Time Complexity:
- Best Case: O(1)
- Worst Case: **O(N)**

### Sort the Circular Linked List
```
void sortCLList() {
        if(isListEmpty()) {
            cout << "List is empty. Cannot sort the list." << endl;
            return;
        }

        if(headNode->nextNode == headNode) {
            cout << "List has one node. Cannot sort the list." << endl;
            return;
        }

        Node<T> *sorted = nullptr; // Sorted part of the list
        Node<T> *current = headNode; // Current pointer to sort

        do {
            Node<T> *next = current->nextNode; // Save the next node before sort
            sortedInsert(&sorted, current);
            current = next;
        }while(current != headNode);

        // Restore circularity
        Node<T> *last = sorted;
        while(last->nextNode != sorted) {
            last = last->nextNode;
        }

        last->nextNode = sorted;
        headNode = sorted;
    }
```
Along with helper method: sortedInsert

```
void sortedInsert(Node<T> **sorted, Node<T> *newNode) {
        // If sorted list is empty
        if(*sorted == nullptr) {
            *sorted = newNode;
            newNode->nextNode = newNode; // Link new node to itself to circularize
            return;
        }

        // If new node is smaller than head node of sorted list
        if((*sorted)->data >= newNode->data) {
            Node<T> *last = *sorted;
            while(last->nextNode != *sorted) { // Find last node
                last = last->nextNode;
            }

            last->nextNode = newNode; // Point last node to new node
            newNode->nextNode = *sorted; // Point new node to current head
            *sorted = newNode; // Update head to the new node
        }else { // Otherwise the new node should be inserted somewhere in the middle or end
            Node<T> *current = *sorted;

            while(current->nextNode != *sorted && current->nextNode->data < newNode->data){
                current = current->nextNode;
            }
            // Insert new node and link
            newNode->nextNode = current->nextNode;
            current->nextNode = newNode;
        }
    }
```
Description: Arranges nodes based on property names in lexicographical order. Uses a helper method to insert nodes in the "sorted" segment of the list. Sort is based off of insertion sort. 

Time Complexity:
- Best Case: O(1) 
- Worst Case: **O(N<sup>2</sup>)**

### Print Head Node
```
 void printHeadNode() {
        if(isListEmpty()) {
            cout << "List is empty. Cannot print head node." << endl;
            return;
        }
        cout << headNode->data << endl; // Print headNode information
    }
```
Description: Prints the first node's information.

Time Complexity: 
- Best Case: O(1)
- Worst Case: **O(1)**

### Print Tail Node
```
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
```
Description: Prints the first node's information.

Time Complexity: 
- Best Case: O(1)
- Worst Case: **O(N)**

### Is List Empty
```
 bool isListEmpty() {
        return headNode == nullptr;
    }
```
Description: Checks if the list if empty.

Time Complexity: 
- Best Case: O(1)
- Worst Case: **O(1)**

### Count Nodes
```
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
```
Description: Counts the number of nodes in the list. First handles if the list is empty, then utilizes a counter while iterating the current list.

Time Complexity:
- Best Case: O(1)
- Worst Case: **O(N)**

### De-Circularize a Circular Linked List
```
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
```
Description: De-circularizes a circular linked list. First handles if the list is empty, then gets the last node and sets its next node pointer to null, effectively breaking the circle.

Time Complexity:
- Best Case: O(1)
- Worst Case: **O(N)**

### Update Node Value
```
void updateNodeValue(int position, T newValue) {
        int posCount = 0; // To compare with position to find if we've reached our node to update

        if(isListEmpty()) {
            cout << "List is empty. Cannot update node value." << endl;
        }

        if(position < 0 || position > size) {
            throw invalid_argument("Position out of range! Position must be LESS than the size of the list or GREATER than or EQUAL to zero");
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
```
Description: Updates the data of a specified node in a circular linked list. Utilizes two parameters: an integer position to find which node to update and a generic new value that contains the information to be updated with. Also throws an invalid argument is position is inapplicable. 

Time Complexity:
- Best Case: O(1)
- Worst Case: **O(N)**

### Display Specific Color Node Information
```
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
```
Description: Displays the properties of all nodes with a specified color. Requires a string parameter to search for in the list. Also utilizes a flag to check if properties are found with the input color, and handles the case if the color isn't found on the list. 

Time Complexity:
- Best Case: O(1)
- Worst Case: **O(N)**

### Merge two Circular Linked Lists
```
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
```
Description: Merges two circular linked lists. First handles the cases if the original or second list is empty, then uses the tails of both lists to link to their respective heads. 

Time Complexity: 
- Best Case: O(1)
- Worst Case: **O(N)** ; or whichever list is larger.


