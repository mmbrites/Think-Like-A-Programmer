#pragma once

#include<string>
#include <optional>

#include "StudentRecord.hpp"

class StudentBuilder {

    public:
        StudentBuilder();
        void reset();

        // Setters
        StudentBuilder & setGrade(int grade);
        StudentBuilder & setStudentID(int studentID);
        StudentBuilder & setName(std::string name);
        StudentBuilder & setTermPaperTitle(std::string termPaperTitle);
        StudentBuilder & setEnrollmentYear(int enrollmentYear);
        StudentBuilder & setAuditingClass(std::optional<bool> auditingClass);

        // Getter
        studentRecord student(); 

    private:
        studentRecord _student;

};