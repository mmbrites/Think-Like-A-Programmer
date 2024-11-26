#include <iostream>
#include <string.h>
#include <vector>

using std::cout;
using std::vector;

#include "studentCollection.hpp"

int main() {

    studentRecord r1(85, 5002, "John");
    studentRecord r2(77, 5500, "Elsie");
    studentRecord r3(79, 6700, "Miguel");
    studentRecord r4(85, 4500, "John");
    studentRecord r5(77, 5300, "Elsie");
    studentRecord r6(79, 5021, "Miguel");
    
    studentCollection s1;
    s1.addRecord(r1);
    s1.addRecord(r2);
    s1.addRecord(r3);
    s1.addRecord(r4);
    s1.addRecord(r5);
    s1.addRecord(r6);

    studentCollection s2(s1);
    s2.sortByStudentNumber();
    studentRecord found = s2.findStudent(5700);
    cout << found.name() << "\n";

}