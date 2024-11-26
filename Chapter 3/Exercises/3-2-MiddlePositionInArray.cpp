#include <iostream>
using std::cout;


int main() {

    const int ARRAY_SIZE = 11;
    int array[ARRAY_SIZE] = {1, 90, 10, 30, 40, 39, 27, 58, 51, 82, 525};

    int middlePosition = ARRAY_SIZE / 2;
    cout << array[middlePosition] << "\n";

}