//
// Created by thero on 17.06.2022.
//
#include "../../include/structs/G_PATH.h"

Path::Path()
        : nodes{nullptr}, costs{nullptr}, cost{0}, size{0}
{
    //all init covered in init list
}

Path::~Path()
{
    delete[] this->nodes;
    delete[] this->costs;

    this->cost = 0;
    this->size = 0;
}

void Path::add(const int64_t &node, const int64_t &cost)
{
    this->cost += cost;

    if(this->size == 0)
    {
        this->nodes = new uint64_t;
        this->nodes[0] = node;

        this->costs = new uint64_t;
        this->costs[0] = cost;
    }
    else
    {
        auto tNodes = new uint64_t[this->size + 1];
        auto tCosts = new uint64_t[this->size + 1];

        tNodes[0] = node;
        tCosts[0] = cost;

        for (size_t i = 0; i < this->size + 1; i++)
        {
            tNodes[i] = nodes[i - 1];
            tCosts[i] = costs[i - 1];
        }

        delete this->nodes;
        delete this->costs;

        this->nodes = tNodes;
        this->costs = tCosts;
    }

    this->size++;
}

void Path::print()
{
    if(this->size == 0)
    {
        std::cout << "No available path.\n";
        return;
    }

    std::cout << "Path from: " << nodes[0] << " to " << nodes[this->size - 1] << std::endl;
    std::cout << "|" << nodes[0] << " : " << costs[0] << "|";

    for(size_t i = 1; i < this->size; i++)
    {
        std::cout << "  ->  |" << nodes[i] << " : " << costs[i] << "|";
    }

    std::cout << "\nTotal cost = " << cost << std::endl;
}
