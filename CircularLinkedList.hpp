#ifndef CIRCULARLINKEDLIST_IMPL_H
#define CIRCULARLINKEDLIST_IMPL_H

// Template implementations for CircularLinkedList

template <typename T>
CircularLinkedList<T>::CircularLinkedList() {
    size = 0;
    headNode = nullptr;
    tailNode = nullptr;
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    clear();
}

template <typename T>
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList& other) {
    headNode = nullptr;
    tailNode = nullptr;
    size = 0;
    *this = other; // Use assignment operator
}

template <typename T>
CircularLinkedList<T>& CircularLinkedList<T>::operator=(const CircularLinkedList& other) {
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

template <typename T>
CircularLinkedList<T>::CircularLinkedList(CircularLinkedList&& other) noexcept {
    headNode = other.headNode;
    tailNode = other.tailNode;
    size = other.size;
    other.headNode = nullptr;
    other.tailNode = nullptr;
    other.size = 0;
}

template <typename T>
CircularLinkedList<T>& CircularLinkedList<T>::operator=(CircularLinkedList&& other) noexcept {
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

template <typename T>
void CircularLinkedList<T>::clear() {
    while (headNode != nullptr) {
        deleteAtHead();
    }
}

template <typename T>
void CircularLinkedList<T>::insertAtHead(T value) {
    Node<T>* newNode = new Node<T>(value);

    if(headNode == nullptr) {
        headNode = newNode;
        tailNode = newNode;
        newNode->nextNode = headNode;
    } else {
        newNode->nextNode = headNode;
        tailNode->nextNode = newNode;
        headNode = newNode;
    }
    ++size;
}

template <typename T>
void CircularLinkedList<T>::insertAtTail(T value) {
    Node<T>* newNode = new Node<T>(value);

    if(headNode == nullptr) {
        headNode = newNode;
        tailNode = newNode;
        newNode->nextNode = headNode;
    } else {
        tailNode->nextNode = newNode;
        newNode->nextNode = headNode;
        tailNode = newNode;
    }
    ++size;
}

template <typename T>
void CircularLinkedList<T>::insertAtPosition(T value, int position) {
    int index = 0;

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

    Node<T>* newNode = new Node<T>(value);

    if(headNode == nullptr) {
        headNode = newNode;
        tailNode = newNode;
        newNode->nextNode = headNode;
        ++size;
        return;
    }

    Node<T>* temp = headNode;

    while(temp->nextNode != headNode && index < position - 1) {
        temp = temp->nextNode;
        index++;
    }

    newNode->nextNode = temp->nextNode;
    temp->nextNode = newNode;
    ++size;
}

template <typename T>
void CircularLinkedList<T>::deleteAtHead() {
    if(headNode == nullptr) {
        throw EmptyListException("delete at head");
    }

    if(headNode->nextNode == headNode) {
        delete headNode;
        headNode = nullptr;
        tailNode = nullptr;
    } else {
        Node<T>* toDelete = headNode;
        headNode = headNode->nextNode;
        tailNode->nextNode = headNode;
        delete toDelete;
    }
    --size;
}

template <typename T>
void CircularLinkedList<T>::deleteAtTail() {
    if(headNode == nullptr) {
        throw EmptyListException("delete at tail");
    }

    if(headNode->nextNode == headNode) {
        delete headNode;
        headNode = nullptr;
        tailNode = nullptr;
    } else {
        Node<T>* temp = headNode;

        while(temp->nextNode != tailNode) {
            temp = temp->nextNode;
        }

        Node<T>* toDelete = tailNode;
        temp->nextNode = headNode;
        tailNode = temp;
        delete toDelete;
    }
    size--;
}

template <typename T>
void CircularLinkedList<T>::deleteAtPosition(int position) {
    if(headNode == nullptr) {
        throw EmptyListException("delete at position " + std::to_string(position));
    }

    if(position == 0) {
        deleteAtHead();
    } else if(position == size) {
        deleteAtTail();
    } else if(position < 0 || position >= size) {
        throw InvalidPositionException(position, size);
    } else {
        Node<T>* temp = headNode;
        int posCount = 0;

        for(posCount = 0; posCount < position - 1; posCount++) {
            temp = temp->nextNode;
        }

        Node<T>* toDelete = temp->nextNode;
        temp->nextNode = temp->nextNode->nextNode;
        delete toDelete;
        size--;
    }
}

template <typename T>
void CircularLinkedList<T>::search(T value) {
    Node<T>* temp = headNode;
    bool found = false;
    do {
        if (temp->data.isEqual(value)) {
            std::cout << temp->data << std::endl;
            found = true;
        }
        temp = temp->nextNode;
    } while (temp != headNode);

    if(!found) {
        std::cout << "Property not on the list." << std::endl;
    }
}

template <typename T>
void CircularLinkedList<T>::printList() {
    Node<T>* temp = headNode;

    if(temp == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    do {
        temp->data.print();
        temp = temp->nextNode;

        if(temp != headNode) {
            std::cout << " -> ";
        }
    } while(temp != headNode);
}

template <typename T>
void CircularLinkedList<T>::reverseCLList() {
    Node<T>* current = headNode;
    Node<T>* previous = nullptr;

    do {
        Node<T>* next = current->nextNode;
        current->nextNode = previous;
        previous = current;
        current = next;
    } while(current != headNode);

    headNode->nextNode = previous;
    headNode = previous;
}

template <typename T>
void CircularLinkedList<T>::sortCLList() {
    if(isListEmpty()) {
        throw EmptyListException("sort");
    }

    if(headNode->nextNode == headNode) {
        return; // Single node is already sorted
    }

    convertToLinear();
    headNode = mergeSort(headNode);
    restoreCircularity();
}

template <typename T>
void CircularLinkedList<T>::convertToLinear() {
    if(tailNode != nullptr) {
        tailNode->nextNode = nullptr;
    }
}

template <typename T>
void CircularLinkedList<T>::restoreCircularity() {
    if(headNode != nullptr) {
        Node<T>* current = headNode;
        while(current->nextNode != nullptr) {
            current = current->nextNode;
        }
        current->nextNode = headNode;
        tailNode = current;
    }
}

template <typename T>
Node<T>* CircularLinkedList<T>::mergeSort(Node<T>* head) {
    if(head == nullptr || head->nextNode == nullptr) {
        return head;
    }

    Node<T>* mid = getMiddle(head);
    Node<T>* secondHalf = mid->nextNode;
    mid->nextNode = nullptr;

    Node<T>* left = mergeSort(head);
    Node<T>* right = mergeSort(secondHalf);

    return merge(left, right);
}

template <typename T>
Node<T>* CircularLinkedList<T>::getMiddle(Node<T>* head) {
    if(head == nullptr) return nullptr;

    Node<T>* slow = head;
    Node<T>* fast = head->nextNode;

    while(fast != nullptr && fast->nextNode != nullptr) {
        slow = slow->nextNode;
        fast = fast->nextNode->nextNode;
    }

    return slow;
}

template <typename T>
Node<T>* CircularLinkedList<T>::merge(Node<T>* left, Node<T>* right) {
    Node<T>* result = nullptr;

    if(left == nullptr) return right;
    if(right == nullptr) return left;

    if(left->data < right->data) {
        result = left;
        result->nextNode = merge(left->nextNode, right);
    } else {
        result = right;
        result->nextNode = merge(left, right->nextNode);
    }

    return result;
}

template <typename T>
void CircularLinkedList<T>::printHeadNode() {
    if(isListEmpty()) {
        throw EmptyListException("print head node");
    }
    std::cout << headNode->data << std::endl;
}

template <typename T>
void CircularLinkedList<T>::printLastNode() {
    if(isListEmpty()) {
        throw EmptyListException("print last node");
    }
    std::cout << tailNode->data << std::endl;
}

template <typename T>
bool CircularLinkedList<T>::isListEmpty() {
    return headNode == nullptr;
}

template <typename T>
void CircularLinkedList<T>::countNodes() {
    if(headNode == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node<T>* temp = headNode;
    int count = 0;

    do {
        temp = temp->nextNode;
        count++;
    } while(temp != headNode);

    std::cout << "Total count of nodes is: " << count << std::endl;
}

template <typename T>
void CircularLinkedList<T>::convertCLList() {
    if(isListEmpty()) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    if(tailNode != nullptr) {
        tailNode->nextNode = nullptr;
    }
}

template <typename T>
void CircularLinkedList<T>::updateNodeValue(int position, T newValue) {
    int posCount = 0;

    if(isListEmpty()) {
        throw EmptyListException("update node value");
    }

    if(position < 0 || position >= size) {
        throw InvalidPositionException(position, size);
    }

    Node<T>* temp = headNode;
    do {
        if(position == posCount) {
            temp->data = newValue;
            return;
        }
        posCount++;
        temp = temp->nextNode;
    } while(temp != headNode);
}

template <typename T>
void CircularLinkedList<T>::displaySpecificColorNode(std::string color) {
    if(isListEmpty()) {
        throw EmptyListException("display nodes with color: " + color);
    }

    bool found = false;
    Node<T>* temp = headNode;

    do {
        if(temp->data.getColor() == color) {
            std::cout << temp->data << std::endl;
            found = true;
        }
        temp = temp->nextNode;
    } while(temp != headNode);

    if(!found) {
        std::cout << "There are no properties on the list with this color." << std::endl;
    }
}

template <typename T>
void CircularLinkedList<T>::mergeCLList(CircularLinkedList<T>& secondList) {
    if(secondList.headNode == nullptr) {
        std::cout << "Second list is empty. There is nothing to merge." << std::endl;
        return;
    }

    if(isListEmpty()) {
        headNode = secondList.headNode;
        tailNode = secondList.tailNode;
        size = secondList.size;
        secondList.headNode = nullptr;
        secondList.tailNode = nullptr;
        secondList.size = 0;
        return;
    }

    Node<T>* tail1 = tailNode;
    Node<T>* tail2 = secondList.tailNode;

    tail1->nextNode = secondList.headNode;
    tail2->nextNode = headNode;
    tailNode = tail2;
    
    size += secondList.size;
    
    secondList.headNode = nullptr;
    secondList.tailNode = nullptr;
    secondList.size = 0;
}

#endif // CIRCULARLINKEDLIST_IMPL_H
