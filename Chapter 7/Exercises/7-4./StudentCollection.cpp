#include <iostream>
#include <vector>

using std::cout;
using std::vector;

#include "studentCollection.hpp"

studentCollection::studentCollection() { 
    _studentMap.reserve(STARTING_SIZE);
    _studentMap.resize(STARTING_SIZE); // needed, otherwise the iterators do not work well due to the need to insert at random locations
}

// COPY CONSTRUCTOR
studentCollection::studentCollection(const studentCollection & original) {
    _studentMap.reserve(original._studentMap.capacity());
    _studentMap.resize(original._studentMap.capacity());
    copyMap(original._studentMap);
}

void studentCollection::addRecord(studentRecord newStudent) {

    Pair<int, studentRecord> p(newStudent.studentID(), newStudent);

    if (!_studentMap[hash(newStudent.studentID())].initialised()) {
        _studentMap.erase(_studentMap.begin() + hash(newStudent.studentID())); // needed since we are technically replacing a value, not inserting :) we do not want to increase the size of the map
        _studentMap.insert(_studentMap.begin() + hash(newStudent.studentID()), p);
    }
    else {

        int toHash = hash(newStudent.studentID());

        while (true) {

            if (!_studentMap[hash(toHash)].initialised()) {
                _studentMap.erase(_studentMap.begin() + hash(toHash));
                _studentMap.insert(_studentMap.begin() + hash(toHash), p);
                break;
            }
            else
                toHash = hash(toHash);

        }

    }

}

studentRecord studentCollection::findStudent(int studentID) {

    int toHash = studentID;

    while (true) {

        int key = hash(toHash);

        if (!_studentMap[key].initialised()) {

            studentRecord dummyRecord;
            return dummyRecord;

        }

        Pair<int, studentRecord> pair = _studentMap[key];
        if (pair.value().studentID() == studentID)
            return pair.value();
        toHash = key;
    
    }

}

void studentCollection::debugArray() {

    for (vector<Pair<int, studentRecord>>::iterator it = _studentMap.begin(); it != _studentMap.begin() + _studentMap.capacity(); ++it) {
        if ((*it).initialised())
            cout << (*it).value().name() << "\n";
    }

}

void studentCollection::copyMap(const vector<Pair<int, studentRecord>> & original) {

    for (vector<Pair<int, studentRecord>>::const_iterator it = original.cbegin(); it != original.cbegin() + original.capacity(); ++it) {

        if ((*it).initialised())
            addRecord((*it).value());

    }

}

int studentCollection::hash(int key) {
    return key % _studentMap.capacity() - 1;
}