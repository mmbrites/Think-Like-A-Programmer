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
        studentCollection(studentCollection && original);
        ~studentCollection();
        studentCollection & operator=(const studentCollection & rhs);
        studentCollection & operator=(studentCollection && rhs);

        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int idNum);
        void removeRecord(int idNum);
        void printListHead();
        double averageRecord();
        studentCollection recordsWithinRange(int lowest, int highest);

    private:
        typedef studentNode * studentList;
        studentList _listHead;

        void deleteList(studentList & listPtr);
        studentList copiedList(const studentList original);

};