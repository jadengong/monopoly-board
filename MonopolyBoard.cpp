#include "MonopolyBoard.h"

// Constructor with default values
MonopolyBoard::MonopolyBoard() : propertyName(""), propertyColor(""), value(0), rent(0) {}

// Constructor with given parameter values
MonopolyBoard::MonopolyBoard(const std::string& propertyName, const std::string& propertyColor, 
                             const int value, const int rent) {
    this->propertyName = propertyName;
    this->propertyColor = propertyColor;
    this->value = value;
    this->rent = rent;
}

// Get the color of a property
std::string MonopolyBoard::getColor() const {
    return propertyColor;
}

// Determining if two objects are equal
bool MonopolyBoard::isEqual(const MonopolyBoard& other) const {
    return (propertyName == other.propertyName && 
            propertyColor == other.propertyColor && 
            value == other.value && 
            rent == other.rent);
}

// Compact Node Information
void MonopolyBoard::print() const {
    std::cout << "(Name: " << propertyName << ", Color: " << propertyColor 
              << ", Value: " << value << ", Rent: " << rent << ")" << std::endl;
}

// Operator overload for print
std::ostream& operator<<(std::ostream& os, const MonopolyBoard& obj) {
    std::cout << "Property found! Details below: " << std::endl;
    std::cout << "Property Name: " << obj.propertyName << std::endl;
    std::cout << "Property Color: " << obj.propertyColor << std::endl;
    std::cout << "Value: $" << obj.value << std::endl;
    std::cout << "Rent: $" << obj.rent << std::endl;
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
