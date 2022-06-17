//
// Created by thero on 17.06.2022.
//

#ifndef SDIZO_PROJ_P2_G_INC_MAT_H
#define SDIZO_PROJ_P2_G_INC_MAT_H
#include <iostream>
#include <iomanip>
#include "G_GRAPH.h"

class IncidenceMatrix : public Graph
{
    uint64_t usedEdges = 0;

    int64_t **matrix;
    uint64_t * eVals;

public:

    IncidenceMatrix(const uint64_t& nNodes, const uint64_t& nEdges, const int64_t *data);
    IncidenceMatrix(const uint64_t& nNodes, const uint64_t& nEdges);

    ~IncidenceMatrix();

    void add(const uint64_t& src, const uint64_t& dest, const uint64_t &cost);

    void print() override;

    int64_t ** getMatrix();
    uint64_t* getEVals();

};

#endif //SDIZO_PROJ_P2_G_INC_MAT_H
