// EXERCISE 5-3./5-4./5-5./5-6.

#include <utility>
#include <iostream>

using std::cout;

#include "VariableLengthString.hpp"

// DEFAULT CONSTRUCTOR
VariableLengthString::VariableLengthString() {
    _charArray = nullptr;
}

VariableLengthString::VariableLengthString(char * s, int length) {
    _charArray = nullptr;
    setCharArray(s, length);
}

// COPY CONSTRUCTOR
VariableLengthString::VariableLengthString(const VariableLengthString & vls) {
    _charArray = nullptr;
    setCharArray(vls.charArray(), vls.length());
}

// MOVE CONSTRUCTOR
VariableLengthString::VariableLengthString(VariableLengthString && s) {
    _charArray = s._charArray;
    s._charArray = nullptr;
}

// DESTRUCTOR
VariableLengthString::~VariableLengthString() {

    delete[] _charArray;
    _charArray = nullptr;
        
}

// COPY ASSIGNMENT - THE WAY OF THE BOOK
VariableLengthString & VariableLengthString::operator=(const VariableLengthString & rhs) {

    if (this != &rhs) {

        delete[] _charArray;
        setCharArray(rhs._charArray, rhs.length());

    }
    
    return *this;

}

// MOVE ASSIGNMENT
VariableLengthString & VariableLengthString::operator=(VariableLengthString && rhs) {

    swap(rhs);
    return *this;

}

// IF YOU WANT ADDITION CHAINING YOU NEED 'VariableLengthString &' AS RETURN VALUE - THAT WOULD ALSO CHANGE A S1 = S2 + S3; TO A COPY ASSIGNMENT INSTEAD OF A MOVE ASSIGNMENT
VariableLengthString VariableLengthString::operator+(const VariableLengthString & rhs) {

    concatenate(rhs);
    return *this;

}

char VariableLengthString::operator[](int position) {
    return characterAt(position);
}

VariableLengthString::arrayString VariableLengthString::charArray() const {
    return _charArray;
}

void VariableLengthString::setCharArray(char * s, int length) {

    _charArray = new char[length];
    
    for (int i = 0; i < length; i++)
        _charArray[i] = s[i];

}

// OPERATIONS

char VariableLengthString::characterAt(int position) {
    return _charArray[position];
}

void VariableLengthString::append(char c) {

    int oldLength = length();

    arrayString newS = new char[oldLength + 1];
    for (int i = 0; i < oldLength; i++)
        newS[i] = _charArray[i];

    newS[oldLength] = c;

    clean(newS, oldLength + 1);

}

void VariableLengthString::concatenate(const VariableLengthString s) {

    int currentArrayOldLength = length();
    int addedArrayLength = s.length();
    int resultLength = currentArrayOldLength + addedArrayLength;
    arrayString newS = new char[resultLength + 1];

    arrayString sArray = s.charArray();
    
    for (int i = 0; i < currentArrayOldLength; i++)
        newS[i] = _charArray[i];

    for (int i = 0; i < addedArrayLength; i++)
        newS[currentArrayOldLength + i] = sArray[i];

    clean(newS, resultLength);
   
}

void VariableLengthString::remove(int start, int stretch) {

    int newLength = length() - stretch;
    arrayString newS = new char[newLength + 1];

    for (int i = 0; i < start; i++)
        newS[i] = _charArray[i];

    for (int i = start; i < newLength; i++)
        newS[i] = _charArray[i + stretch];

    clean(newS, newLength);

}

// PRIVATE FUNCTIONS

// SWAP
void VariableLengthString::swap(VariableLengthString & other) {
    std::swap(_charArray, other._charArray);
}

int VariableLengthString::length() const {

    int count = 0;
    while (_charArray[count] != 0)
        count++;
    return count;

}

void VariableLengthString::clean(arrayString & s, int length) {

    s[length] = 0;
    delete[] _charArray;
    _charArray = s;

}