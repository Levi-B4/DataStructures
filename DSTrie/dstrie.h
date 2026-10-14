#ifndef DSTRIE_H
#define DSTRIE_H

#include "../DSString/dsstring.h"
#include "../DSVector/dsvector.h"

class DSTrie{
    private:
        class Node{
            public:
                char data = '\0';
                bool isWord = false;
                DSVector<Node*> children;

                /**
                 * @brief Node - default constructor
                 */
                Node();

                /**
                 * @brief Node - copy constructor
                 * @param other - node to copy
                 */
                Node(const Node& other);

                /**
                 * @brief Node - constructor instantiating data
                 * @param data - character to set node equal to
                 */
                Node(char data);

                /**
                 * @brief getChild - retrieves the child with the given character
                 * @param data - character to check children for
                 * @return pointer to the matching child node, or a nullptr
                 */
                Node* getChild(char data);

                
                Node& operator=(const Node& other);


                bool operator==(const Node& other) const;

                bool operator!=(const Node& other) const;

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
         * @brief DSTrie - copy constructor
         * @param other - trie to copy
         */
        DSTrie(const DSTrie& other);

        /**
         * @brief DSTrie - constructor from a vector of strings
         * @param data - vector of strings to turn into a trie
         */
        DSTrie(const DSVector<DSString>& data);

        /**
         * @brief addString - Adds a string to the trie
         * @param str - string to add
         */
        void addString(const DSString str);

        /**
         * @brief addStrings - Adds each string in the given string vector to the trie
         * @param strs - vector of strings to add
         */
        void addStrings(const DSVector<DSString> strs);

        /**
         * @brief removeString - removes a string from the trie
         * @param str - string to remove
         */
        void removeString(const DSString str);


        /**
         * @brief removestrings - removes each string in the given vector from the trie
         * @param strs - vector of strings
         */
        void removestrings(const DSVector<DSString> strs);

        /**
         * @brief clear - removes all data from the trie
         */
        void clear();

        /**
         * @brief getAll - returns all strings in the trie
         * @return - a vector containing all the strings in the trie
         */
        DSVector<DSString> getAll() const;

        /**
         * @brief has - checks if the trie has the given string
         * @param str - string to check for
         * @return true if the trie contains the string, requires the last character Node to have isWord == true
         */
        bool has(const DSString word) const;

        /**
         * @brief has - checks if the trie has every string in the given vector
         * @param words - vector of strings to check for
         * @return true if the trie contains EVERY string, requires the last character Node to have isWord == true
         */
        bool has(const DSVector<DSString> words) const;

        /**
         * @brief hasPrefix - Checks if the trie has the given prefix
         * @param prefix - prefix to check for
         * @return true if the trie contains the prefix
         */
        bool hasPrefix(const DSString prefix) const;

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
