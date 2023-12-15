#include "DisjointSet.h"
#include <vector>
#include <iostream>


typedef DisjointSet<std::string> stringSet;


int main() {
    std::vector<Node<std::string> *> set(6);
    for (int i = 0; i < set.size(); i++) {
        std::string value = "x" + std::to_string(i);
        set[i] = stringSet::makeSet(value);
    }
    std::cout << "Init DisjointsSet" << std::endl;
    stringSet::print(set);
    stringSet::unionSet(set[0], set[1]);
    stringSet::unionSet(set[2], set[3]);
    std::cout << "unionSet(x0,x1) unionSet(x2,x3)" << std::endl;
    stringSet::print(set);
    stringSet::unionSet(set[5], set[3]);
    stringSet::unionSet(set[4], set[1]);
    std::cout << "unionSet(x5,x3) unionSet(x4,x1)" << std::endl;
    stringSet::print(set);
    stringSet::unionSet(set[5], set[1]);
    std::cout << "unionSet(x5,x2)" << std::endl;
    stringSet::print(set);
}
