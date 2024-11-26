#include <iostream>

#include "StudentCollection.hpp"

using std::cout;

int main() {

    studentCollection s1;
    studentCollection s2;
    studentCollection s3;
    studentRecord r1(85, 99837, "John");
    s2.addRecord(r1);
    studentRecord r2(77, 4765, "Elsie");
    s2.addRecord(r2);
    studentRecord r3(50, 4764, "Dlsie");
    s1 = s3 = s2;
    s1.addRecord(r3);

    s2.printListHead();
    //s2.removeRecord(4765);
    s2.printListHead();

    cout << s2.averageRecord() << "\n";
    cout << s1.averageRecord() << "\n";

    s3 = s1.recordsWithinRange(50, 85);
    s3.printListHead();

    cout << s3.averageRecord() << "\n";

}