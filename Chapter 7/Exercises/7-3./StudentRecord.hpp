#ifndef STUDENTRECORD_HPP
#define STUDENTRECORD_HPP

#include<string>

class studentRecord {

    public:
        
        // CONSTRUCTORS
        studentRecord();
        studentRecord(int newGrade, int newID, std::string newName);
        studentRecord(const studentRecord & original);
        studentRecord & operator=(const studentRecord & rhs);
        
        // GETTERS AND SETTERS
        int grade() const;
        void setGrade(int newGrade);

        int studentID() const;
        void setStudentID(int newID);
        
        std::string name();
        void setName(std::string newName);

        // OPERATIONS

        std::string letterGrade();

    private:
        int _grade;
        int _studentID;
        std::string _name;

        // AUXILIARY FUNCTIONS

        bool isValidGrade(int grade);

};

#endif