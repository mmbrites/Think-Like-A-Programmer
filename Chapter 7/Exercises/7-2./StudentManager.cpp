#include <iostream>
#include <string.h>

using std::cout;

#include "studentCollection.hpp"

int main() {

    studentRecord r1(85, 99837, "John");
    studentRecord r2(77, 4765, "Elsie");
    studentRecord r3(75, 5032, "Miguel");
    
    studentCollection s1;
    s1.addRecord(r1);
    s1.addRecord(r2);
    s1.addRecord(r3);

    s1.debugList();

    studentCollection s2(s1);

    s2.debugList();
    cout << s2.averageRecord() << "\n";

}