// EXERCISE 5-3./5-4./5-5./5-6.

class VariableLengthString {

    private:
        typedef char * arrayString;

    public:
        
        // CONSTRUCTORS, DESTRUCTORS, OVERLOADS
        VariableLengthString();
        VariableLengthString(char * s, int length);
        VariableLengthString(const VariableLengthString & vls);
        VariableLengthString(VariableLengthString && s);
        ~VariableLengthString();
        VariableLengthString & operator=(const VariableLengthString & rhs);
        VariableLengthString & operator=(VariableLengthString && rhs);
        VariableLengthString operator+(const VariableLengthString & rhs);
        char operator[](int position);

        // GETTERS AND SETTERS
        arrayString charArray() const;
        void setCharArray(char * s, int length);

        // OPERATIONS
        char characterAt(int position);
        void append(char c);
        void concatenate(const VariableLengthString s);
        void remove(int start, int stretch);

    private:
        arrayString _charArray;
    
        void swap(VariableLengthString & other);
        int length() const;
        void clean(arrayString & s, int length);

};