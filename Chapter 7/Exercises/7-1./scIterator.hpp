#ifndef SCITERATOR_HPP
#define SCITERATOR_HPP

#include "studentCollection.hpp"

class scIterator {

    public:
        scIterator();
        scIterator(studentCollection::studentNode * initial);
        void advance();
        bool pastEnd();
        studentRecord student();

    private:
        studentCollection::studentNode * _current;

};

#endif