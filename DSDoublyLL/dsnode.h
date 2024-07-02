#ifndef DSNODE_H
#define DSNODE_H

template <class T>
class DSNode{
    public:
        DSNode* next = nullptr;
        DSNode* prev = nullptr;

        T data;

        /**
         * @brief DSNode - default constructor
         */
        DSNode();

        /**
         * @brief DSNode - constructor
         * @param data - value to set as this node's data
         */
        DSNode(T data);

        /**
         * @brief ~6DSNode - default destructor
         */
        ~DSNode();
};

/**
 * @brief DSNode - default constructor
 */
template <class T>
DSNode<T>::DSNode(){

}

template <class T>
DSNode<T>::DSNode(T data){
    this->data = data;
}

/**
 * @brief ~DSNode - default destructor
 */
template <class T>
DSNode<T>::~DSNode(){

}

#endif // DSNODE_H
