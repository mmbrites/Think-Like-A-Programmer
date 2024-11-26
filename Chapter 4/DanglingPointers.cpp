#include<iostream>

using std::cout;

int* test(int pnt) {
    return &pnt; // bad idea, but technically you haven't done anything wrong yet
}

void test2() {
    int* p = test(5);
    cout << *p; // accesses a deallocated variable. Bad stuff happens here
}

int main() {
    test2();
}