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
         * @brief Getter - numIndexes
         */
        int getNumIndexes();

        /**
         * @brief Getter - capacity
         */
        int getCapacity();

        /**
         * @brief Setter - capacity
         */
        void setCapacity();

        /**
         * @brief Getter - risizeIncrement
         */
        int getResizeIncrement();

        /**
         * @brief Setter - resizeIncrement
         */
        void setResizeIncrement();

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
        DSStack<T>& operator=(const DSStack<T>& other);

        /**
         * @brief operator == :  compares this stack against another stack
         * @param other - reference to target stack
         * @return true if the stacks have equal values
         */
        bool operator==(const DSStack<T>& other) const;



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
 * @brief Getter - numIndexes
 */
template <class T>
int DSStack<T>::getNumIndexes(){
    return numIndexes;
}

/**
 * @brief Getter - capacity
 */
template <class T>
int DSStack<T>::getCapacity(){
    return capacity;
}

/**
 * @brief Setter - capacity
 */
template <class T>
void DSStack<T>::setCapacity(){

}

/**
 * @brief Getter - risizeIncrement
 */
template <class T>
int DSStack<T>::getResizeIncrement(){
    return resizeIncrement;
}

/**
 * @brief Setter - resizeIncrement
 */
template <class T>
void DSStack<T>::setResizeIncrement(){

}

/**
 * @brief DSStack::push - increments the top pointer by one element and sets its target to the given element. Sets it to data if it is currently nullptr.
 * @param element
 */
template <class T>
void DSStack<T>::push(T element){
    if(top == nullptr){
        top = data;
    } else {
        top++;
    }

    numIndexes++;
    *top = element;
}

/**
 * @brief DSStack::pop - decrements the top pointer by one element
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
 * @brief DSStack::peek - returns the top element of the stack
 * @return top element of the stack
 */
template <class T>
T DSStack<T>::peek(){
    return *top;
}

/**
 * @brief operator = :  Sets this stack equal to the passed in stack
 * @param other - reference to target stack
 * @return reference to this stack
 */
template <class T>
DSStack<T>& DSStack<T>::operator=(const DSStack<T>& other){
    delete[] data;

    numIndexes = other.numIndexes;
    capacity = other.capacity;
    resizeIncrement = other.resizeIncrement;

    data = new T[capacity];

    for(int i = 0; i < numIndexes; i++){
        data[i] = other.data[i];
    }

    top = data + numIndexes - 1;

    return *this;
}


/**
 * @brief operator == :  compares this stack against another stack, value by value
 * @param other - reference to target stack
 * @return true if the stacks have equal values
 */
template <class T>
bool DSStack<T>::operator==(const DSStack<T>& other) const{
    if(numIndexes != other.numIndexes){
        return false;
    }

    for(int i = 0; i < numIndexes; i++){
        if(data[i] != other.data[i]){
            return false;
        }
    }

    return true;
}







#endif // DSSTACK_H
