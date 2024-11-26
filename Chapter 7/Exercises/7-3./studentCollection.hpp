#ifndef STUDENTCOLLECTION_HPP
#define STUDENTCOLLECTION_HPP

#include <vector>

using std::vector;

#include "StudentRecord.hpp"

class scIterator;

class studentCollection {

    public:
        studentCollection();
        studentCollection(const studentCollection & original);
        void addRecord(studentRecord newStudent);
        void sortByStudentNumber();
        studentRecord findStudent(int studentID);

        void debugArray();

    private:
        vector<studentRecord> _studentList;
        void copyArray(const vector<studentRecord> original);
        static bool compareStudentNumbers(const studentRecord & recordA, const studentRecord & recordB);

};

#endif