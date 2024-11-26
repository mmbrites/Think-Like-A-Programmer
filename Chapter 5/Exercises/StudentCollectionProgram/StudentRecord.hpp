#include<string>

class studentRecord {

    public:
        
        // CONSTRUCTORS
        studentRecord();
        studentRecord(int newGrade, int newID, std::string newName);
        
        // GETTERS AND SETTERS
        int grade();
        void setGrade(int newGrade);

        int studentID();
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