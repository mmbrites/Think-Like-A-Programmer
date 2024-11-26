#include <string>
#include <list>

using std::string;
using std::list;

class WordDirectory {

    public:
        WordDirectory();

        // GETTER & SETTER

        list<string> wordList();
        void setWordList(list<string> wList);

        // OPERATIONS

        void fillWordList();
        void displayWordList();
        int countWordsWithoutLetter(char letter); // Counts the amount of words without the specified letter
        int countWordsWithMostFrequentPattern(list<int> & pattern, char letter); // Counts the amount of words that comply with the most frequent pattern - Additionaly, 'pattern' stores the most frequent pattern
        void removeWords(int length); // Removes words that are not of the specified length
        void removeWordsWithLetter(char letter); // Removes words with the specified letter
        void removeWordsWithoutLetter(char letter); // Removes words without the specified letter
        void removeWords(list<int> pattern, char letter); // Removes words that do not conform to the specified pattern

    private:
        const string WORD_FILE = "wordList.txt";
        list<string> _wordList;

        // AUXILIAR OPERATIONS
        bool containsLetter(string s, char letter); // Verifies whether 's' contains at least one instance of 'letter'
        bool containsPattern(string s, list<int> pattern, char letter); // Verifies whether 's' conforms to the specified pattern
        list<int> createPattern(string s, char letter); // Creates a list that contains the positions in 's' where 'letter' occurs
        bool positionInPattern(int position, list<int> pattern); // Verifies whether a specified position is in the pattern
        void privateRemoveWordWithoutLetter(list<string> & cloneList, char letter); // Removes words without the specified letter out of a cloned list

};