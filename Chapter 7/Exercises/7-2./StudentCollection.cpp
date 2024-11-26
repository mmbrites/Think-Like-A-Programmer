#include <iostream>
#include <string.h>
#include <list>

using std::cout;

#include "studentCollection.hpp"

studentCollection::studentCollection() { }

// COPY CONSTRUCTOR
studentCollection::studentCollection(const studentCollection & original) {
    copiedList(original._studentList);
} 

void studentCollection::addRecord(studentRecord newStudent) {
    _studentList.push_front(newStudent);
}

double studentCollection::averageRecord() {

    int sum = 0;
    for (std::list<studentRecord>::iterator it = _studentList.begin(); it != _studentList.end(); ++it)
        sum += (*it).grade();

    return (double) sum / _studentList.size();

}

void studentCollection::debugList() {

    for (std::list<studentRecord>::iterator it = _studentList.begin(); it != _studentList.end(); ++it)
        cout << (*it).name() << "\n";

}

void studentCollection::copiedList(const list<studentRecord> original) {
    
    for (std::list<studentRecord>::const_reverse_iterator it = original.crbegin(); it != original.crend(); ++it)
        _studentList.push_front(*it);

}