# Monopoly Board - Circular Linked List Implementation

## Overview
This project implements a comprehensive Monopoly game board simulation using a high-performance circular linked list data structure. The implementation features advanced C++ programming techniques, memory management, and performance optimizations.

### Key Features
- **Complete Circular Linked List Operations**: Insert, Delete, Search, Print, Reverse, Sort, Merge, Update, Count, Convert
- **Memory Management**: Rule of Five implementation with proper destructors and move semantics
- **Performance Optimizations**: O(1) tail operations with tail pointer, O(N log N) merge sort
- **Error Handling**: Custom exception classes with comprehensive error management
- **Modern C++**: C++20 features, templates, and best practices
- **Professional Code Organization**: Separated header/implementation files

Each node represents a Monopoly property with name, color, value, and rent information.

## Project Structure
```
monopoly-board/
├── MonopolyBoard.h          # Header for MonopolyBoard class
├── MonopolyBoard.cpp        # Implementation for MonopolyBoard class
├── CircularLinkedList.h     # Header for CircularLinkedList template
├── CircularLinkedList.hpp   # Template implementation file
├── main.cpp                 # Main function and comprehensive tests
├── CMakeLists.txt           # Build configuration
└── README.md               # This file
```

## How to Run the Code

### Prerequisites
- **C++ Compiler**: GCC 10+ or Clang 10+ with C++20 support
- **CMake**: Version 3.16 or higher
- **Operating System**: Windows, macOS, or Linux
- **IDE** (optional): CLion, VSCode, or any C++ compatible editor

### Build Instructions

#### Option 1: Using CMake (Recommended)
```bash
# Clone the repository
git clone <repository-url>
cd monopoly-board

# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
make

# Run the program
./sdsu_projects
```

#### Option 2: Direct Compilation
```bash
# From the project root directory
g++ -std=c++20 -o sdsu_projects main.cpp MonopolyBoard.cpp

# Run the program
./sdsu_projects
```

#### Option 3: Using CLion
1. Open the project in CLion
2. The cmake-build-debug folder will be automatically generated
3. Run the project using the IDE's run configuration 

## Technical Improvements

### Memory Management
- **Rule of Five Implementation**: Complete destructor, copy constructor, assignment operator, move constructor, and move assignment operator
- **Exception Safety**: Strong exception safety guarantees with proper resource cleanup
- **No Memory Leaks**: Automatic memory management with proper destructor implementation

### Performance Optimizations
- **Tail Pointer**: O(1) tail operations instead of O(N) traversal
- **Merge Sort**: O(N log N) sorting algorithm instead of O(N²) insertion sort
- **Efficient Algorithms**: Optimized implementations for all operations

### Error Handling
- **Custom Exceptions**: `EmptyListException` and `InvalidPositionException` classes
- **Consistent Error Management**: Standardized exception handling throughout the codebase
- **Input Validation**: Comprehensive parameter validation with descriptive error messages

## Operations Documentation

### Core Operations

#### Insertion Operations
- **`insertAtHead(T value)`**: Insert at the beginning - **O(1)** with tail pointer
- **`insertAtTail(T value)`**: Insert at the end - **O(1)** with tail pointer  
- **`insertAtPosition(T value, int position)`**: Insert at specific position - **O(N)**

#### Deletion Operations
- **`deleteAtHead()`**: Delete from beginning - **O(1)** with tail pointer
- **`deleteAtTail()`**: Delete from end - **O(1)** with tail pointer
- **`deleteAtPosition(int position)`**: Delete at specific position - **O(N)**

#### Search and Display
- **`search(T value)`**: Find specific element - **O(N)**
- **`printList()`**: Display all elements - **O(N)**
- **`printHeadNode()`**: Display first element - **O(1)**
- **`printLastNode()`**: Display last element - **O(1)** with tail pointer

### Advanced Operations

#### List Manipulation
- **`reverseCLList()`**: Reverse the entire list - **O(N)**
- **`sortCLList()`**: Sort using merge sort - **O(N log N)**
- **`mergeCLList(CircularLinkedList& secondList)`**: Merge two lists - **O(1)** with tail pointer

#### Utility Operations
- **`countNodes()`**: Count total elements - **O(N)**
- **`isListEmpty()`**: Check if list is empty - **O(1)**
- **`updateNodeValue(int position, T newValue)`**: Update element at position - **O(N)**
- **`displaySpecificColorNode(string color)`**: Filter by color - **O(N)**
- **`convertCLList()`**: Convert to linear list - **O(1)**

### Time Complexity Summary
| Operation | Time Complexity | Notes |
|-----------|----------------|-------|
| Insert/Delete at Head/Tail | O(1) | With tail pointer optimization |
| Insert/Delete at Position | O(N) | Requires traversal to position |
| Search | O(N) | Linear search through list |
| Sort | O(N log N) | Merge sort implementation |
| Reverse | O(N) | Single pass through list |
| Merge | O(1) | Direct pointer manipulation |

## Testing and Validation

The project includes comprehensive testing that demonstrates:

### Memory Management Tests
- Copy constructor functionality
- Assignment operator behavior  
- Move constructor and move assignment
- Proper resource cleanup

### Error Handling Tests
- Empty list exception handling
- Invalid position exception handling
- Input validation and error messages

### Performance Tests
- Merge sort timing with large datasets
- Performance comparison with previous implementations
- Memory usage optimization verification

## Code Quality Features

### Modern C++ Practices
- **C++20 Standard**: Latest language features and improvements
- **Template Programming**: Generic, reusable data structure
- **RAII**: Resource Acquisition Is Initialization for memory safety
- **Exception Safety**: Strong exception safety guarantees

### Professional Development
- **Header Guards**: Prevent multiple inclusion issues
- **Const Correctness**: Proper use of const methods and parameters
- **Documentation**: Comprehensive inline documentation
- **Separation of Concerns**: Clean separation between interface and implementation

## Future Enhancements

Potential improvements for future development:
- Iterator support for range-based loops
- Unit testing framework integration
- Doxygen documentation generation
- Thread safety considerations
- Additional sorting algorithms
- Performance benchmarking suite
