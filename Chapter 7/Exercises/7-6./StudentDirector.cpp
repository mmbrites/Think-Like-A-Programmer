#include "StudentDirector.hpp"

StudentDirector::StudentDirector() { }

void StudentDirector::buildCompleteStudent(StudentBuilder & builder) {
    builder.setStudentID(1).setGrade(98).setName("Luís").setTermPaperTitle("Researching Fish").setEnrollmentYear(2018).setAuditingClass(false);
}

void StudentDirector::buildIncompleteStudent(StudentBuilder & builder) {
    builder.setStudentID(2).setGrade(75).setName("Bárbara").setEnrollmentYear(2019);
}