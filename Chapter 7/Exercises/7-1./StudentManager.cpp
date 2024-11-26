#include <iostream>
#include <string.h>

using std::cout;

#include "studentCollection.hpp"
#include "scIterator.hpp"

bool higherGrade(studentRecord r1, studentRecord r2) {
    return r1.grade() > r2.grade();
}

bool lowerStudentNumber(studentRecord r1, studentRecord r2) {
    return r1.studentID() < r2.studentID();
}

bool nameComesFirst(studentRecord r1, studentRecord r2) {
    return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
}

int main() {

    studentRecord r1(85, 99837, "John");
    studentRecord r2(77, 4765, "Elsie");
    studentRecord r3(-1, 5032, "Miguel");
    
    studentCollection s1;
    studentCollection s2;
    studentCollection s3;
    s2.addRecord(r1);
    s2.addRecord(r3);
    s2.addRecord(r2);
    s1 = s3 = s2;

    s2.setFirstStudentPolicy(studentCollection::LOWER_STUDENT_NUMBER);
    cout << s2.firstStudent().studentID() << "\n";
    s2.setFirstStudentPolicy(studentCollection::HIGHER_GRADE);
    cout << s2.firstStudent().grade() << "\n";
    s2.setFirstStudentPolicy(studentCollection::NAME_FIRST);
    cout << s2.firstStudent().name() << "\n";

}