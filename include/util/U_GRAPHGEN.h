//
// Created by thero on 20.06.2022.
//

#ifndef SDIZO_PROJ_P2_U_GRAPHGEN_H
#define SDIZO_PROJ_P2_U_GRAPHGEN_H

#include <cstdlib>
#include <iostream>

class GraphBuilder {

    uint64_t nodesNumber;
    uint64_t edgesNumber;
    uint64_t density;

    int64_t * data = nullptr;

    size_t size = 0;

public:

    GraphBuilder(const uint64_t& nodesNumber_, const uint64_t& density_);
    ~GraphBuilder();

    uint64_t getNodesNumber()
    {
        return this->nodesNumber;
    }

    uint64_t getEdgesNumber()
    {
        return this->edgesNumber;
    }

    uint64_t getDensity()
    {
        return this->density;
    }

    int64_t * getData()
    {
        return this->data;
    }
};

#endif //SDIZO_PROJ_P2_U_GRAPHGEN_H
