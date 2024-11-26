// EXERCISE 5-1.

#include<string>

class Automobile {

    public:
        
        // CONSTRUCTORS
        Automobile();
        Automobile(std::string newManufacturerName, std::string newModelName, int newModelYear);
        
        // GETTERS AND SETTERS
        std::string manufacturerName();
        void setManufacturerName(std::string newName);

        std::string modelName();
        void setModelName(std::string newName);

        int modelYear();
        void setModelYear(int newYear);

        // OPERATIONS

        std::string getAutomobileDescription();
        int getAutomobileAge();

    private:
        std::string _manufacturerName;
        std::string _modelName;
        int _modelYear;
        const int _countingYearsSince = 1900;

};