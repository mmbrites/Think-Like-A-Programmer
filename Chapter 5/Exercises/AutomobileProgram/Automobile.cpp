// EXERCISE 5-1.

#include <iostream>
#include <ctime>

using std::cout;

#include "Automobile.hpp"

// CONSTRUCTORS

Automobile::Automobile() {
    setManufacturerName("");
    setModelName("");
    setModelYear(0);
}

Automobile::Automobile(std::string newManufacturerName, std::string newModelName, int newModelYear) {
    setManufacturerName(newManufacturerName);
    setModelName(newModelName);
    setModelYear(newModelYear);
}

// GETTERS AND SETTERS

std::string Automobile::manufacturerName() {
    return _manufacturerName;
}

void Automobile::setManufacturerName(std::string newName) {
    _manufacturerName = newName;
}

std::string Automobile::modelName() {
    return _modelName;
}

void Automobile::setModelName(std::string newName) {
    _modelName = newName;
}

int Automobile::modelYear() {
    return _modelYear;
}

void Automobile::setModelYear(int newYear) {

    if (newYear >= 0)
        _modelYear = newYear;
    else
        std::cout << "Invalid model year. Set request was rejected!";

}

// OPERATIONS

// EXERCISE 5-2.
std::string Automobile::getAutomobileDescription() {
    return std::to_string(modelYear()) + " " + manufacturerName() + " " + modelName();
}

// EXERCISE 5-2
int Automobile::getAutomobileAge() {

    std::time_t t = std::time(nullptr); // Get time_t
    std::tm *const timeInfo = std::localtime(&t); // Get a struct with time information
    int currentYear = _countingYearsSince + timeInfo->tm_year; // 'tm_year' stores the amount of years passed since 1900
    return currentYear - modelYear();

}