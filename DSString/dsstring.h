#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <cstring>

class DSString
{
    public:
        // default constructor
        DSString();
        // constructor - parameters: const char* cString
        DSString(const char* data);
        // constructor - parameters: const DSString cString
        DSString(const DSString& data);

        // default destructor
        ~DSString();

        DSString& operator = (const char* other);
        DSString& operator = (const DSString& other);
        DSString& operator + (const DSString& other);
        DSString& operator += (const DSString& other);

        bool operator == (const char* other);
        bool operator == (const DSString& other);
        bool operator < (const char* other);
        bool operator < (const DSString& other);

        char& operator [] (const int index);

        int size();

        // returns a smaller DSString from the original
        // parameters:
            // int startingIndex - first element of the sub-string
            // int numElements - number of elements the sub-string contains
        DSString substring(int startingIndex, int numElements);

        // c_str returns a c-string  representation of the DSString obj
        char* c_str();

        // grants private access to ostream operator function for <<
        friend std::ostream& operator << (std::ostream&, const DSString&);

    private:
        char* data;

};

#endif // DSSTRING_H
