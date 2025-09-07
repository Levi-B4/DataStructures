#ifndef DSLISTSTACK_H
#define DSLISTSTACK_H

template <class T>
class DSListStack
{
public:
    /**
         * @brief DSStack - default constructor
         * @param resizeIncrement - increment of size increase when at max capacity, 10 by default
         */
    DSListStack(int resizeIncrement = 10);
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
};

#endif // DSLISTSTACK_H
