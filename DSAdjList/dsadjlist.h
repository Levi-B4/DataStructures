#ifndef DSADJLIST_H
#define DSADJLIST_H

#include "../DSDoublyLL/dsdoublyll.h"

template <class TNode, class TWeight>
class DSAdjList
{
private:
    /**
     * @brief The NodeWeightPair class - holds a node and its connection weight
     */
    struct NodeWeightPair
    {
        NodeWeightPair(TNode node, TWeight weight): node(node), weight(weight){}
        TNode node;
        TWeight weight;
    };

    /**
     * @brief The NodeEdges class - holds a node and all of its connections
     */
    struct NodeEdges
    {
        NodeEdges(TNode source, DSDoublyLL<NodeWeightPair> connections) : source(source), connections(connections){}

        TNode source;
        DSDoublyLL<NodeWeightPair> connections;
    };

    DSDoublyLL<NodeEdges> data;
public:
    /**
     * @brief DSAdjList - default constructor
     */
    DSAdjList();

    /**
     * @brief DSAdjList - copy constructor
     * @param other - list to copy
     */
    DSAdjList(DSAdjList<TNode, TWeight>& other);

    /**
     * @brief GetConnectedNode - returns all nodes connected to the given nodes
     * @param node - source node for connections
     * @return doubly linked list of nodes
     */
    DSDoublyLL<TNode> GetConnectedNodes(TNode node);

    /**
     * @brief GetEdgeWeight - returns the weight between two nodes
     * @param n1 - first node of the connection
     * @param n2 - second node of the connection
     * @return the weight of the connected between the two given nodes
     */
    TWeight GetEdgeWeight(TNode n1, TNode n2);

    /**
     * @brief GetNodeOutEdges - returns all edges branching from a node
     * @param node - source node for the returned edges
     * @return a doubly linked list of a node and the edges weight
     */
    // TODO: look into returning an itterator instead
    DSDoublyLL<NodeWeightPair> GetNodeOutEdges(TNode node);

    /**
     * @brief GetNodeInEdges - returns all edges branching to a node
     * @param node - source node for the returned edges
     * @return a doubly linked list a node and the edges weight
     */
    DSDoublyLL<NodeWeightPair> GetNodeInEdges(TNode node);

    /**
     * @brief addNode - adds a new node to the list
     * @param node - the value of the new node
     */
    void addNode(TNode node);

    /**
     * @brief addEdge - adds a connection between two nodes with their weight
     * @param source - the source node
     * @param destination - the destination node
     * @param weight - the weight associated with this edge
     */
    void addEdge(TNode source, TNode destination, TWeight weight);

    /**
     * @brief remove - removes a node and all of its edges
     * @param element - the value of the node
     */
    void removeNode(TNode element);

    /**
     * @brief removeEdge - removes an edge from the list
     * @param n1 - the source node
     * @param n2 - the destination node
     */
    void removeEdge(TNode source, TNode destination);

    /**
     * @brief ~DSAdList - default destructor
     */
    ~DSAdjList();
};

#endif // DSADJLIST_H
