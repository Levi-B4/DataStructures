#include "dstrie.h"

/**
 * @brief DSTrie::Node::Node - default constructor
 */
DSTrie::Node::Node(){}

/**
 * @brief DSTrie::Node::Node - copy constructor
 * @param other - node to copy
 */
DSTrie::Node::Node(const Node& other){
    *this = other;
}

/**
 * @brief DSTrie::Node::Node - constructor to instantiate data
 * @param data - character to set the node data to
 */
DSTrie::Node::Node(char data) : data(data){}

/**
 * @brief getChild - retrieves the child with the given character
 * @param data - character to check children for
 * @return pointer to the matching child node, or a nullptr
 */
DSTrie::Node* DSTrie::Node::getChild(char query){

    for(Node* child : children){
        if(child->data == query){
            return child;
        }
    }

    return nullptr;
}


DSTrie::Node& DSTrie::Node::operator=(const Node& other){
    data = other.data;
    isWord = other.isWord;

    int min = -1;

    if(children.getNumIndexes() < other.children.getNumIndexes()){
        min = children.getNumIndexes();
    } else {
        min = other.children.getNumIndexes();
    }

    for(int i = 0; i < min; i++){
        *children[i] = *other.children[i];
    }

    if(children.getNumIndexes() < other.children.getNumIndexes()){
        for(int i = min - 1; i < other.children.getNumIndexes(); i++){
            Node* child = new Node(*other.children[i]);
            children.pushBack(child);
        }
    } else{
        int leftToDelete = children.getNumIndexes() - min;
        while(leftToDelete > 0){
            delete children[children.getNumIndexes() - 1];
            children.removeLast();
        }
    }

    return *this;
}


bool DSTrie::Node::operator==(const Node& other) const{
    if(data != other.data ||
            isWord != other.isWord ||
                children.getNumIndexes() != other.children.getNumIndexes()){
        return false;
    }

    if(children == other.children){
        return true;
    }

    for(int i = 0; i < children.getNumIndexes(); i++){
        if(*children[i] != *other.children[i]){
            return false;
        }
    }

    return true;
}

bool DSTrie::Node::operator!=(const Node& other) const{
    return !(*this == other);
}

/**
 * @brief DSTrie::Node::~Node - default destructor
 */
DSTrie::Node::~Node(){
    for(int i = 0; i < children.getNumIndexes(); i++){
        delete children[i];
    }
}

/**
 * @brief DSTrie::DSTrie - default constructor
 */
DSTrie::DSTrie() : root(new Node()){}

/**
 * @brief DSTrie - copy constructor
 * @param other - trie to copy
 */
DSTrie::DSTrie(const DSTrie& other) : root(new Node(*other.root)){}

/**
 * @brief DSTrie - constructor from a vector of strings
 * @param data - vector of strings to turn into a trie
 */
DSTrie::DSTrie(const DSVector<DSString>& data){
    root = new Node();

    addStrings(data);
}

/**
 * @brief DSTrie::addString -
 * @param str - string to add
 */
void DSTrie::addString(const DSString str)
{
    Node* current = root;
    Node* child = nullptr;
    for(int j = 0; j < str.size(); j++){
        Node* child = current->getChild(str[j]);
        if(child == nullptr){
            child = new Node(str[j]);
            current->children.pushBack(child);
        }

        current = child;
    }

    if(child != nullptr){
        child->isWord = true;
    }
}

/**
 * @brief DSTrie::addStrings
 * @param strs - vector of strings to add
 */
void DSTrie::addStrings(const DSVector<DSString> strs)
{
    for(int i = 0; i < strs.getNumIndexes(); i++){
        addString(strs[i]);
    }
}

/**
 * @brief DSTrie::removeString
 * @param str - string to remove
 */
void DSTrie::removeString(const DSString str)
{

}

/**
 * @brief DSTrie::removestrings
 * @param strs - vector of strings to remove
 */
void DSTrie::removestrings(const DSVector<DSString> strs)
{

}

/**
 * @brief DSTrie::clear
 */
void DSTrie::clear()
{
    delete root;
    root = new Node();
}

/**
 * @brief DSTrie::getAll
 * @return a vector containing all strings in the trie
 */
DSVector<DSString> DSTrie::getAll() const
{
    return DSVector<DSString>();
}

/**
 * @brief DSTrie::has
 * @param word - string to check for
 * @return true if the trie contains that string, requires the last character Node to have isWord == true
 */
bool DSTrie::has(const DSString word) const
{
    return false;
}

/**
 * @brief DSTrie::has
 * @param words - vector of strings to check for
 * @return true if the trie contains EVERY string, requires the last character Node to have isWord == true
 */
bool DSTrie::has(const DSVector<DSString> words) const
{
    return false;
}

/**
 * @brief DSTrie::hasPrefix
 * @param prefix - prefix to check for
 * @return true if the trie contains the prefix
 */
bool DSTrie::hasPrefix(const DSString prefix) const
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
    return *root == *other.root;
}

/**
 * @brief operator != : compares this trie and the given trie
 * @param other - reference to the trie to compare to
 * @return false if both ries are equal
 */
bool DSTrie::operator!=(const DSTrie& other) const{
    return !(*this == other);
}

/**
 * @brief ~DSTrie() - default destructor
 */
DSTrie::~DSTrie(){
    if(root != nullptr){
        delete root;
    }
}
