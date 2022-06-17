//
// Created by thero on 13.06.2022.
//

#ifndef SDIZO_PROJ_P2_G_ADJ_LIST_H
#define SDIZO_PROJ_P2_G_ADJ_LIST_H
#include <iostream>
#include "G_GRAPH.h"
#include "G_EDGE.h"


class AdjacencyList : public Graph
{
private:

    Edge ** edgeTab;

public:

    AdjacencyList(const uint64_t& nNodes, const uint64_t& nEdges, const int64_t * data);
    AdjacencyList(const uint64_t& nNodes, const uint64_t& nEdges);

    ~AdjacencyList();


    void add(const uint64_t& src, const uint64_t& dest, const int64_t& cost);

    void print() override;

    Edge ** get_edgeTab();

};

#endif //SDIZO_PROJ_P2_G_ADJ_LIST_H
