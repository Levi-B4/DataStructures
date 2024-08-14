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
    void insert(T data, int index);

    /**
         * @brief popFront - removes first node from list
         */
    void popFront();

    /**
         * @brief popBack - removes last node from list
         */
    void popBack();

    /**
         * @brief DSDoublyLL::operator [] - returns data at passed index
         * @param index - index to retrieve data
         * @return data at passed index
         */
    T operator[](const int index) const;

    /**
         * @brief operator = :  sets this list equal to the list passed in
         * @param other - reference to target list
         * @return returns this
         */
    DSDoublyLL<T>& operator=(const DSDoublyLL<T>& other);

    /**
         * @brief operator == :  compares this list against another list
         * @param other - reference to target list
         * @return true if the lists have equal values
         */
    bool operator==(const DSDoublyLL<T>& other) const;

    /**
         * @brief ~DSDoublyLL - default destructor
         */
    ~DSDoublyLL();

private:
    DSNode<T>* head = nullptr;
    DSNode<T>* tail = nullptr;

    int numIndexes = 0;
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
 * @brief DSDoublyLL::operator [] - returns data of node at passed index
 * @param index - index to retrieve data
 * @return data of node at passed index
 */
template <class T>
T DSDoublyLL<T>::operator[](const int index) const{
    DSNode<T>* current;

    if(index < 0){
        current = tail;

        for(int i = 0; i > index; i--){
            current = current->prev;
        }

    } else {
        current = head;

        for(int i = 0; i < index; i++){
            current = current->next;
        }
    }

    return current->data;
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

#endif // DSDOUBLYLL_H
