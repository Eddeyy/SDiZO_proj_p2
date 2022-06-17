//
// Created by thero on 13.06.2022.
//
#include "../../include/structs/G_ADJ_LIST.h"

AdjacencyList::AdjacencyList(const uint64_t &_nNodes, const uint64_t &_nEdges) : Graph(_nNodes, _nEdges)
{
    this->edgeTab = new Edge * [this->nNodes]{nullptr};
}

AdjacencyList::AdjacencyList(const uint64_t &_nNodes, const uint64_t &_nEdges, const int64_t* data) : AdjacencyList(_nNodes, _nEdges)
{
    for(size_t dat_i = 0; dat_i < this->nEdges * 3; dat_i+=3)
    {
        auto tEdge = new Edge(data[dat_i], data[dat_i + 1], data[dat_i + 2]);

        if(this->edgeTab[data[dat_i]] == nullptr)
            this->edgeTab[data[dat_i]] = tEdge;
        else
        {
            auto tPtr = this->edgeTab[data[dat_i]];

            while(tPtr->next != nullptr)
            {
                tPtr = tPtr->next;
            }

            tPtr->next = tEdge;
        }
    }
}

AdjacencyList::~AdjacencyList()
{
    for(size_t i = 0; i< this->nNodes; i++)
    {
        auto tEdgePtr = this->edgeTab[i];
        auto destroyer = this->edgeTab[i];

        if(tEdgePtr == nullptr)
            continue;
        while(tEdgePtr->next != nullptr)
        {
            tEdgePtr = tEdgePtr->next;
            delete destroyer;
            destroyer = tEdgePtr;
        }
        delete destroyer;
    }

    delete[] this->edgeTab;

    this-> nNodes = 0;
    this-> nEdges = 0;
}

void AdjacencyList::add(const uint64_t &src, const uint64_t &dest, const int64_t &cost)
{
    auto edge = new Edge(src, dest, cost);

    if(this->edgeTab[edge->src] == nullptr)
        edgeTab[edge->src] = edge;
    else
    {
        auto tPtr = this->edgeTab[edge->src];

        while(tPtr->next != nullptr)
        {
            tPtr = tPtr->next;
        }

        tPtr->next = edge;
    }
    densityCalc();
}

void AdjacencyList::print()
{
    for(size_t i = 0; i < this->nNodes; i++)
    {
        auto tPtr = this->edgeTab[i];

        std::cout << i << "    ";

        while(tPtr != nullptr)
        {
            std::cout << "-> |" << tPtr->dest << " : " << tPtr->cost << "| ";
            tPtr = tPtr->next;
        }
        std::cout << "\n";
    }
}

Edge ** AdjacencyList::get_edgeTab()
{
    return this->edgeTab;
}
