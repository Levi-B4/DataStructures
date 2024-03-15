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
    int size;
    int capacity;
    int resizeIncrement;

};

/**
 * @brief Default constructor
 * @param int capacity = 10, int resizeIncrement = 10
 */
template <class T>
DSStack::DSStack(){
    this->capacity = capacity;
    data = new T[capacity];
    this->resizeIncrement = resizeIncrement;
    top = nullptr;
    size = 0;
}

/**
 * @brief places element one position after top, making it the new top
 * @param T element
 */
template <class T>
void push(T element){
    size++;

    if(top == nullptr){
        top = data;
        *top = element;
        return;
    }

    if(capacity == size){
        T* temp = data;
        data = new T[capacity + resizeIncrement];

        for(int i = 0; temp + i - 1 != top; i++){
            data[i] = temp[i];
        }

        delete temp;
        top = data + size - 1;
    }

    *top = element;
}

/**
 * @brief removes last element from the top of the stack
 */
template <class T>
void pop(){
    if(top != nullptr){
        size--;
        top--;
    }
}

/**
 * @brief accesses top element of the stack
 * @return T
 */
template <class T>
T top(){
    return *top;
}

/**
 * @brief returns true if top is nullptr
 * @return bool
 */
template <class T>
bool isEmpty(){
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
int size(){
    return size;
}

/**
 * Default destructor
 */
template <class T>
DSStack::~DSStack(){
    delete data;
}

#endif // DSSTACK_H
