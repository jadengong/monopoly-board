#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream>
#include <string>
#include <stdexcept>

// Custom exception classes for better error handling
class EmptyListException : public std::runtime_error {
public:
    EmptyListException(const std::string& operation) 
        : std::runtime_error("List is empty. Cannot perform operation: " + operation) {}
};

class InvalidPositionException : public std::invalid_argument {
public:
    InvalidPositionException(int position, int size) 
        : std::invalid_argument("Position " + std::to_string(position) + 
                               " is out of range. Valid range: 0 to " + std::to_string(size - 1)) {}
};

// Template Node class
template <typename T> 
class Node {
public:
    T data;
    Node* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

/**
 * @class CircularLinkedList
 * @brief A template class implementing a circular linked list data structure
 * @tparam T The type of data stored in the list
 */
template <typename T> 
class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;  // Tail pointer for O(1) tail operations
    int size;

    // Helper methods for merge sort
    void convertToLinear();
    void restoreCircularity();
    Node<T>* mergeSort(Node<T>* head);
    Node<T>* getMiddle(Node<T>* head);
    Node<T>* merge(Node<T>* left, Node<T>* right);

public:
    // Constructors and Destructor
    CircularLinkedList();
    ~CircularLinkedList();
    
    // Rule of Three/Five
    CircularLinkedList(const CircularLinkedList& other);
    CircularLinkedList& operator=(const CircularLinkedList& other);
    CircularLinkedList(CircularLinkedList&& other) noexcept;
    CircularLinkedList& operator=(CircularLinkedList&& other) noexcept;

    // Core Operations
    void insertAtHead(T value);
    void insertAtTail(T value);
    void insertAtPosition(T value, int position);
    void deleteAtHead();
    void deleteAtTail();
    void deleteAtPosition(int position);
    void search(T value);
    void printList();
    void clear();

    // Advanced Operations
    void reverseCLList();
    void sortCLList();
    void printHeadNode();
    void printLastNode();
    bool isListEmpty();
    void countNodes();
    void convertCLList();
    void updateNodeValue(int position, T newValue);
    void displaySpecificColorNode(std::string color);
    void mergeCLList(CircularLinkedList<T>& secondList);
};

// Template implementations must be in header file
#include "CircularLinkedList.hpp"

#endif // CIRCULARLINKEDLIST_H
