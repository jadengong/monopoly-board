#ifndef MONOPOLYBOARD_H
#define MONOPOLYBOARD_H

#include <iostream>
#include <string>

/**
 * @class MonopolyBoard
 * @brief Represents a property on a Monopoly board with name, color, value, and rent
 */
class MonopolyBoard {
public:
    std::string propertyName;
    std::string propertyColor;
    int value;
    int rent;

    // Constructors
    MonopolyBoard();
    MonopolyBoard(const std::string& propertyName, const std::string& propertyColor, 
                  const int value, const int rent);

    // Getters
    std::string getColor() const;

    // Comparison methods
    bool isEqual(const MonopolyBoard& other) const;

    // Display methods
    void print() const;

    // Friend functions for operator overloading
    friend std::ostream& operator<<(std::ostream& os, const MonopolyBoard& obj);
    friend bool operator>=(const MonopolyBoard& lhs, const MonopolyBoard& rhs);
    friend bool operator<(const MonopolyBoard& lhs, const MonopolyBoard& rhs);
};

#endif // MONOPOLYBOARD_H
