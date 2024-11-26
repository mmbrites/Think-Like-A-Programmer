#include <iostream>

int main() {

    char * test = new char[4];
    test[0] = 'c';
    test[1] = 'd';
    test[2] = 'e';
    test[3] = 0;

    char * test2 = new char[3];
    int length = 0;
    for (int i = 0; test[i] != 0; i++) {
        length++;
    }
    std::cout << length << "\n";

    for (int i = 0; i < 4; i++)
        test2[i] = test[i];

    length = 0;
    for (int i = 0; test2[i] != 0; i++) {
        length++;
        std::cout << length << "\n";
    }

}