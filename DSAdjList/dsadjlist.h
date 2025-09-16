#ifndef DSADJLIST_H
#define DSADJLIST_H

#include "../DSDoublyLL/dsdoublyll.h"

template <class T>
class DSAdjList
{
private:
    DSDoublyLL<DSDoublyLL<T>> data;
public:
    /**
     * @brief DSAdjList - default constructor
     */
    DSAdjList();

    /**
     * @brief DSAdjList - copy constructor
     * @param other - list to copy
     */
    DSAdjList(DSAdjList<T>& other);

    /**
     * @brief GetConnectedNode - returns all nodes connected to the given nodes
     * @param nodeData - data of the source node for connections
     * @return doubly linked list of nodes
     */
    DSDoublyLL<T> GetConnectedNodes(T nodeData);

    /**
     * @brief addNode - adds a new node to the list
     * @param nodeData - the value of the new node
     */
    void addNode(T nodeData);

    /**
     * @brief addEdge - adds a connection between two nodes with their weight
     * @param node1 - first node of the edge
     * @param node2 - second node of the edge
     */
    void addEdge(T node1, T node2);

    /**
     * @brief remove - removes a node and all of its edges
     * @param nodeData - the value of the node
     */
    void removeNode(T nodeData);

    /**
     * @brief removeEdge - removes an edge from the list
     * @param node1 - first node of the edge
     * @param node2 - second node of the edge
     */
    void removeEdge(T node1, T node2);

    /**
     * @brief ~DSAdList - default destructor
     */
    ~DSAdjList();
};


/**
 * @brief DSAdjList - default constructor
 */
template <class T>
DSAdjList<T>::DSAdjList(){}

/**
 * @brief DSAdjList - copy constructor
 * @param other - list to copy
 */
template <class T>
DSAdjList<T>::DSAdjList(DSAdjList<T>& other){}

/**
 * @brief GetConnectedNode - returns all linked list that is the tail of the given element's list
 * @param nodeData - data of the source node for connections
 * @return doubly linked list of nodes
 */
template <class T>
DSDoublyLL<T> DSAdjList<T>::GetConnectedNodes(T nodeData){}

/**
 * @brief addNode - creates a new list at the end of the data list for the given node
 * @param nodeData - the value of the new node
 */
template <class T>
void DSAdjList<T>::addNode(T nodeData){}

/**
 * @brief addEdge - adds the given nodes to eachother's lists
 * @param node1 - first node of the edge
 * @param node2 - second node of the edge
 */
template <class T>
void DSAdjList<T>::addEdge(T node1, T node2){}

/**
 * @brief remove - removes a node's list and all of its occurances in other lists
 * @param nodeData - the value of the node
 */
template <class T>
void DSAdjList<T>::removeNode(T nodeData){}

/**
 * @brief removeEdge - removes the given nodes from each others lists
 * @param node1 - first node of the edge
 * @param node2 - second node of the edge
 */
template <class T>
void DSAdjList<T>::removeEdge(T node1, T node2){}

/**
 * @brief ~DSAdList - default destructor
 */
template <class T>
DSAdjList<T>::~DSAdjList(){}

#endif // DSADJLIST_H
