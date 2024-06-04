#ifndef DSSTACK_H
#define DSSTACK_H

template <class T>
class DSStack{
    public:
        /**
         * @brief DSStack - default constructor
         * @param resizeIncrement - increment of size increase when at max capacity, 10 by default
         */
        DSStack(int resizeIncrement = 10);
        /**
         * @brief DSStack - copy constructor
         * @param other - reference to target stack
         */
        DSStack(const DSStack<T>& other);

        /**
         * @brief ~DSStack - destructor
         */
        ~DSStack();

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




    private:
        T* data;
        int capacity;
        int numIndexes = 0;
        int resizeIncrement;
        T* top = nullptr;
};

/**
 * @brief DSStack::DSStack - default constructor
 * @param resizeIncrement - increment of size increase when at max capacity, 10 by default
 */
template <class T>
DSStack<T>::DSStack(int resizeIncrement){
    this->resizeIncrement = resizeIncrement;
    capacity = resizeIncrement;
    data = new T[capacity];
}

/**
 * @brief DSStack::DSStack - copy constructor
 * @param other - reference to target stack
 */
template <class T>
DSStack<T>::DSStack(const DSStack<T>& other){
    capacity = other.capacity;
    numIndexes = other.numIndexes;
    resizeIncrement = other.resizeIncrement;

    data = new T[capacity];

    for(int i = 0; i < numIndexes; i++){
        this->data[i] = other.data[i];
    }
}

/**
 * @brief ~DSStack - destructor
 */
template <class T>
DSStack<T>::~DSStack(){
    delete[] data;
}

/**
 * @brief pop - decrements the top pointer by one element
 */
template <class T>
void DSStack<T>::pop(){
    if(numIndexes == 0){
        return;
    } else{
        top--;
        numIndexes--;
    }
}

/**
 * @brief peek - returns the top element of the stack
 * @return top element of the stack
 */
template <class T>
T DSStack<T>::peek(){
    return *top;
}



#endif // DSSTACK_H
