#ifndef STUDENTCOLLECTION_HPP
#define STUDENTCOLLECTION_HPP

#include <list>

using std::list;

#include "StudentRecord.hpp"

class scIterator;

class studentCollection {

    public:
        studentCollection();
        studentCollection(const studentCollection & original);
        void addRecord(studentRecord newStudent);
        double averageRecord();

        void debugList();

    private:
        list<studentRecord> _studentList;
        void copiedList(const list<studentRecord> original);

};

#endif