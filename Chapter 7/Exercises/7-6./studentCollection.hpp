#pragma once

#include <unordered_map>

#include "StudentRecord.hpp"

class studentCollection {

    public:
        studentCollection();
        studentCollection(const studentCollection & original);
        void addRecord(studentRecord newStudent);
        studentRecord findStudent(int studentID);

        void debugMap();

    private:
        std::unordered_map<int, studentRecord> _studentMap;
        void copyMap(const std::unordered_map<int, studentRecord> & original);

};