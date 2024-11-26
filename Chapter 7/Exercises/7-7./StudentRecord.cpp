#include "StudentRecord.hpp"

studentRecord::studentRecord()  {
    setGrade(0);
    setStudentID(-1);
    setName("");
}

studentRecord::studentRecord(int newGrade, int newID, std::string newName) {
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

// COPY CONSTRUCTOR
studentRecord::studentRecord(const studentRecord & original) {

    setGrade(original._grade);
    setStudentID(original._studentID);
    setName(original._name);
    setFields(original._fields);

}

// COPY ASSIGNMENT
studentRecord & studentRecord::operator=(const studentRecord & rhs) {

    if (this != &rhs) {

        setGrade(rhs._grade);
        setStudentID(rhs._studentID);
        setName(rhs._name);
        setFields(rhs._fields);

    }
    
    return *this;

}

bool studentRecord::isValidGrade(int grade) {

    if((grade >= 0) && (grade <= 100)) // Accepting the '-1' value to conform with the problem in page 190
        return true;
    else
        return false;

}

int studentRecord::grade() const { 
    return _grade; 
}

void studentRecord::setGrade(int newGrade) {

    if (isValidGrade(newGrade))
        _grade = newGrade;

}

int studentRecord::studentID() const {
    return _studentID;
}

void studentRecord::setStudentID(int newID) {
    _studentID = newID;
}

std::string studentRecord::name() {
    return _name;
}

void studentRecord::setName(std::string newName) {
    _name = newName;
}

std::string studentRecord::letterGrade() {

    if (isValidGrade(_grade))
        return "ERROR";

    const int NUMBER_CATEGORIES = 11;
    const std::string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};

    int category = 0;
    while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
        category++;

    return GRADE_LETTER[category - 1];

}

void studentRecord::addExtraField(std::string fieldName, std::variant<int, std::string> fieldValue) {
    _fields.insert({fieldName, fieldValue});
}

std::variant<int, std::string> studentRecord::retrieveField(std::string fieldName) {
    return _fields[fieldName];
}

int studentRecord::addedFields() {
    return _fields.size();
}

void studentRecord::setFields(std::unordered_map<std::string, std::variant<int, std::string>> fields) {
    _fields = fields;
}