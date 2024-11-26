#include <iostream>
#include <string.h>
#include <vector>

using std::cout;
using std::vector;

#include "studentCollection.hpp"
#include "Pair.hpp"

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
    s1.addRecord(r6);

    cout << s1.findStudent(3978).name() << "\n";

    studentCollection s2(s1);
    s2.debugArray();

    cout << s2.findStudent(3978).name() << "\n";
    

}