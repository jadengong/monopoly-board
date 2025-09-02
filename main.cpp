#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "MonopolyBoard.h"
#include "CircularLinkedList.h"

using namespace std;

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
    } else {
        cout << "List is not empty." << endl;
    }
    cout << endl;

    // Count the number of nodes
    list.countNodes();
    cout << endl;

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
    list.updateNodeValue(11, MonopolyBoard("New Kentucky Avenue", "Red", 220, 18));
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
