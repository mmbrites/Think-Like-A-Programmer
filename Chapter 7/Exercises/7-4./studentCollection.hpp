#pragma once

#include <vector>

using std::vector;

#include "StudentRecord.hpp"
#include "Pair.hpp"

class studentCollection {

    public:
        studentCollection();
        studentCollection(const studentCollection & original);
        void addRecord(studentRecord newStudent);
        studentRecord findStudent(int studentID);

        void debugArray();

    private:
        vector<Pair<int, studentRecord>> _studentMap;
        const int STARTING_SIZE = 1024;
        void copyMap(const vector<Pair<int, studentRecord>> & original);
        int hash(int key);

};