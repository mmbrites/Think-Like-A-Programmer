#include <optional>
#include <iostream>

using std::cout;

#include "StudentRecord.hpp"

studentRecord::studentRecord()  {
    clean();
}

studentRecord::studentRecord(int newGrade, int newID, std::string newName, std::string termPaperTitle, int enrollmentYear, std::optional<bool> auditingClass) {

    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
    setTermPaperTitle(termPaperTitle);
    setEnrollmentYear(enrollmentYear);
    setAuditingClass(auditingClass);

}

// COPY CONSTRUCTOR
studentRecord::studentRecord(const studentRecord & original) {

    setGrade(original._grade);
    setStudentID(original._studentID);
    setName(original._name);
    setTermPaperTitle(original._termPaperTitle);
    setEnrollmentYear(original._enrollmentYear);
    setAuditingClass(original._auditingClass);

}

// COPY ASSIGNMENT
studentRecord & studentRecord::operator=(const studentRecord & rhs) {

    if (this != &rhs) {

        setGrade(rhs._grade);
        setStudentID(rhs._studentID);
        setName(rhs._name);
        setTermPaperTitle(rhs._termPaperTitle);
        setEnrollmentYear(rhs._enrollmentYear);
        setAuditingClass(rhs._auditingClass);

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

std::string studentRecord::termPaperTitle() {
    return _termPaperTitle;
}

void studentRecord::setTermPaperTitle(std::string termPaperTitle) {
    _termPaperTitle = termPaperTitle;
}

int studentRecord::enrollmentYear() {
    return _enrollmentYear;
}

void studentRecord::setEnrollmentYear(int enrollmentYear) {
    _enrollmentYear = enrollmentYear;
}

std::optional<bool> studentRecord::auditingClass() {
    return _auditingClass;
}

void studentRecord::setAuditingClass(std::optional<bool> auditingClass) {
    _auditingClass = auditingClass;
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

void studentRecord::clean() {
    setGrade(0);
    setStudentID(-1);
    setName("");
    setTermPaperTitle("");
    setEnrollmentYear(-1);
    setAuditingClass(std::nullopt);
}