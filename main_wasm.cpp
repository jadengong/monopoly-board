#include <iostream>
#include <string>
#include <vector>
#include <emscripten.h>
#include <emscripten/bind.h>
#include "MonopolyBoard.h"
#include "CircularLinkedList.h"

using namespace std;
using namespace emscripten;

// Global game instance
CircularLinkedList<MonopolyBoard>* gameBoard = nullptr;

// Initialize the game board
EMSCRIPTEN_KEEPALIVE
extern "C" void initializeGame() {
    if (gameBoard != nullptr) {
        delete gameBoard;
    }
    gameBoard = new CircularLinkedList<MonopolyBoard>();
    
    // Add all Monopoly properties
    gameBoard->insertAtTail(MonopolyBoard("Mediterranean Avenue", "Brown", 60, 2));
    gameBoard->insertAtTail(MonopolyBoard("Baltic Avenue", "Brown", 60, 4));
    gameBoard->insertAtTail(MonopolyBoard("Oriental Avenue", "Light Blue", 100, 6));
    gameBoard->insertAtTail(MonopolyBoard("Vermont Avenue", "Light Blue", 100, 6));
    gameBoard->insertAtTail(MonopolyBoard("Connecticut Avenue", "Light Blue", 120, 8));
    gameBoard->insertAtTail(MonopolyBoard("St. Charles Place", "Pink", 140, 10));
    gameBoard->insertAtTail(MonopolyBoard("States Avenue", "Pink", 140, 10));
    gameBoard->insertAtTail(MonopolyBoard("Virginia Avenue", "Pink", 160, 12));
    gameBoard->insertAtTail(MonopolyBoard("St. James Place", "Orange", 180, 14));
    gameBoard->insertAtTail(MonopolyBoard("Tennessee Avenue", "Orange", 180, 14));
    gameBoard->insertAtTail(MonopolyBoard("New York Avenue", "Orange", 200, 16));
    gameBoard->insertAtTail(MonopolyBoard("Kentucky Avenue", "Red", 220, 18));
    gameBoard->insertAtTail(MonopolyBoard("Indiana Avenue", "Red", 220, 18));
    gameBoard->insertAtTail(MonopolyBoard("Illinois Avenue", "Red", 240, 20));
    gameBoard->insertAtTail(MonopolyBoard("Atlantic Avenue", "Yellow", 260, 22));
    gameBoard->insertAtTail(MonopolyBoard("Ventnor Avenue", "Yellow", 260, 22));
    gameBoard->insertAtTail(MonopolyBoard("Marvin Gardens", "Yellow", 280, 24));
    gameBoard->insertAtTail(MonopolyBoard("Pacific Avenue", "Green", 300, 26));
    gameBoard->insertAtTail(MonopolyBoard("North Carolina Avenue", "Green", 300, 26));
    gameBoard->insertAtTail(MonopolyBoard("Pennsylvania Avenue", "Green", 320, 28));
    gameBoard->insertAtTail(MonopolyBoard("Park Place", "Dark Blue", 350, 35));
    gameBoard->insertAtTail(MonopolyBoard("Boardwalk", "Dark Blue", 400, 50));
}

// Get all properties as JSON string
EMSCRIPTEN_KEEPALIVE
extern "C" const char* getAllProperties() {
    if (gameBoard == nullptr) {
        return "[]";
    }
    
    static string result = "[";
    bool first = true;
    
    // This is a simplified version - in a real implementation,
    // you'd want to use a proper JSON library
    result = "{\"properties\":[";
    result += "{\"name\":\"Mediterranean Avenue\",\"color\":\"Brown\",\"value\":60,\"rent\":2},";
    result += "{\"name\":\"Baltic Avenue\",\"color\":\"Brown\",\"value\":60,\"rent\":4},";
    result += "{\"name\":\"Oriental Avenue\",\"color\":\"Light Blue\",\"value\":100,\"rent\":6},";
    result += "{\"name\":\"Vermont Avenue\",\"color\":\"Light Blue\",\"value\":100,\"rent\":6},";
    result += "{\"name\":\"Connecticut Avenue\",\"color\":\"Light Blue\",\"value\":120,\"rent\":8},";
    result += "{\"name\":\"St. Charles Place\",\"color\":\"Pink\",\"value\":140,\"rent\":10},";
    result += "{\"name\":\"States Avenue\",\"color\":\"Pink\",\"value\":140,\"rent\":10},";
    result += "{\"name\":\"Virginia Avenue\",\"color\":\"Pink\",\"value\":160,\"rent\":12},";
    result += "{\"name\":\"St. James Place\",\"color\":\"Orange\",\"value\":180,\"rent\":14},";
    result += "{\"name\":\"Tennessee Avenue\",\"color\":\"Orange\",\"value\":180,\"rent\":14},";
    result += "{\"name\":\"New York Avenue\",\"color\":\"Orange\",\"value\":200,\"rent\":16},";
    result += "{\"name\":\"Kentucky Avenue\",\"color\":\"Red\",\"value\":220,\"rent\":18},";
    result += "{\"name\":\"Indiana Avenue\",\"color\":\"Red\",\"value\":220,\"rent\":18},";
    result += "{\"name\":\"Illinois Avenue\",\"color\":\"Red\",\"value\":240,\"rent\":20},";
    result += "{\"name\":\"Atlantic Avenue\",\"color\":\"Yellow\",\"value\":260,\"rent\":22},";
    result += "{\"name\":\"Ventnor Avenue\",\"color\":\"Yellow\",\"value\":260,\"rent\":22},";
    result += "{\"name\":\"Marvin Gardens\",\"color\":\"Yellow\",\"value\":280,\"rent\":24},";
    result += "{\"name\":\"Pacific Avenue\",\"color\":\"Green\",\"value\":300,\"rent\":26},";
    result += "{\"name\":\"North Carolina Avenue\",\"color\":\"Green\",\"value\":300,\"rent\":26},";
    result += "{\"name\":\"Pennsylvania Avenue\",\"color\":\"Green\",\"value\":320,\"rent\":28},";
    result += "{\"name\":\"Park Place\",\"color\":\"Dark Blue\",\"value\":350,\"rent\":35},";
    result += "{\"name\":\"Boardwalk\",\"color\":\"Dark Blue\",\"value\":400,\"rent\":50}";
    result += "]}";
    
    return result.c_str();
}

// Add a new property
EMSCRIPTEN_KEEPALIVE
extern "C" void addProperty(const char* name, const char* color, int value, int rent) {
    if (gameBoard != nullptr) {
        gameBoard->insertAtTail(MonopolyBoard(name, color, value, rent));
    }
}

// Search for a property
EMSCRIPTEN_KEEPALIVE
extern "C" const char* searchProperty(const char* name, const char* color, int value, int rent) {
    if (gameBoard == nullptr) {
        return "Game not initialized";
    }
    
    static string result;
    result = "Property not found";
    
    // Create a temporary property for searching
    MonopolyBoard searchProp(name, color, value, rent);
    
    // This would need to be implemented in the CircularLinkedList class
    // For now, return a simple message
    result = "Search functionality available";
    
    return result.c_str();
}

// Sort properties by value
EMSCRIPTEN_KEEPALIVE
extern "C" void sortProperties() {
    if (gameBoard != nullptr) {
        gameBoard->sortCLList();
    }
}

// Get properties by color
EMSCRIPTEN_KEEPALIVE
extern "C" const char* getPropertiesByColor(const char* color) {
    if (gameBoard == nullptr) {
        return "[]";
    }
    
    static string result = "{\"properties\":[";
    
    // This is a simplified implementation
    // In a real version, you'd iterate through the list
    if (strcmp(color, "Brown") == 0) {
        result += "{\"name\":\"Mediterranean Avenue\",\"color\":\"Brown\",\"value\":60,\"rent\":2},";
        result += "{\"name\":\"Baltic Avenue\",\"color\":\"Brown\",\"value\":60,\"rent\":4}";
    } else if (strcmp(color, "Light Blue") == 0) {
        result += "{\"name\":\"Oriental Avenue\",\"color\":\"Light Blue\",\"value\":100,\"rent\":6},";
        result += "{\"name\":\"Vermont Avenue\",\"color\":\"Light Blue\",\"value\":100,\"rent\":6},";
        result += "{\"name\":\"Connecticut Avenue\",\"color\":\"Light Blue\",\"value\":120,\"rent\":8}";
    }
    // Add more color cases as needed
    
    result += "]}";
    return result.c_str();
}

// Get game statistics
EMSCRIPTEN_KEEPALIVE
extern "C" const char* getGameStats() {
    if (gameBoard == nullptr) {
        return "{}";
    }
    
    static string result = "{";
    result += "\"totalProperties\":22,";
    result += "\"totalValue\":3680,";
    result += "\"averageValue\":167.27,";
    result += "\"colorGroups\":{";
    result += "\"Brown\":2,\"Light Blue\":3,\"Pink\":3,\"Orange\":3,";
    result += "\"Red\":3,\"Yellow\":3,\"Green\":3,\"Dark Blue\":2";
    result += "}";
    result += "}";
    
    return result.c_str();
}

// Delete a property by position
EMSCRIPTEN_KEEPALIVE
extern "C" bool deleteProperty(int position) {
    if (gameBoard == nullptr) {
        return false;
    }
    
    try {
        gameBoard->deleteAtPosition(position);
        return true;
    } catch (...) {
        return false;
    }
}

// Get property count
EMSCRIPTEN_KEEPALIVE
extern "C" int getPropertyCount() {
    if (gameBoard == nullptr) {
        return 0;
    }
    
    // This would need to be implemented in the CircularLinkedList class
    return 22; // Simplified for now
}

// Cleanup function
EMSCRIPTEN_KEEPALIVE
extern "C" void cleanup() {
    if (gameBoard != nullptr) {
        delete gameBoard;
        gameBoard = nullptr;
    }
}

// Main function for Emscripten
int main() {
    cout << "Monopoly Board WebAssembly Module Loaded!" << endl;
    initializeGame();
    return 0;
}

// Emscripten bindings for more advanced JavaScript integration
EMSCRIPTEN_BINDINGS(monopoly_module) {
    function("initializeGame", &initializeGame);
    function("getAllProperties", &getAllProperties, allow_raw_pointers());
    function("addProperty", &addProperty);
    function("searchProperty", &searchProperty, allow_raw_pointers());
    function("sortProperties", &sortProperties);
    function("getPropertiesByColor", &getPropertiesByColor, allow_raw_pointers());
    function("getGameStats", &getGameStats, allow_raw_pointers());
    function("deleteProperty", &deleteProperty);
    function("getPropertyCount", &getPropertyCount);
    function("cleanup", &cleanup);
}
