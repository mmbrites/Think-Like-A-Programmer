// USED FOR TESTING IN EXERCISES 5-1./5-2.

#include <iostream>

using std::cout;

#include "Automobile.hpp"

int main() {

    Automobile a;
    Automobile b("Chevrolet", "Impala", 1957);
    cout << a.getAutomobileDescription() << "\n";
    cout << b.getAutomobileDescription() << "\n";
    cout << b.getAutomobileAge() << "\n";

}