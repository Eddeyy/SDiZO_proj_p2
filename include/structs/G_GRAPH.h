//
// Created by thero on 13.06.2022.
//

#ifndef SDIZO_PROJ_P2_G_GRAPH_H
#define SDIZO_PROJ_P2_G_GRAPH_H

class Graph
{
protected:

    uint64_t nNodes;
    uint64_t nEdges;
    uint64_t density;

    void densityCalc()
    {
        this->density = ((2 * this->nEdges * 100) / (this->nNodes * (this->nNodes - 1)));
    };

public:

    Graph (const uint64_t& _nNodes,const uint64_t& _nEdges) : nNodes{_nNodes}, nEdges{_nEdges}
    {
        if(_nNodes && _nEdges)
            densityCalc();
    };

    virtual void print() = 0;

    virtual uint64_t get_nNodes(){return nNodes;};
    virtual uint64_t get_nEdges(){return nEdges;};
    virtual uint64_t get_density(){return density;};

};

#endif //SDIZO_PROJ_P2_G_GRAPH_H
