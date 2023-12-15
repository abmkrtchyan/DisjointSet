#ifndef DISJOINT_SET_DISJOINT_SET_H
#define DISJOINT_SET_DISJOINT_SET_H

#include <iostream>
#include <vector>


template<class T>
class Node {
public:
    T value;
    int rank;
    Node *parent;


    Node(T value, int rank = 0, Node *p = nullptr) :
            value(value), rank(rank), parent(p) {}
};


template<class T>
class DisjointSet {
public:
    static Node<T> *makeSet(T val) {
        auto node = new Node<T>(val);
        node->parent = node;
        return node;
    }


    static Node<T> *findSet(Node<T> *node) {
        if (node->parent->value != node->value) {
            node->parent = findSet(node->parent);
        }
        return node->parent;
    }


    static void unionSet(Node<T> *n1, Node<T> *n2) {
        auto v1 = findSet(n1);
        auto v2 = findSet(n2);
        if (v1->value != v2->value)
            link_by_rank(v1, v2);
    }


    static void link_by_rank(Node<T> *n1, Node<T> *n2) {
        if (n1->rank > n2->rank) {
            n2->parent = n1;
        } else if (n1->rank < n2->rank) {
            n1->parent = n2;
        } else if (n1->rank == n2->rank) {
            n1->parent = n2;
            n2->rank++;
        }
    }


    static void print(std::vector<Node<T> *> nodes) {
        std::cout << std::endl << "DISJOINT SETS:" << std::endl;
        for (auto it: nodes) {
            std::cout << "Value is: " << it->value
                      << ", Rank is: " << it->rank
                      << ", Parent is: " << findSet(it)->value
                      << std::endl;
        }
    }
};

#endif //DISJOINT_SET_DISJOINT_SET_H
