#include "scIterator.hpp"

scIterator::scIterator() { _current = NULL; }
scIterator::scIterator(studentCollection::studentNode * initial) { _current = initial; }

void scIterator::advance() {
    if (_current != nullptr)
        _current = _current->next;
}

bool scIterator::pastEnd() {
    return _current == nullptr;
}

studentRecord scIterator::student() {

    if (_current == nullptr) {
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    }

    return _current->studentData;

}