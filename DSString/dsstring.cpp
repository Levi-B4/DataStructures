#include "dsstring.h"


// default constructor
DSString::DSString() {
    // instantiate empty char array
    data = new char[1];
    data[0] = '\0';
    // TODO: check if need to instantiate with '\0'
}

// constructor - parameters: const char* data
DSString::DSString(const char* data){
    // instantiate char array with size of input data
    this->data = new char[strlen(data) + 1];

    // copy char array memory from input data to object data
    std::memcpy(this->data, data, strlen(data) + 1);
}

// constructor - parameters: const DSString data
DSString::DSString(const DSString& data){
    this->data = new char[data.size()];
    std::memcpy(this->data, data.data, data.size() + 1);
}

// default destructor
DSString::~DSString(){
    // delete data char array
    delete[] data;
}


// instantiation operator - parameter: const char* other
DSString& DSString::operator = (const char* other){
    // delete current data
    delete[] this->data;

    // create char array same size as other array
    data = new char[strlen(other) + 1];

    // copy char array memory from other to data
    std::memcpy(data, other, strlen(other) + 1);

    return *this;
}

// instantiation operator - parameter: const DDString& other
DSString& DSString::operator = (const DSString& other){
    // delete current data
    delete[] this->data;

    // create char array same size as other array
    this->data = new char[other.size()+1];

    // copy data from other DSString to this object's data
    std::memcpy(this->data, other.data, other.size() + 1);

    return *this;
}

// concatination operator: +
DSString& DSString::operator + (const DSString& other){
    // create char array the size of both strings plus a terminating char
    char* temp = new char[size() + other.size() + 1];

    // copy data from data to temp char array
    std::strcpy(temp, data);

    // concatinate the temporary array and the other array
    std::strcat(temp, other.data);

    // delete data
    delete[] data;

    // set data pointing to temp
    data = temp;

    // return this object
    return *this;
}

// concatination operator: +=
DSString& DSString::operator += (const DSString& other){
    // create char array the size of both strings plus a terminating char
    char* temp = new char[size() + other.size() + 1];

    // copy data from data to temp char array
    std::strcpy(temp, data);

    // concatinate the temporary array and the other array
    std::strcat(temp, other.data);

    // delete data
    delete[] data;

    // set data pointing to temp
    data = temp;

    // return this object
    return *this;
}

// comparison operator: ==
// parameter: const char* other
bool DSString::operator == (const char* other){

    // if this data is the same as other char array return true
    if(strcmp(this->data, other)){
        return true;
    }

    return false;
}

// comparison operator: ==
// parameter: const DDString& other
bool DSString::operator == (const DSString& other){
    // if this data is the same as other data return true
    if(strcmp(this->data, other.data) == 0){
        return true;
    }

    return false;
}

// comparison operator <
// parameter: const char* other
bool DSString::operator < (const char* other){
    if(strcmp(this->data, other) < 0){
        return true;
    }
    return false;
}

// comparison operator <
// parameter: const char* other
bool DSString::operator < (const DSString& other){
    if(strcmp(this->data, other.data) < 0){
        return true;
    }
    return false;
}

// indexing operator []
// parameter: const int
char& DSString::operator[](const int index){
    return data[index];
}

// returns size of data
int DSString::size() const{
    return strlen(data);
}

// returns a smaller DSString from the original
// parameters:
    // int startingIndex - first element of the sub-string
    // int numElements - number of elements the sub-string contains
/*DSString DSString::substring(int startingIndex, int numElements){
    return ;
}*/

// c_str returns a c-string representation of the DSString obj
char* DSString::c_str(){
    return data;
}
