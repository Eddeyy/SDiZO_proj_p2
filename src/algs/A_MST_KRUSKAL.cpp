//
// Created by thero on 20.06.2022.
//
#include "../../include/algs/A_MST_KRUSKAL.h"
#include "../../include/structs/G_EDGE_HEAP.h"

IncidenceMatrix* Kruskal::genMST(IncidenceMatrix* mat)
{
    auto edgesNumber = mat->get_nEdges();
    auto nodesNumber = mat->get_nNodes();
    auto matrix = mat->getMatrix();
    auto edgeValues = mat->getEVals();

    auto heap = new Heap();
    auto resultMatrix = new IncidenceMatrix(nodesNumber, edgesNumber);

    int64_t totalCost = 0;
    int64_t connectingEdges = 0;

    auto setsID = new size_t[nodesNumber];

    for(int i = 0; i < nodesNumber; i++)
    {
        setsID[i] = i;
    }

    // inserting edge heap
    for(int i = 0; i < edgesNumber; i++)
    {
        size_t source, destination;

        for(int j = 0; j < nodesNumber; j++)
        {
            if(matrix[j][i] == -1)
                source = j;

            if(matrix[j][i] == 1)
                destination = j;
        }

        heap->push(new Edge(source, destination, edgeValues[i]));
    }

    while(heap->getSize())
    {
        if(connectingEdges == nodesNumber - 1)
            break;

        auto minEdge = heap->pop();

        if(setsID[minEdge->src] != setsID[minEdge->dest])
        {
            resultMatrix->add(minEdge->src, minEdge->dest, minEdge->cost);

            auto oldID = setsID[minEdge->src];
            auto newID = setsID[minEdge->dest];

            for(int i = 0; i < nodesNumber; i++)
            {
                if(setsID[i] == oldID)
                    setsID[i] = newID;
            }

            totalCost += minEdge->cost;
            connectingEdges++;
        }
    }

    return resultMatrix;
}

AdjacencyList* Kruskal::genMST(AdjacencyList* list)
{
    // inserting needed data
    auto edgesNumber = list->get_nEdges();
    auto nodesNumber = list->get_nNodes();
    auto edgesTable = list->get_edgeTab();

    // creating min heap and return list
    auto heap = new Heap();
    auto listToReturn = new AdjacencyList(nodesNumber, edgesNumber);

    int64_t totalCost = 0;
    int64_t connectingEdges = 0;

    // this table includes ids of kruskal sets
    auto setsID = new size_t[nodesNumber];

    for(int i = 0; i < nodesNumber; i++)
    {
        setsID[i] = i;
    }

    Edge* tempEdge = nullptr;

    // pushing edge into min heap
    for(int i = 0; i < nodesNumber; i++)
    {
        tempEdge = edgesTable[i];

        while(tempEdge != nullptr)
        {
            heap->push(tempEdge);
            tempEdge = tempEdge->next;
        }
    }

    // main algorithm
    while(heap->getSize())
    {
        // poping min edge
        auto minEdge = heap->pop();

        // condition of v-1 connecting edges
        if(connectingEdges == nodesNumber - 1)
            break;

        // checking if source and destination of min edge
        // are in the same set
        if(setsID[minEdge->src] != setsID[minEdge->dest])
        {
            // adding edge into return list
            listToReturn->add(minEdge->src, minEdge->dest, minEdge->cost);

            // changing sets id
            auto oldID = setsID[minEdge->src];
            auto newID = setsID[minEdge->dest];

            for(int i = 0; i < nodesNumber; i++)
            {
                if(setsID[i] == oldID)
                    setsID[i] = newID;
            }

            // increasing costs and connectind edges
            totalCost += minEdge->cost;
            connectingEdges++;
        }
    }

    tempEdge = nullptr;
    delete heap;
    delete[] setsID;

    return listToReturn;
}


bool Kruskal::isEmpty(bool *table, const size_t& size)
{
    for(int i = 0; i < size; i++)
        if(!table[i])
            return true;
    return false;

}