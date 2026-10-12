#include "dstrie.h"

/**
 * @brief DSTrie::Node::Node - default constructor
 */
DSTrie::Node::Node(){

}

/**
 * @brief DSTrie::Node::~Node - default destructor
 */
DSTrie::Node::~Node(){

}

/**
 * @brief DSTrie::DSTrie - default constructor
 */
DSTrie::DSTrie()
{

}

/**
 * @brief DSTrie::addString -
 * @param str - string to add
 */
void DSTrie::addString(DSString str)
{

}

/**
 * @brief DSTrie::addStrings
 * @param strs - vector of strings to add
 */
void DSTrie::addStrings(DSVector<DSString> strs)
{

}

/**
 * @brief DSTrie::removeString
 * @param str - string to remove
 */
void DSTrie::removeString(DSString str)
{

}

/**
 * @brief DSTrie::removestrings
 * @param strs - vector of strings to remove
 */
void DSTrie::removestrings(DSVector<DSString> strs)
{

}

/**
 * @brief DSTrie::clear
 */
void DSTrie::clear()
{

}

/**
 * @brief DSTrie::getAll
 * @return a vector containing all strings in the trie
 */
DSVector<DSString> DSTrie::getAll()
{
    return DSVector<DSString>();
}

/**
 * @brief DSTrie::has
 * @param word - string to check for
 * @return true if the trie contains that string, requires the last character Node to have isWord == true
 */
bool DSTrie::has(DSString word)
{
    return false;
}

/**
 * @brief DSTrie::has
 * @param words - vector of strings to check for
 * @return true if the trie contains EVERY string, requires the last character Node to have isWord == true
 */
bool DSTrie::has(DSVector<DSString> words)
{
    return false;
}

/**
 * @brief DSTrie::hasPrefix
 * @param prefix - prefix to check for
 * @return true if the trie contains the prefix
 */
bool DSTrie::hasPrefix(DSString prefix)
{
    return false;
}

/**
 * @brief operator = : sets this trie equal to the trie given
 * @param other - reference to trie to copy
 * @return reference to this trie
 */
DSTrie& DSTrie::operator=(const DSTrie& other){
    return *this;
}

/**
 * @brief operator = : creates this trie from the given vector of strings
 * @param other - reference to vector of strings to create trie from
 * @return reference to this trie
 */
DSTrie& DSTrie::operator=(const DSVector<DSString>& other){
    return *this;
}

/**
 * @brief operator +=
 * @param other - reference to the trie to add from
 * @return reference to this trie
 */
DSTrie& DSTrie::operator+=(const DSTrie& other){
    return *this;
}

/**
 * @brief operator +=
 * @param other - reference to the vector of strings to add from
 * @return referenece to this trie
 */
DSTrie& DSTrie::operator+=(const DSVector<DSString>& other){
    return *this;
}

/**
 * @brief operator + : adds every string in the given trie to the current trie
 * @param other - reference to the trie to add from
 * @return the sum of the given trie and this trie
 */
DSTrie DSTrie::operator+(const DSTrie& other) const{
    return DSTrie();
}

/**
 * @brief operator + : adds every string in the given trie to the current trie
 * @param other - reference to the vector of strings to add from
 * @return  the sum of the given vector of strings and this trie
 */
DSTrie DSTrie::operator+(const DSVector<DSString>& other) const{
    return DSTrie();
}

/**
 * @brief operator == : compares this trie and the given trie
 * @param other - reference to the trie to compare to
 * @return true if both tries are equal
 */
bool DSTrie::operator==(const DSTrie& other) const{
    return false;
}

/**
 * @brief operator != : compares this trie and the given trie
 * @param other - reference to the trie to compare to
 * @return false if both ries are equal
 */
bool DSTrie::operator!=(const DSTrie& other) const{
    return false;
}

/**
 * @brief ~DSTrie() - default destructor
 */
DSTrie::~DSTrie(){
    if(root != nullptr){
        delete root;
    }
}
