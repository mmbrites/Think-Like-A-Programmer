#ifndef STUDENTRECORD_HPP
#define STUDENTRECORD_HPP

#include <string>
#include <unordered_map>
#include <variant>

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

        void addExtraField(std::string fieldName, std::variant<int, std::string> fieldValue);
        std::variant<int, std::string> retrieveField(std::string fieldName);

        int addedFields();

    private:
        int _grade;
        int _studentID;
        std::string _name;

        std::unordered_map<std::string, std::variant<int, std::string>> _fields;

        // AUXILIARY FUNCTIONS

        bool isValidGrade(int grade);

        // SETTERS

        void setFields(std::unordered_map<std::string, std::variant<int, std::string>> fields);

};

#endif