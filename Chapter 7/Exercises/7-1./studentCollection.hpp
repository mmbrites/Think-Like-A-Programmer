#ifndef STUDENTCOLLECTION_HPP
#define STUDENTCOLLECTION_HPP

#include "StudentRecord.hpp"

class scIterator;

class studentCollection {

    private:
        struct studentNode {
            studentRecord studentData;
            studentNode * next;
        };
        typedef bool (* firstStudentPolicy)(studentRecord r1, studentRecord r2); // new type that corresponds to a pointer to a function that returns a 'bool' and takes two parameters of type 'studentRecord'

    public:
        studentCollection();
        studentCollection(const studentCollection & original);
        ~studentCollection();
        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int idNum);
        void removeRecord(int idNum);
        studentCollection & operator=(const studentCollection & rhs);
        void printListHead();

        // Enumeration for 'firstStudentPolicy' selection
        enum StudentPolicy { HIGHER_GRADE, LOWER_STUDENT_NUMBER, NAME_FIRST };

        // First Student Policies
        static bool higherGrade(studentRecord r1, studentRecord r2);
        static bool lowerStudentNumber(studentRecord r1, studentRecord r2);
        static bool nameComesFirst(studentRecord r1, studentRecord r2);

        // First Student Functions
        void setFirstStudentPolicy(StudentPolicy policy);
        studentRecord firstStudent();

        // Iterator
        friend class scIterator;
        scIterator firstItemIterator();

    private:
        typedef studentNode * studentList;
        studentList _listHead;
        firstStudentPolicy _currentPolicy;
        void deleteList(studentList & listPtr);
        studentList copiedList(const studentList original);

};

#endif