#include "StudentCollection.hpp"

int main() {

    studentCollection s1;
    studentCollection s2;
    studentCollection s3;
    studentRecord r1(85, 99837, "John");
    s2.addRecord(r1);
    studentRecord r2(77, 4765, "Elsie");
    s2.addRecord(r2);
    s1 = s3 = s2;

    s2.printListHead();
    s2.removeRecord(4765);
    s2.printListHead();

}