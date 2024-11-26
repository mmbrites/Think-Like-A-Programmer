#pragma once

#include <unordered_map>

#include "StudentRecord.hpp"

// I changed the implementation to a map of int to pointers to studentRecord to test the _fields map in the studentRecord class
class studentCollection {

    public:
        studentCollection();
        studentCollection(const studentCollection & original);
        void addRecord(studentRecord & newStudent);
        studentRecord * findStudent(int studentID);

        void debugMap();

    private:
        std::unordered_map<int, studentRecord *> _studentMap;
        void copyMap(const std::unordered_map<int, studentRecord *> & original);

};