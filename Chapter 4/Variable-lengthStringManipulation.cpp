#include<iostream>

using std::cout;

typedef char * arrayString;

char characterAt(arrayString s, int position) {
    return s[position];
}

int length(arrayString s) {

    int count = 0;
    while (s[count] != 0)
        count++;
    return count;

}

void append(arrayString& s, char c) {

    int oldLength = length(s);

    arrayString newS = new char[oldLength + 1];
    for (int i = 0; i < oldLength; i++)
        newS[i] = s[i];

    newS[oldLength] = c;
    newS[oldLength + 1] = 0;
    delete[] s;
    s = newS;

}

void appendTester() {

    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    append(a, '!');
    cout << a << "\n"; // This only works because the array is using the null-character termination expected by the standard libraries

    arrayString b = new char[1];
    b[0] = 0;
    append(b, '!');
    cout << b << "\n";

    delete[] a;
    delete[] b;

    a = NULL;
    b = NULL;

}

void concatenate(arrayString& s1, arrayString s2) {

    int s1_OldLength = length(s1);
    int s2_Length = length(s2);
    int s1_NewLength = s1_OldLength + s2_Length;
    arrayString newS = new char[s1_NewLength + 1];
    
    for (int i = 0; i < s1_OldLength; i++)
        newS[i] = s1[i];

    for (int i = 0; i < s2_Length; i++)
        newS[s1_OldLength + i] = s2[i];

    newS[s1_NewLength] = 0;
    delete[] s1;
    s1 = newS;

}

void concatenateTester() {

    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    arrayString b = new char[4];
    b[0] = 'b'; b[1] = 'e'; b[2] = 'd'; b[3] = 0;
    concatenate(a, b);
    cout << a << "\n";

    arrayString c = new char[5];
    c[0] = 't'; c[1] = 'e'; c[2] = 's'; c[3] = 't'; c[4] = 0;
    arrayString d = new char[1];
    d[0] = 0;
    concatenate(d, c);
    cout << c << "\n" << d << "\n";
    cout << (void *) c << "\n" << (void *) d << "\n";

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
    
    appendTester();
    concatenateTester();

}