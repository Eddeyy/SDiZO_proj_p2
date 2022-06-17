//
// Created by thero on 17.06.2022.
//

#ifndef SDIZO_PROJ_P2_G_EDGE_HEAP_H
#define SDIZO_PROJ_P2_G_EDGE_HEAP_H
#include <iostream>
#include "G_EDGE.h"

class Heap {

    Edge** tab;
    size_t size;

    void heapify(int i);

public:
    Heap();
    ~Heap();

    Edge* operator[](int);

    void push(Edge* edge);
    Edge* pop();

    void printHeap();

    void buildHeap();

    size_t getSize() const
    {
        return this->size;
    }
};


#endif //SDIZO_PROJ_P2_G_EDGE_HEAP_H
