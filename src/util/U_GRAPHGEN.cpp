//
// Created by thero on 20.06.2022.
//

#include "../../include/util/U_GRAPHGEN.h"

GraphBuilder::GraphBuilder(const uint64_t& nodesNumber_, const uint64_t& density_)
        :nodesNumber(nodesNumber_), density(density_)
{
    // calculating edges number
    this->edgesNumber = (this->density) * this->nodesNumber * (this->nodesNumber - 1) / 200;

    // this variable controls how many edges should be created
    uint64_t currentEdgeNumber = this->edgesNumber;

    // initializing data table
    this->data = new int64_t[this->edgesNumber * 3];

    // filling data table with INT_MAX value
    for(int i = 0; i < this->edgesNumber * 3; i++)
    {
        data[i] = INT_MAX;
    }

    // making sure that graph will be connected
    for(int i = 0; i < this->nodesNumber; i++)
    {
        // checking if current will be from last to first node
        if(i == this->nodesNumber - 1)
        {
            data[i * 3] = i;
            data[i * 3 + 1] = 0;
            data[i * 3 + 2] = rand() % 100;
        }
        else
        {
            data[i * 3] = i;
            data[i * 3 + 1] = i + 1;
            data[i * 3 + 2] = rand() % 100;
        }

        this->size += 3;

        currentEdgeNumber--;
    }

    // if there are still edges to create
    // this loop will do them
    while(currentEdgeNumber != 0)
    {
        bool exists = false;
        int source = rand() % this->nodesNumber;
        int destination = rand() % this->nodesNumber;
        int cost = rand() % 100;

        // making sure that destination
        // is not equal to source
        while(source == destination)
        {
            destination = rand() % this->nodesNumber;
        }

        // checking if possible edges is already created
        for(int i = 0; data[i] != INT_MAX; i += 3)
        {
            if(data[i] == source && data[i + 1] == destination || data[i] == destination && data[i + 1] == source)
            {
                exists = true;
                break;
            }
        }

        // if such edge wasnt created
        // then its created here
        if(!exists)
        {
            data[this->size] = source;
            data[this->size + 1] = destination;
            data[this->size + 2] = cost;

            this->size += 3;
            currentEdgeNumber--;
        }
    }
}

GraphBuilder::~GraphBuilder()
{
    delete[] this->data;

    this->nodesNumber = 0;
    this->edgesNumber = 0;
    this->density = 0;
}