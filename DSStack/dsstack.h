#ifndef DSSTACK_H
#define DSSTACK_H

template <class T>
class DSStack{
public:
    /**
     * @brief Default constructor
     */
    DSStack();

    /**
     * @brief adds element to the top of the stack
     * @param T element
     */
    void push(T element);

    /**
     * @brief removes last element from the top of the stack
     */
    void pop();

    /**
     * @brief accesses top element of the stack
     * @return T
     */
    T top();

    /**
     * @brief returns true if data is empty
     * @return bool
     */
    bool isEmpty();

    /**
     * @brief returns the size of data
     * @return int
     */
    int size();

    /**
     * @brief Default destructor
     */
    ~DSStack();
private:
    T* data;
    T* top;
    int capacity;
    int numIndexes;
    int resizeIncrement;

};

/**
 * @brief Default constructor
 */
template <class T>
DSStack::DSStack(){

}

/**
 * @brief places element one position after top, making it the new top
 * @param T element
 */
void push(T element){
    top++;
    *top = element;
}

/**
 * @brief removes last element from the top of the stack
 */
void pop();

/**
 * @brief accesses top element of the stack
 * @return T
 */
T top();

/**
 * @brief returns true if top is nullptr
 * @return bool
 */
bool isEmpty();

/**
 * @brief returns the size of data
 * @return int
 */
int size();

/**
 * Default destructor
 */
template <class T>
DSStack::~DSStack(){

}

#endif // DSSTACK_H
