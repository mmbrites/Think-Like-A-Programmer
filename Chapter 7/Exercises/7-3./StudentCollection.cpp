#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For std::round

using std::cout;
using std::vector;

#include "studentCollection.hpp"

studentCollection::studentCollection() { }

// COPY CONSTRUCTOR
studentCollection::studentCollection(const studentCollection & original) {
    copyArray(original._studentList);
}

void studentCollection::addRecord(studentRecord newStudent) {
    _studentList.push_back(newStudent);
}

bool studentCollection::compareStudentNumbers(const studentRecord & recordA, const studentRecord & recordB) {
    return recordA.studentID() < recordB.studentID();
}

void studentCollection::sortByStudentNumber() {
    std::sort(_studentList.begin(), _studentList.end(), compareStudentNumbers);
}

studentRecord studentCollection::findStudent(int id) {

    studentRecord student;

    // INTERPOLATION SEARCH
    int low = 0;
    int high = _studentList.size() - 1;
    
    // The last two comparisons evade complications when 'id' is not on the list
    while (high >= low && _studentList[low].studentID() <= id && _studentList[high].studentID() >= id) {
        
        int pos = std::round((double) low + (id - _studentList[low].studentID()) * (double) (high - low) / (_studentList[high].studentID() - _studentList[low].studentID()));

        if (_studentList[pos].studentID() == id) {
            student = _studentList[pos];
            break;
        }
        if (_studentList[pos].studentID() < id) {

            // needed to see if cycle is 'stuck'
            if (pos == low) low++;
            else low = pos;
        
        }
        else {

             // needed to see if cycle is 'stuck'
            if (pos == high) high--;
            else high = pos;

        }

    }

    return student;

}

void studentCollection::debugArray() {

    for (std::vector<studentRecord>::iterator it = _studentList.begin(); it != _studentList.end(); ++it)
        cout << (*it).name() << "\n";

}

void studentCollection::copyArray(const vector<studentRecord> original) {
    
    for (vector<studentRecord>::const_iterator it = original.cbegin(); it != original.cend(); ++it)
        _studentList.push_back(*it);

}