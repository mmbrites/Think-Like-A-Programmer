#include <iostream>
#include <string.h>
#include <vector>

using std::cout;
using std::vector;

#include "studentCollection.hpp"

int main() {

    studentRecord r1(85, 5002, "John");
    studentRecord r2(77, 5500, "Elsie");
    studentRecord r3(79, 3978, "Miguel");
    studentRecord r4(85, 4500, "Mercuria");
    studentRecord r5(77, 5300, "Ray");
    studentRecord r6(79, 5021, "W");

    studentCollection s1;
    s1.addRecord(r1);
    s1.addRecord(r2);
    s1.addRecord(r3);
    s1.addRecord(r4);
    s1.addRecord(r5);

    r1.addExtraField("Balance", 10);
    
    cout << std::get<int>(r1.retrieveField("Balance")) << "\n";
     cout << r1.addedFields() << "\n";
    cout << s1.findStudent(r1.studentID())->addedFields() << "\n";
    cout << std::get<int>(s1.findStudent(r1.studentID())->retrieveField("Balance")) << "\n";

}