//
// Created by hkhai on 12/10/2018.
//

#ifndef LAB_12_1_EDGE_H
#define LAB_12_1_EDGE_H

#include <iostream>

using namespace std;

class Edge {
public:
    int u;
    int v;

    Edge(int u, int v) {
        this->u = u;
        this->v = v;
    }
};

#endif //LAB_12_1_EDGE_H
