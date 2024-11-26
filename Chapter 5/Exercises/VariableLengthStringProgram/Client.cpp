#include <iostream>

#include "VariableLengthString.hpp"

using std::cout;

int main() {

    char * a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    VariableLengthString s1(a, 5);

    cout << "s1: " << s1.charArray() << "\n";
    
    VariableLengthString s2;
    s2 = s1;

    cout << "s2: " << s2.charArray() << "\n";
    s2.append('!');
    cout << "s2: " << s2.charArray() << "\n";
    VariableLengthString s3;
    s3 = s2 + s1;
    cout << "s2: " << s2.charArray() << "\n";

    cout << "s1: " << s1.charArray() << "\n";

    cout << "s3: " << s3.charArray() << "\n";

    s3.remove(4, 2);

    cout << "s3: " << s3.charArray() << "\n";

}