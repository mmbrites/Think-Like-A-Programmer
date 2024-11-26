#include <iostream>
#include <string.h>
#include <vector>

using std::cout;
using std::vector;

#include "studentCollection.hpp"
#include "StudentBuilder.hpp"
#include "StudentDirector.hpp"

int main() {

    // Procedure with no 'Director' class
    StudentBuilder builder;
    builder.setName("Maria").setGrade(80).setStudentID(10).setAuditingClass(true).setAuditingClass(true);
    studentRecord r1 = builder.student();
    
    cout << r1.name() << "\n";
    cout << r1.grade() << "\n";
    cout << r1.studentID() << "\n";
    cout << r1.auditingClass().value() << "\n";

    // Procedure with 'Director' class
    StudentDirector director;
    director.buildCompleteStudent(builder);
    studentRecord r2 = builder.student();

    cout << r2.name() << " ";
    cout << r2.grade() << " ";
    cout << r2.studentID() << " ";
    cout << r2.termPaperTitle() << " ";
    cout << r2.enrollmentYear() << " ";
    cout << r2.auditingClass().value() << "\n";

    director.buildIncompleteStudent(builder);
    studentRecord r3 = builder.student();

    cout << r3.name() << " ";
    cout << r3.grade() << " ";
    cout << r3.studentID() << " ";
    cout << r3.termPaperTitle() << " ";
    cout << r3.enrollmentYear() << " ";
    if (r3.auditingClass().has_value())
        cout << r3.auditingClass().value() << "\n";

}