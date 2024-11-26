#ifndef STUDENTRECORD_HPP
#define STUDENTRECORD_HPP

#include<string>
#include <optional>

class studentRecord {

    public:
        
        // CONSTRUCTORS
        studentRecord();
        studentRecord(int newGrade, int newID, std::string newName, std::string termPaperTitle, int enrollmentYear, std::optional<bool> auditingClass);
        studentRecord(const studentRecord & original);
        studentRecord & operator=(const studentRecord & rhs);
        
        // GETTERS AND SETTERS
        int grade() const;
        void setGrade(int newGrade);

        int studentID() const;
        void setStudentID(int newID);
        
        std::string name();
        void setName(std::string newName);

        std::string termPaperTitle();
        void setTermPaperTitle(std::string termPaperTitle);

        int enrollmentYear();
        void setEnrollmentYear(int enrollmentYear);

        std::optional<bool> auditingClass();
        void setAuditingClass(std::optional<bool> auditingClass);

        // OPERATIONS

        std::string letterGrade();
        void clean();

    private:
        int _grade;
        int _studentID;
        std::string _name;
        std::string _termPaperTitle;
        int _enrollmentYear;
        std::optional<bool> _auditingClass;

        // AUXILIARY FUNCTIONS

        bool isValidGrade(int grade);

};

#endif