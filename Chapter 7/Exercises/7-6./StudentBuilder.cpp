#include<string>

#include "StudentBuilder.hpp"

StudentBuilder::StudentBuilder() { }

void StudentBuilder::reset() {
    _student.clean();
}

StudentBuilder & StudentBuilder::setGrade(int grade) {
    _student.setGrade(grade);
    return *this;
}

StudentBuilder & StudentBuilder::setStudentID(int studentID) {
    _student.setStudentID(studentID);
    return *this;
}

StudentBuilder & StudentBuilder::setName(std::string name) {
    _student.setName(name);
    return *this;
}

StudentBuilder & StudentBuilder::setTermPaperTitle(std::string termPaperTitle) {
    _student.setTermPaperTitle(termPaperTitle);
    return *this;
}

StudentBuilder & StudentBuilder::setEnrollmentYear(int enrollmentYear) {
    _student.setEnrollmentYear(enrollmentYear);
    return *this;
}

StudentBuilder & StudentBuilder::setAuditingClass(std::optional<bool> auditingClass) {
    _student.setAuditingClass(auditingClass);
    return *this;
}

studentRecord StudentBuilder::student() {
    studentRecord record(_student);
    // reset();
    return record;
}