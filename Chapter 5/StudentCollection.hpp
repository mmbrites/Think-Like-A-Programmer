#include "StudentRecord.hpp"

class studentCollection {

    private:
        struct studentNode {
            studentRecord studentData;
            studentNode * next;
        };

    public:
        studentCollection();
        studentCollection(const studentCollection & original);
        ~studentCollection();
        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int idNum);
        void removeRecord(int idNum);
        studentCollection & operator=(const studentCollection & rhs);
        void printListHead();

    private:
        typedef studentNode * studentList;
        studentList _listHead;

        void deleteList(studentList & listPtr);
        studentList copiedList(const studentList original);

};