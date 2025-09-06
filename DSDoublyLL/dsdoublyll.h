#ifndef DSDOUBLYLL_H
#define DSDOUBLYLL_H

#include "dsnode.h"

template <class T>
class DSDoublyLL{
public:
    /**
     * @brief DSDoublyLL - default constructor
     */
    DSDoublyLL();

    /**
     * @brief DSDoublyLL - constructor
     * @param data - pointer to array of size elements
     * @param size - size of data array
     */
    DSDoublyLL(const T* data, const int size);

    /**
     * @brief DSDoublyLL - copy constructor
     * @param other - reference of list to copy
     */
    DSDoublyLL(const DSDoublyLL<T>& other);


    /**
     * @brief getNumIndexes - Getter: numIndexes
     * @return numIndexes
     */
    int getNumIndexes();

    /**
     * @brief pushFront - adds element data to the front of the list
     * @param data - data to be added
     */
    void pushFront(T data);

    /**
     * @brief pushBack - adds data to the front of the list
     * @param data - data to be added
     */
    void pushBack(T data);

    /**
     * @brief insert - inserts data in list at given index
     * @param data - data to be added
     * @param index - index to insert data
     */
    void insert(int index, T data);

    /**
     * @brief remove - removes data from list at given index
     * @param index - index to be removed
     */
    void remove(int index);

    /**
     * @brief popFront - removes first node from list
     */
    void popFront();

    /**
     * @brief popBack - removes last node from list
     */
    void popBack();

    /**
     * @brief size - returns the size of the list
     * @return size of the list
     */
    int size();

    /**
     * @brief DSDoublyLL::operator [] - returns data at passed index
     * @param index - index to retrieve data
     * @return data at passed index
     */
    T& operator[](const int index) const;

    /**
     * @brief operator = :  sets this list equal to the list passed in
     * @param other - reference to target list
     * @return returns this
     */
    DSDoublyLL<T>& operator=(const DSDoublyLL<T>& other);

    /**
     * @brief operator + : returns a linked list combining this and the given list
     * @param other - reference to given list
     * @return combined linked list of this and given list
     */
    DSDoublyLL<T> operator+(const DSDoublyLL<T>& other) const;

    /**
     * @brief operator += : combines this
     * @param other
     * @return
     */
    DSDoublyLL<T>& operator+=(const DSDoublyLL<T>& other);

    /**
     * @brief operator == :  compares this list against another list
     * @param other - reference to target list
     * @return true if the lists have equal values
     */
    bool operator==(const DSDoublyLL<T>& other) const;

    /**
     * @brief operator != : compares this list against another list
     * @param other - reference to target list
     * @return false if the lists have equal values
     */
    bool operator!=(const DSDoublyLL<T>& other) const;

    /**
     * @brief ~DSDoublyLL - default destructor
     */
    ~DSDoublyLL();

private:
    DSNode<T>* head = nullptr;
    DSNode<T>* tail = nullptr;

    int numIndexes = 0;

    /**
     * @brief getNodeAt: returns node at given index
     * @param index - index at which the node is
     * @return node pointer
     */
    DSNode<T>* getNodeAt(int index) const;
};

/**
 * @brief DSDoublyLL - default constructor
 */
template <class T>
DSDoublyLL<T>::DSDoublyLL(){

}

/**
 * @brief DSDoublyLL - constructor
 * @param data - pointer to array of size elements
 * @param size - size of data array
 */
template <class T>
DSDoublyLL<T>::DSDoublyLL(const T* data, const int size){
    for(int i = 0; i < size; i++){
        pushBack(data[i]);
    }
}

/**
 * @brief DSDoublyLL - copy constructor
 * @param other - reference to the list to copy
 */
template <class T>
DSDoublyLL<T>::DSDoublyLL(const DSDoublyLL& other){
    for(DSNode<T>* n = other.head; n != nullptr; n = n->next){
        pushBack(n->data);
    }
}


/**
 * @brief getNumIndexes - Getter: numIndexes
 * @return numIndexes
 */
template <class T>
int DSDoublyLL<T>::getNumIndexes(){
    return numIndexes;
}

/**
 * @brief pushFront - creates a node with data and has the current head point to it as prev, and makes it the new head
 * @param data - data to be added
 */
template <class T>
void DSDoublyLL<T>::pushFront(T data){
    numIndexes++;
    DSNode<T>* newNode = new DSNode<T>;
    newNode->data = data;

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;

        head = newNode;
    }
}

/**
 * @brief pushBack - creates a node with data and has the current tail point to it as next, and makes it the new tail
 * @param data - data to be added
 */
template <class T>
void DSDoublyLL<T>::pushBack(T data){
    numIndexes++;
    DSNode<T>* newNode = new DSNode<T>;
    newNode->data = data;

    if(tail == nullptr){
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;

        tail = newNode;
    }
}

/**
 * @brief DSDoublyLL::insert - adds a node at an index and links the next and previous nodes to the new node
 * @param data - data of the new node
 * @param index - index of the new node
 */
template <class T>
void DSDoublyLL<T>::insert(int index, T data){
    if(index == 0){
        pushFront(data);
        return;
    }

    DSNode<T>* newNode = new DSNode<T>(data);

    //ToDo: throw an "index out of bounds" error
    DSNode<T>* current = head;
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;

    current->next = newNode;

    if(newNode->next == nullptr){
        tail = newNode;
    }else {
        newNode->next->prev = newNode;
    }

    numIndexes++;
}

/**
 * @brief DSDoublyLL::remove - removes and deletes the node at an index and links the next and previous nodes together
 * @param index - index where the node will be removed
 */
template <class T>
void DSDoublyLL<T>::remove(int index){
    //ToDo: remove
}

/**
 * @brief DSDoublyLL::popFront - deletes the first node and sets it to nullptr
 */
template <class T>
void DSDoublyLL<T>::popFront(){
    if(head == nullptr){
        return;
    }

    numIndexes--;

    if(numIndexes == 0){
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    if(numIndexes == 1){
        delete head;
        head = tail;
        head->prev = nullptr;
        return;
    }

    head = head->next;
    delete head->prev;
    head->prev = nullptr;
}

/**
 * @brief DSDoublyLL::popBack - deletes the last node and sets it to nullptr
 */
template<class T>
void DSDoublyLL<T>::popBack(){
    if(tail == nullptr){
        return;
    }

    numIndexes--;

    if(numIndexes == 0){
        delete tail;
        head = nullptr;
        tail = nullptr;
        return;
    }

    if(numIndexes == 1){
        delete tail;
        tail = head;
        tail->next = nullptr;
        return;
    }

    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
}

/**
 * @brief DSDoublyLL::size - itterates through the list and counts the number of nodes
 * @return the number of nodes in the list
 */
template<class T>
int DSDoublyLL<T>::size()
{
    int total = 0;
    for(DSNode<T>* current = head; current != nullptr; current = current->next){
        total++;
    }
    return total;
}

/**
 * @brief DSDoublyLL::operator [] - returns data of node at passed index
 * @param index - index to retrieve data
 * @return data of node at passed index
 */
template <class T>
T& DSDoublyLL<T>::operator[](int index) const{
    return getNodeAt(index)->data;
}

/**
 * @brief operator = :  sets this list equal to the list passed in
 * @param other - reference to target list
 * @return returns this
 */
template <class T>
DSDoublyLL<T>& DSDoublyLL<T>::operator=(const DSDoublyLL<T>& other){
    DSNode<T>* next;
    DSNode<T>* current = head;
    while(current != nullptr){
        next = current->next;
        delete current;
        current = next;
    }
    numIndexes = 0;

    head = nullptr;
    tail = nullptr;

    for(current = other.head; current != nullptr; current = current->next){
        pushBack(current->data);
    }

    return *this;
}

/**
 * @brief operator + : returns a linked list combining this and the given list
 * @param other - reference to given list
 * @return combined linked list of this and given list
 */
template <class T>
DSDoublyLL<T> DSDoublyLL<T>::operator+(const DSDoublyLL<T>& other) const{
    DSDoublyLL<T> result;

    for(DSNode<T>* current = this->head; current != nullptr; current = current->next){
        result.pushBack(current->data);
    }

    for(DSNode<T>* current = other.head; current != nullptr; current = current->next){
        result.pushBack(current->data);
    }

    return result;
}

/**
 * @brief operator += : combines this
 * @param other
 * @return
 */
template <class T>
DSDoublyLL<T>& DSDoublyLL<T>::operator+=(const DSDoublyLL<T>& other){
    for(DSNode<T>* current = other.head; current != nullptr; current = current->next){
        pushBack(current->data);
    }

    return *this;
}

/**
 * @brief operator == :  compares this list against another list
 * @param other - reference to target list
 * @return true if the lists have equal values
 */
template <class T>
bool DSDoublyLL<T>::operator==(const DSDoublyLL<T>& other) const{
    if(numIndexes != other.numIndexes){
        return false;
    }

    DSNode<T>* i = head;
    for(DSNode<T>* j = other.head; i != nullptr; i = i->next, j = j->next){
        if(i->data != j->data){
            return false;
        }
    }

    return true;
}

/**
 * @brief operator != :  pipes to operator== and flips the return
 * @param other - reference to target list
 * @return opposite of operator==
 */
template <class T>
bool DSDoublyLL<T>::operator!=(const DSDoublyLL<T>& other) const{
    return !(*this == other);
}

/**
 * @brief ~DSDoublyLL - default destructor
 */
template <class T>
DSDoublyLL<T>::~DSDoublyLL(){
    DSNode<T>* next;
    DSNode<T>* current = head;
    while(current != nullptr){
        next = current->next;
        delete current;
        current = next;
    }
}

/**
 * @brief getNodeAt: returns node at given index
 * @param index - index at which the node is
 * @return node pointer
 */
template <class T>
DSNode<T>* DSDoublyLL<T>::getNodeAt(int index) const{
    DSNode<T>* current;

    // set indexing to start from the closer end node
    if(index < 0){
        index = numIndexes + index;
    }
    if(index > (numIndexes / 2) - 1){
        index = index - numIndexes;
    }


    if(index < 0){
        current = tail;

        for(int i = -1; i > index; i--){
            current = current->prev;
        }
    } else {
        current = head;

        for(int i = 0; i < index; i++){
            current = current->next;
        }
    }

    return current;
}

#endif // DSDOUBLYLL_H
