#include <iostream>
using std::cout;

// IMPORTANT: You cannot and must not use qsort on an array of std::strings. The elements must be of trivial type, which strings are not, and thus the behaviour is undefined.

struct student {
        int grade;
        int studentID;
        std::string name;
};

const int ARRAY_SIZE = 10;

int compareFunc(const void* voidA, const void* voidB) {

    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);

    return *intA - *intB;

}

void fromStructToArray(int* array, student* studentArray, int flag) {

    if (flag)
        for (int i = 0; i < ARRAY_SIZE; i++)
            array[i] = studentArray[i].grade;
    else 
        for (int i = 0; i < ARRAY_SIZE; i++)
            array[i] = studentArray[i].studentID;

}

int main() {

    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}
    };

    int *sortedArray = new int[ARRAY_SIZE];
    fromStructToArray(sortedArray, studentArray, 1);

    qsort(sortedArray, ARRAY_SIZE, sizeof(int), compareFunc);

    cout << "Sorted by Grade:\n";

    for (int i = 0; i < ARRAY_SIZE; i++)
        cout << sortedArray[i] << "\n";

    fromStructToArray(sortedArray, studentArray, 0);
    qsort(sortedArray, ARRAY_SIZE, sizeof(int), compareFunc);

    cout << "Sorted by StudentID:\n";

    for (int i = 0; i < ARRAY_SIZE; i++)
        cout << sortedArray[i] << "\n";

    delete[] sortedArray;

}