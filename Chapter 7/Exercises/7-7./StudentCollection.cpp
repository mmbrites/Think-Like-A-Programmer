#include <iostream>
#include <unordered_map>

using std::cout;

#include "studentCollection.hpp"

studentCollection::studentCollection() { }

// COPY CONSTRUCTOR
studentCollection::studentCollection(const studentCollection & original) {
    copyMap(original._studentMap);
}

void studentCollection::addRecord(studentRecord & newStudent) {
    _studentMap.insert({newStudent.studentID(), &newStudent});
}

studentRecord * studentCollection::findStudent(int studentID) {
    return _studentMap.find(studentID)->second; // method find(...) returns a pointer
}

void studentCollection::debugMap() {

    for (std::unordered_map<int, studentRecord *>::iterator it = _studentMap.begin(); it != _studentMap.end(); ++it)
            cout << (*it).second->name() << "\n";

}

void studentCollection::copyMap(const std::unordered_map<int, studentRecord *> & original) {
    _studentMap = original;
}