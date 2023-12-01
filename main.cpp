// Kiran Biswa
// CIS 1202 201
// November 29, 2023
// Write a function to calculate character offsets, throwing exceptions in error conditions.
// **************
// *** Part A ***
// **************

#include <iostream>
#include <stdexcept>
using namespace std;

// Define custom exceptions
class InvalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid character exception";
    }
};

class InvalidRangeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid range exception";
    }
};

// Function to calculate character offsets
char character(char start, int offset) {
    // Checks if start is a letter
    if (!isalpha(start)) {
        throw InvalidCharacterException();
    }

    // Checks if the target is a letter
    char result = start + offset;
    if (!isalpha(offset)) {
        throw InvalidRangeException();
    }

    return result;
}

int main() {
    char start;
    int offset;
    
    // Gets user input for start and offset
    cout << "Enter a character (A-Z, a-z): ";
    cin >> start;

    cout << "Enter an offset value: ";
    cin >> offset;

    try {
        // Tests the character function with user input
        cout << "Result: " << character(start, offset) << endl;
    } catch (const InvalidCharacterException& e) {
        cerr << e.what() << endl;
    } catch (const InvalidRangeException& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
