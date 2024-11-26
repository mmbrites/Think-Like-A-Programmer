#include<iostream>

using std::cout;

typedef char * arrayString;

// PREREQUISITES: s != NULL
int length(arrayString s) {
    return s[0];
}

void printArrayString(arrayString s) {

    for (int i = 1; i < length(s); i++)
        cout << s[i];

    cout << "\n";

}

// PREREQUISITES: s != NULL && position >= 1 && position < length(s)
char characterAt(arrayString s, int position) {
    return s[position];
}

void characterAtTester() {

    arrayString a = new char[5];
    a[0] = 5; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    char character = characterAt(a, 4);
    cout << character << "\n";

}

void append(arrayString& s, char c) {

    int oldLength = length(s);

    arrayString newS = new char[oldLength + 1];
    newS[0] = oldLength + 1;
    for (int i = 1; i < oldLength; i++)
        newS[i] = s[i];

    newS[oldLength] = c;
    newS[oldLength + 1] = 0;
    delete[] s;
    s = newS;

}

void appendTester() {

    arrayString a = new char[5];
    a[0] = 5; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    append(a, '!');
    printArrayString(a);

    arrayString b = new char[1];
    b[0] = 1; 
    append(b, '!');
    printArrayString(b);

    cout << length(a) << "\n";
    cout << length(b) << "\n";

    delete[] a;
    delete[] b;

    a = NULL;
    b = NULL;

}

// PREREQUISITES = s1 != NULL && s2 != NULL
void concatenate(arrayString& s1, arrayString s2) {

    int s1_OldLength = length(s1);
    int s2_Length = length(s2);
    int s1_NewLength = s1_OldLength + s2_Length;
    arrayString newS = new char[s1_NewLength - 1];
    
    newS[0] = s1_NewLength - 1;
    for (int i = 1; i < s1_OldLength; i++)
        newS[i] = s1[i];

    for (int i = 0; i < s2_Length - 1; i++)
        newS[s1_OldLength + i] = s2[i + 1];

    newS[s1_NewLength] = 0;
    delete[] s1;
    s1 = newS;

}

void concatenateTester() {

    arrayString a = new char[5];
    a[0] = 5; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    arrayString b = new char[4];
    b[0] = 4; b[1] = 'b'; b[2] = 'e'; b[3] = 'd';
    concatenate(a, b);
    printArrayString(a);
    cout << length(a) << "\n";

    arrayString c = new char[5];
    c[0] = 5; c[1] = 't'; c[2] = 'e'; c[3] = 's'; c[4] = 't';
    arrayString d = new char[1];
    d[0] = 1;
    concatenate(d, c);
    printArrayString(c);
    printArrayString(d);
    cout << (void *) c << "\n" << (void *) d << "\n";
    cout << length(d) << "\n";

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;

    a = NULL;
    b = NULL;
    c = NULL;
    d = NULL;

}

int main() {

    characterAtTester();
    appendTester();
    concatenateTester();

}