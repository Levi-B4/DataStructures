#include "dsstring.h"


// default constructor
DSString::DSString() {}

// constructor - parameters: const char* cString
DSString::DSString(const char* data){

}

// constructor - parameters: const DSString cString
DSString::DSString(const DSString&){

}

// default destructor
DSString::~DSString(){}


// instantiation operator - parameter: const char* other
DSString& DSString::operator = (const char* other){
    return *this;
}

// instantiation operator - parameter: const DDString& other
DSString& DSString::operator = (const DSString& other){
    return *this;
}

// concatination operator: +
DSString& DSString::operator + (const DSString& other){
    return *this;
}

// concatination operator: +=
DSString& DSString::operator += (const DSString& other){
    return *this;
}

// comparison operator: ==
// parameter: const char* other
bool DSString::operator == (const char* other){
    return true;
}

// comparison operator: ==
// parameter: const DDString& other
bool DSString::operator == (const DSString& other){
    return true;
}

// comparison operator <
// parameter: const char* other
bool DSString::operator < (const char* other){
    return true;
}

// comparison operator <
// parameter: const char* other
bool DSString::operator < (const DSString& other){
    return true;
}

// indexing operator []
// parameter: const int
char& DSString::operator[](const int index){
    return data[index];
}

// returns size
int DSString::size(){
    return 0;
}

// returns a smaller DSString from the original
// parameters:
    // int startingIndex - first element of the sub-string
    // int numElements - number of elements the sub-string contains
/*DSString DSString::substring(int startingIndex, int numElements){
    return ;
}*/

// c_str returns a c-string  representation of the DSString obj
char* DSString::c_str(){
    return data;
}
