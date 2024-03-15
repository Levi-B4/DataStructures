#ifndef DSSTACK_H
#define DSSTACK_H

template <class T>
class DSStack{
public:
    /**
     * @brief Default constructor
     * @param int capacity = 10, int resizeIncrement = 10
     */
    DSStack(int capacity = 10, int resizeIncrement = 10);

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
    T peekTop();

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
     * @brief operator =
     * @param DSStack<T>& other
     * @return DSStack<T>&
     */
    DSStack<T>& operator=(const DSStack<T>& other);

    /**
     * @brief Default destructor
     */
    ~DSStack();
private:
    T* data;
    T* top;
    int numElements;
    int capacity;
    int resizeIncrement;

};

/**
 * @brief Default constructor
 * @param int capacity = 10, int resizeIncrement = 10
 */
template <class T>
DSStack<T>::DSStack(int capacity, int resizeIncrement){
    this->capacity = capacity;
    data = new T[capacity];
    this->resizeIncrement = resizeIncrement;
    top = nullptr;
    numElements = 0;
}

/**
 * @brief places element one position after top, making it the new top
 * @param T element
 */
template <class T>
void DSStack<T>::push(T element){
    numElements++;

    if(top == nullptr){
        top = data;
        *top = element;
        return;
    }

    if(capacity == size){
        T* temp = data;
        data = new T[capacity + resizeIncrement];

        for(int i = 0; i < numElements; i++){
            data[i] = temp[i];
        }

        delete temp;
        top = data + numElements - 2;
    }

    *top = element;
}

/**
 * @brief removes last element from the top of the stack
 */
template <class T>
void DSStack<T>::pop(){
    if(top != nullptr){
        numElements--;
        top--;
    }
}

/**
 * @brief accesses top element of the stack
 * @return T
 */
template <class T>
T DSStack<T>::peekTop(){
    return *top;
}

/**
 * @brief returns true if top is nullptr
 * @return bool
 */
template <class T>
bool DSStack<T>::isEmpty(){
    if(top == nullptr){
        return true;
    } else{
        return false;
    }
}

/**
 * @brief returns the size of data
 * @return int
 */
template <class T>
int DSStack<T>::size(){
    return numElements;
}

/**
 * @brief operator =
 * @param DSStack<T>& other
 * @return DSStack<T>&
 */
template <class T>
DSStack<T>& DSStack<T>::operator=(const DSStack<T>& other){
    delete[] data;

    numElements = other.numElements;
    capacity = other.capacity;
    resizeIncrement = other.resizeIncrement;

    data = new T[capacity];

    for(int i = 0; i < numElements; i++){
        this->data[i] = other.data[i];
    }

    return *this;
}

/**
 * Default destructor
 */
template <class T>
DSStack<T>::~DSStack(){
    delete data;
}

#endif // DSSTACK_H
