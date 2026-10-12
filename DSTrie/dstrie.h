#ifndef DSTRIE_H
#define DSTRIE_H

#include "../DSString/dsstring.h"
#include "../DSVector/dsvector.h"

class DSTrie{
    private:
        class Node{
            public:
                /**
                 * @brief Node - default constructor
                 */
                Node();
                char data = '\0';
                bool isWord = false;
                DSVector<Node> children;

                /**
                 * @brief ~Node - default destructor
                 */
                ~Node();
        };

        Node* root = nullptr;

    public:
        /**
         * @brief DSTrie - default constructor
         */
        DSTrie();

        /**
         * @brief addString - Adds a string to the trie
         * @param str - string to add
         */
        void addString(DSString str);

        /**
         * @brief addStrings - Adds each string in the given string vector to the trie
         * @param strs - vector of strings to add
         */
        void addStrings(DSVector<DSString> strs);

        /**
         * @brief removeString - removes a string from the trie
         * @param str - string to remove
         */
        void removeString(DSString str);


        /**
         * @brief removestrings - removes each string in the given vector from the trie
         * @param strs - vector of strings
         */
        void removestrings(DSVector<DSString> strs);

        /**
         * @brief clear - removes all data from the trie
         */
        void clear();

        /**
         * @brief getAll - returns all strings in the trie
         * @return - a vector containing all the strings in the trie
         */
        DSVector<DSString> getAll();

        /**
         * @brief has - checks if the trie has the given string
         * @param str - string to check for
         * @return true if the trie contains the string, requires the last character Node to have isWord == true
         */
        bool has(DSString word);

        /**
         * @brief has - checks if the trie has every string in the given vector
         * @param words - vector of strings to check for
         * @return true if the trie contains EVERY string, requires the last character Node to have isWord == true
         */
        bool has(DSVector<DSString> words);

        /**
         * @brief hasPrefix - Checks if the trie has the given prefix
         * @param prefix - prefix to check for
         * @return true if the trie contains the prefix
         */
        bool hasPrefix(DSString prefix);

        /**
         * @brief operator = : sets this trie equal to the trie given
         * @param other - reference to trie to copy
         * @return reference to this trie
         */
        DSTrie& operator=(const DSTrie& other);

        /**
         * @brief operator = : creates this trie from the given vector of strings
         * @param other - reference to vector of strings to create trie from
         * @return reference to this trie
         */
        DSTrie& operator=(const DSVector<DSString>& other);

        /**
         * @brief operator += : adds every string in the given trie to the current trie and sets this to the sum
         * @param other - reference to the trie to add from
         * @return reference to this trie
         */
        DSTrie& operator+=(const DSTrie& other);

        /**
         * @brief operator += : adds every string in the given trie to the current trie and sets this to the sum
         * @param other - reference to the vector of strings to add from
         * @return referenece to this trie
         */
        DSTrie& operator+=(const DSVector<DSString>& other);

        /**
         * @brief operator + : adds every string in the given trie to the current trie
         * @param other - reference to the trie to add from
         * @return the sum of the given trie and this trie
         */
        DSTrie operator+(const DSTrie& other) const;

        /**
         * @brief operator + : adds every string in the given trie to the current trie
         * @param other - reference to the vector of strings to add from
         * @return  the sum of the given vector of strings and this trie
         */
        DSTrie operator+(const DSVector<DSString>& other) const;

        /**
         * @brief operator == : compares this trie and the given trie
         * @param other - reference to the trie to compare to
         * @return true if both tries are equal
         */
        bool operator==(const DSTrie& other) const;

        /**
         * @brief operator != : compares this trie and the given trie
         * @param other - reference to the trie to compare to
         * @return false if both ries are equal
         */
        bool operator!=(const DSTrie& other) const;


        /**
         * @brief ~DSTrie() - default destructor
         */
        ~DSTrie();
};

#endif // DSTRIE_H
