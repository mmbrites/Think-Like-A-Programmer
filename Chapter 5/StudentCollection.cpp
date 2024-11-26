#include "StudentCollection.hpp"
#include<iostream>

using std::cout;

studentCollection::studentCollection() {
    _listHead = NULL;
}

// COPY CONSTRUCTOR
studentCollection::studentCollection(const studentCollection & original) {
    _listHead = copiedList(original._listHead);
} 

studentCollection::~studentCollection() {
    deleteList(_listHead);
}

void studentCollection::addRecord(studentRecord newStudent) {

    studentNode * newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;

}

studentRecord studentCollection::recordWithNumber(int idNum) {

    studentNode * loopPtr = _listHead;

    while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum)
        loopPtr = loopPtr->next;

    if (loopPtr == NULL) {

        studentRecord dummyRecord(-1, -1, ""); // This is equal to studentRecord dummyRecord = new studentRecord(-1, -1, ""); in Java
        return dummyRecord;

    }
    else
        return loopPtr->studentData;

}

void studentCollection::removeRecord(int idNum) {

    studentNode * loopPtr = _listHead;
    studentNode * trailing = NULL;

    while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum) {
        trailing = loopPtr;
        loopPtr = loopPtr->next;
    }

    if (loopPtr == NULL) return;
    if (trailing == NULL)
        _listHead = loopPtr->next;
    else
        trailing->next = loopPtr->next;

    delete loopPtr;

}

studentCollection & studentCollection::operator=(const studentCollection & rhs) {

    if (this != &rhs) {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }

    return *this;

}

void studentCollection::printListHead() {

    cout << _listHead->studentData.grade() << "\n";

}

void studentCollection::deleteList(studentList & listPtr) {

    while (listPtr != NULL) {
        studentNode * temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }

}

studentCollection::studentList studentCollection::copiedList(const studentList original) {

    if (original == NULL)
        return NULL;

    studentList newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode * oldLoopPtr = original->next;
    studentNode * newLoopPtr = newList;

    while (oldLoopPtr != NULL) {
        newLoopPtr->next = new studentNode;
        newLoopPtr = newLoopPtr->next;
        newLoopPtr->studentData = oldLoopPtr->studentData;
        oldLoopPtr = oldLoopPtr->next;
    }

    newLoopPtr->next = NULL;
    return newList;

}