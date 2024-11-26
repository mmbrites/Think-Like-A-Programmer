#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm> // for std::sort

using std::cout;
using std::vector;

#include "studentCollection.hpp"
#include "scIterator.hpp"

bool higherGrade(studentRecord r1, studentRecord r2) {
    return r1.grade() > r2.grade();
}

bool lowerStudentNumber(studentRecord r1, studentRecord r2) {
    return r1.studentID() < r2.studentID();
}

bool nameComesFirst(studentRecord r1, studentRecord r2) {
    return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
}

// Sorting Some, Leaving Others Alone

// Using customised 'insertion sort'
void ignoreNegativeGrades(studentRecord sra[], int arraySize) {

    int start = 0;
    int end = arraySize - 1;    

    for (int i = start + 1; i <= end; i++) {

        if (sra[i].grade() != -1) {

            int rightswap = i;

            // The added condition 'sra[leftswap].grade() == -1' is needed to advance the loop in case there is a '-1' in the current iteration. Otherwise, loops would end early
            for (int leftswap = i - 1; leftswap >= start && (sra[leftswap].grade() > sra[rightswap].grade() || sra[leftswap].grade() == -1); leftswap--) {

                if (sra[leftswap].grade() != -1) {

                    studentRecord temporary = sra[leftswap];
                    sra[leftswap] = sra[rightswap];
                    sra[rightswap] = temporary;
                    rightswap = leftswap;

                }

            }

        }

    }

}

bool compareStudentRecord(const studentRecord & recordA, const studentRecord & recordB) {
    return recordA.grade() < recordB.grade();
}

void ignoreNegativeGradesQSort(vector<studentRecord> & sra, int arraySize) {

    vector<studentRecord> sortArray;
    sortArray.reserve(arraySize);
    
    for (int i = 0; i < arraySize; i++)
        if (sra.at(i).grade() != -1)
            sortArray.push_back(sra.at(i));

    std::sort(sortArray.begin(), sortArray.end(), compareStudentRecord);
    int sortArrayCount = 0;

    for (int i = 0; i < arraySize; i++) {

        if (sra.at(i).grade() != -1) {
            sra[i] = sortArray[sortArrayCount];
            sortArrayCount++;
        }

    }

}

int main() {

    studentRecord r1(85, 99837, "John");
    studentRecord r2(77, 4765, "Elsie");
    studentRecord r3(-1, 5032, "Miguel");

    /*
    
    studentCollection s1;
    studentCollection s2;
    studentCollection s3;
    s2.addRecord(r1);
    s2.addRecord(r3);
    s2.addRecord(r2);
    s1 = s3 = s2;

    s2.setFirstStudentPolicy(lowerStudentNumber);
    cout << s2.firstStudent().studentID() << "\n";
    s2.setFirstStudentPolicy(higherGrade);
    cout << s2.firstStudent().grade() << "\n";
    s2.setFirstStudentPolicy(nameComesFirst);
    cout << s2.firstStudent().name() << "\n";

    scIterator iterator;
    int gradeTotal = 0;
    int numRecords = 0;
    iterator = s2.firstItemIterator();
    while (!iterator.pastEnd()) {
        numRecords++;
        gradeTotal += iterator.student().grade();
        iterator.advance();
    }

    double average = (double) gradeTotal / numRecords;
    cout << "Average: " << average << "\n";

    */


    const int arraySize = 3;
    vector<studentRecord> sra = {r1, r3, r2};

    for(vector<studentRecord>::iterator it = sra.begin(); it != sra.end(); ++it)
        cout << (*it).grade() << "\n";

    ignoreNegativeGradesQSort(sra, arraySize);

    cout << "\n";

    for(vector<studentRecord>::iterator it = sra.begin(); it != sra.end(); ++it)
        cout << (*it).grade() << "\n";

}