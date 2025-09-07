#ifndef DSLISTSTACK_H
#define DSLISTSTACK_H

#include "dsdoublyll.h"


template <class T>
class DSListStack
{
public:
    /**
     * @brief DSStack - default constructor
     */
    DSListStack();
    /**
     * @brief DSStack - copy constructor
     * @param other - reference to target stack
     */
    DSListStack(const DSListStack<T>& other);

    /**
     * @brief ~DSStack - destructor
     */
    ~DSListStack();

    /**
     * @brief Getter - numIndexes
     */
    int size();

    /**
     * @brief push - adds an element to the top of the stack
     * @param element - element to add to stack
     */
    void push(T element);

    /**
     * @brief pop - removes the top element of the stack
     */
    void pop();

    /**
     * @brief peek - returns the top element of the stack
     * @return top element of the stack
     */
    T peek();

    /**
     * @brief operator = :  Sets this stack equal to the passed in stack
     * @param other - reference to target stack
     * @return reference to this stack
     */
    DSListStack<T>& operator=(const DSListStack<T>& other);

    /**
     * @brief operator + : returns a stack combining this and the given stack
     * @param other - reference to given stack
     * @return combined stack of this and given stack
     */
    DSListStack<T> operator+(const DSListStack<T>& other) const;

    /**
     * @brief operator += : combines this stack with the given stack
     * @param other - reference to the given stack
     * @return this stack, after it has been combined with the given
     */
    DSListStack<T>& operator+=(const DSListStack<T>& other);

    /**
     * @brief operator == : compares this stack against another stack
     * @param other - reference to target stack
     * @return true if the stacks have equal values
     */
    bool operator==(const DSListStack<T>& other) const;

private:
    DSDoublyLL<T> data;
};

/**
 * @brief DSStack - default constructor
 */
template <class T>
DSListStack<T>::DSListStack(){}
/**
 * @brief DSStack - copy constructor
 * @param other - reference to target stack
 */
template <class T>
DSListStack<T>::DSListStack(const DSListStack<T>& other){
    data = other->data;
}

/**
 * @brief ~DSStack - destructor
 */
template <class T>
DSListStack<T>::~DSListStack(){}

/**
 * @brief Getter - numIndexes
 */
template <class T>
int DSListStack<T>::size(){
    return data.size();
}

/**
 * @brief push - adds an element to the top of the stack
 * @param element - element to add to stack
 */
template <class T>
void DSListStack<T>::push(T element){
    data.pushBack(element);
}

/**
 * @brief pop - removes the top element of the stack
 */
template <class T>
void DSListStack<T>::pop(){
    data.popBack();
}

/**
 * @brief peek - returns the top element of the stack
 * @return top element of the stack
 */
template <class T>
T DSListStack<T>::peek(){
    return data[size() - 1];
}

/**
 * @brief operator = :  Sets this stack equal to the passed in stack
 * @param other - reference to target stack
 * @return reference to this stack
 */
template <class T>
DSListStack<T>& DSListStack<T>::operator=(const DSListStack<T>& other){
    data = other.data;

    return *this;
}

/**
 * @brief operator + : returns a stack combining this and the given stack
 * @param other - reference to given stack
 * @return combined stack of this and given stack
 */
template <class T>
DSListStack<T> DSListStack<T>::operator+(const DSListStack<T>& other) const{
    DSListStack<T> result;
    result.data = data + other.data;

    return result;
}

/**
 * @brief operator += : combines this stack with the given stack
 * @param other - reference to the given stack
 * @return this stack, after it has been combined with the given
 */
template <class T>
DSListStack<T>& DSListStack<T>::operator+=(const DSListStack<T>& other){
    data += other.data;
}


/**
 * @brief operator == : compares this stack against another stack
 * @param other - reference to target stack
 * @return true if the stacks have equal values
 */
template <class T>
bool DSListStack<T>::operator==(const DSListStack<T>& other) const{
    return data == other.data;
}

#endif // DSLISTSTACK_H
