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





    private:
        T* data;
        int capacity;
        int numIndexes = 0;
        int resizeIncrement;
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


#endif // DSSTACK_H
