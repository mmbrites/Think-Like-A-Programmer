#include "StudentBuilder.hpp"

// This class is optional and its only purpose is to hide the details regarding builder's methods :)
class StudentDirector {

    public:
        StudentDirector();
        void buildCompleteStudent(StudentBuilder & builder);
        void buildIncompleteStudent(StudentBuilder & builder);

};