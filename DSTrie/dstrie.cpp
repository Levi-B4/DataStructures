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

DSVector<DSString> DSTrie::Node::getAll(){
    DSVector<DSString> output;

    getAll(output, "");

    return output;
}

void DSTrie::Node::getAll(DSVector<DSString>& output, const DSString& current){
    if(isWord){
        output += current;
    }

    for(Node* child : children){
        child->getAll(output, current + child->data);
    }
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
        for(int i = min; i < other.children.getNumIndexes(); i++){
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
DSTrie::Node::~Node(){}

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
void DSTrie::addString(const DSString& str)
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

    if(current != nullptr){
        current->isWord = true;
    }
}

/**
 * @brief DSTrie::addStrings
 * @param strs - vector of strings to add
 */
void DSTrie::addStrings(const DSVector<DSString>& strs)
{
    for(int i = 0; i < strs.getNumIndexes(); i++){
        addString(strs[i]);
    }
}

/**
 * @brief DSTrie::removeString
 * @param str - string to remove
 */
void DSTrie::removeString(const DSString& str)
{
    Node* current = root;
    DSVector<DSVector<Node*>::iterator> trail;
    for(int i = 0; i < str.size(); i++){
        for(DSVector<Node*>::iterator it = current->children.begin(); true; it++){
            if((*it)->data == str[i]){
                trail.pushBack(it);
                current = *it;
                break;
            }

            if(it == current->children.end() - 1){
                return;
            }
        }
    }

    if(current->isWord != true){
        return;
    }
    current->isWord = false;

    while(trail.getNumIndexes() > 0){
        if( current->children.getNumIndexes() == 0){
            DSVector<Node*>::iterator temp = trail.back();
            trail.removeLast();
            (*trail.back())->children.remove(temp);
            delete *temp;
        } else {
            return;
        }
    }
}

/**
 * @brief DSTrie::removestrings
 * @param strs - vector of strings to remove
 */
void DSTrie::removestrings(const DSVector<DSString>& strs)
{
    for(int i = 0; i < strs.getNumIndexes(); i ++){
        removeString(strs[i]);
    }
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
    return root->getAll();
}

/**
 * @brief DSTrie::has
 * @param word - string to check for
 * @return true if the trie contains that string, requires the last character Node to have isWord == true
 */
bool DSTrie::has(const DSString& str) const
{
    Node* current = root;

    if(root->children.getNumIndexes() == 0 ||
            str == ""){
        return false;
    }

    for(int i = 0; i < str.size(); i++){
        for(DSVector<Node*>::iterator it = current->children.begin(); true; it++){
            if((*it)->data == str[i]){
                current = *it;
                break;
            }

            if(it == current->children.end() - 1){
                return false;
            }
        }
    }

    return current->isWord;
}

/**
 * @brief DSTrie::has
 * @param words - vector of strings to check for
 * @return true if the trie contains EVERY string, requires the last character Node to have isWord == true
 */
bool DSTrie::has(const DSVector<DSString>& strs) const
{
   for(int i = 0; i < strs.getNumIndexes(); i ++){
        if(!has(strs[i])){
            return false;
        }
    }

    return true;
}

/**
 * @brief DSTrie::hasPrefix
 * @param prefix - prefix to check for
 * @return true if the trie contains the prefix
 */
bool DSTrie::hasPrefix(const DSString& prefix) const
{
    Node* current = root;

    if(root->children.getNumIndexes() == 0 ||
            prefix == ""){
        return false;
    }

    for(int i = 0; i < prefix.size(); i++){
        for(DSVector<Node*>::iterator it = current->children.begin(); true; it++){
            if((*it)->data == prefix[i]){
                current = *it;
                break;
            }

            if(it == current->children.end() - 1){
                return false;
            }
        }
    }

    return true;
}

DSVector<DSString> DSTrie::getPrefix(const DSString& prefix) const{
    Node* current = root;

    if(root->children.getNumIndexes() == 0){
        return DSVector<DSString>();
    }

    if(prefix == ""){
        return getAll();
    }

    for(int i = 0; i < prefix.size(); i++){
        for(DSVector<Node*>::iterator it = current->children.begin(); true; it++){
            if((*it)->data == prefix[i]){
                current = *it;
                break;
            }

            if(it == current->children.end() - 1){
                return DSVector<DSString>();
            }
        }
    }

    DSVector<DSString> output;
    current->getAll(output, prefix);

    return output;
}

/**
 * @brief operator = : sets this trie equal to the trie given
 * @param other - reference to trie to copy
 * @return reference to this trie
 */
DSTrie& DSTrie::operator=(const DSTrie& other){
    *root = *other.root;
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
    DSTrie temp = *this;
    temp.addStrings(other);
    return temp;
}

/**
 * @brief operator == : compares this trie and the given trie
 * @param other - reference to the trie to compare to
 * @return true if both tries are equal
 */
bool DSTrie::operator==(const DSTrie& other) const{
    if(root == other.root){
        return true;
    } else {
        return *root == *other.root;
    }
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
