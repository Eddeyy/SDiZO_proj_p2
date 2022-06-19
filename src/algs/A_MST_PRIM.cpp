//
// Created by thero on 18.06.2022.
//

#include "../../include/algs/A_MST_PRIM.h"

AdjacencyList* Prim::genMST(AdjacencyList *list, const uint64_t &start)
{

    // initializing local variables
    auto edgesNumber = list->get_nEdges();
    auto nodesNumber = list->get_nNodes();
    auto edgesTable = list->get_edgeTab();

    auto heap = new Heap();

    auto visitedNodes = new bool[nodesNumber]{false};
    visitedNodes[start] = true;

    int64_t totalCost = 0;

    // creating result list
    auto listToReturn = new AdjacencyList(nodesNumber, edgesNumber);

    Edge* tempPointer = nullptr;

    // inserting heap with start edges
    for(int i = 0; i < nodesNumber; i++)
    {
        tempPointer = edgesTable[i];

        while(tempPointer != nullptr)
        {
            if(tempPointer->src == start || tempPointer->dest == start)
            {
                heap->push(tempPointer);
            }
            tempPointer = tempPointer->next;
        }
    }

    // main algorithm
    while(isEmpty(visitedNodes, nodesNumber))
    {
        // popping edge with min cost
        auto minEdge = heap->pop();

        // checking if node has been already visited
        // if hasnt, adding it to result list
        if(!visitedNodes[minEdge->dest])
        {
            totalCost += minEdge->cost;
            visitedNodes[minEdge->dest] = true;

            listToReturn->add(minEdge->src, minEdge->dest, minEdge->cost);

            // adding new edges to heap
            for(int i = 0; i < nodesNumber; i++)
            {
                tempPointer = edgesTable[i];

                while(tempPointer != nullptr)
                {
                    if(tempPointer->src == minEdge->dest || tempPointer->dest == minEdge->dest)
                    {
                        heap->push(tempPointer);
                    }
                    tempPointer = tempPointer->next;
                }
            }
        }

        if(!visitedNodes[minEdge->src])
        {
            totalCost += minEdge->cost;
            visitedNodes[minEdge->src] = true;

            listToReturn->add(minEdge->dest, minEdge->src, minEdge->cost);

            // adding new edges to heap
            for(int i = 0; i < nodesNumber; i++)
            {
                tempPointer = edgesTable[i];

                while(tempPointer != nullptr)
                {
                    if(tempPointer->src == minEdge->src || tempPointer->dest == minEdge->src)
                    {
                        heap->push(tempPointer);
                    }
                    tempPointer = tempPointer->next;
                }
            }
        }
    }

    // realeasing memory
    delete tempPointer;
    delete[] visitedNodes;
    delete heap;

    return listToReturn;
}


IncidenceMatrix* Prim::genMST(IncidenceMatrix *mat, const uint64_t &start)
{
    // initializing local variables
    auto edgesNumber = mat->get_nEdges();
    auto nodesNumber = mat->get_nNodes();
    auto matrix = mat->getMatrix();
    auto edgeValues = mat->getEVals();

    int64_t totalCost = 0;

    auto heap = new Heap();
    auto resultMatrix = new IncidenceMatrix(nodesNumber, nodesNumber-1);

    auto visitedNodes = new bool[nodesNumber]{false};
    visitedNodes[start] = true;

    // inserting edge heap
    for(int i = 0; i < edgesNumber; i++)
    {
        size_t source, destination;

        if(matrix[start][i] != 0)
        {
            for(int j = 0; j < nodesNumber; j++)
            {
                if(matrix[j][i] == -1)
                    source = j;

                if(matrix[j][i] == 1)
                    destination = j;
            }

            heap->push(new Edge(source, destination, edgeValues[i]));
        }
    }

    // main algorithm
    while(isEmpty(visitedNodes, nodesNumber))
    {
        // popping edge with min cost
        auto minEdge = heap->pop();

        // checking if node has been already visited
        // if hasnt, adding it to result list
        if(!visitedNodes[minEdge->dest])
        {
            totalCost += minEdge->cost;
            visitedNodes[minEdge->dest] = true;

            resultMatrix->add(minEdge->src, minEdge->dest, minEdge->cost);

            // adding new edges to heap
            for(int i = 0; i < edgesNumber; i++)
            {
                size_t source, destination;

                if(matrix[minEdge->src][i]|| matrix[minEdge->dest][i])
                {
                    for(int j = 0; j < nodesNumber; j++)
                    {
                        if(matrix[j][i] == -1)
                            source = j;

                        if(matrix[j][i] == 1)
                            destination = j;
                    }

                    heap->push(new Edge(source, destination, edgeValues[i]));
                }
            }
        }

        if(!visitedNodes[minEdge->src])
        {
            totalCost += minEdge->cost;
            visitedNodes[minEdge->src] = true;

            resultMatrix->add(minEdge->src, minEdge->dest, minEdge->cost);

            // adding new edges to heap
            for(int i = 0; i < edgesNumber; i++)
            {
                size_t source, destination;

                if(matrix[minEdge->src][i] || matrix[minEdge->dest][i])
                {
                    for(int j = 0; j < nodesNumber; j++)
                    {
                        if(matrix[j][i] == -1)
                            source = j;

                        if(matrix[j][i] == 1)
                            destination = j;
                    }

                    heap->push(new Edge(source, destination, edgeValues[i]));
                }
            }
        }
    }

    return resultMatrix;
}

bool Prim::isEmpty(const bool *table, const size_t& size)
{
    for(size_t i = 0; i < size; i++)
        if(!table[i])
            return true;

    return false;
}
