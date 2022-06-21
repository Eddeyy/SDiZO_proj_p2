//
// Created by thero on 20.06.2022.
//
#include "../../include/algs/A_SP_BELFOR.h"

Path* BellmanFord::getSP(IncidenceMatrix* graph, const uint64_t& start, const uint64_t& finish)
{
    // inserting needed data
    auto nodesNumber = graph->get_nNodes();
    auto edgesNumber = graph->get_nEdges();
    auto matrix = graph->getMatrix();
    auto edgeValues = graph->getEVals();

    // creating tables of distances and previous node
    auto distances = new uint64_t [nodesNumber];
    auto previous = new uint64_t [nodesNumber];

    bool hasChanged = false;

    // insterting startup values
    for(int i = 0; i < nodesNumber; i++)
    {
        distances[i] = INT_MAX;
        previous[i] = -1;
    }

    distances[start] = 0;
    Edge *tempEdge = nullptr;

    for(int i = 0; i < nodesNumber - 1; i++)
    {

        for(int source = 0; source < nodesNumber; source++)
        {
            if(distances[source] == INT_MAX)
                continue;

            for(int edge = 0; edge < edgesNumber; edge++)
            {
                if (matrix[source][edge] != -1)
                    continue;

                for(int destination = 0; destination < edgesNumber; destination++)
                {
                    if(matrix[destination][edge] != 1)
                        continue;

                    if (distances[destination] > distances[source] + edgeValues[edge])
                    {
                        distances[destination] = distances[source] + edgeValues[edge];
                        previous[destination] = source;

                        hasChanged = true;
                    }

                    break;
                }

            }
        }

        if(!hasChanged)
            break;
    }

    // variables for creating Path
    auto resultPath = new Path();
    auto currentIndex = finish;
    auto tempPrevious = previous[currentIndex];

    // inserting path into Path object
    do
    {
        if(currentIndex == start)
        {
            resultPath->add(currentIndex, 0);
            break;
        }

        if(distances[currentIndex] == INT_MAX)
            break;

        resultPath->add(currentIndex, distances[currentIndex] - distances[tempPrevious]);

        currentIndex = tempPrevious;
        tempPrevious = previous[currentIndex];

    }while(currentIndex != -1);

    return resultPath;
}

Path* BellmanFord::getSP(AdjacencyList* graph, const uint64_t& start, const uint64_t& finish)
{
    auto nodesNumber = graph->get_nNodes();
    auto edgesNumber = graph->get_nEdges();
    auto edgesTable = graph->get_edgeTab();

    auto returnList = new AdjacencyList(nodesNumber, edgesNumber);

    auto distances = new uint64_t [nodesNumber];
    auto previous = new uint64_t [nodesNumber];

    bool hasChanged = false;

    for(int i = 0; i < nodesNumber; i++)
    {
        distances[i] = INT_MAX;
        previous[i] = -1;
    }

    distances[start] = 0;
    for(int i = 0; i < nodesNumber - 1; i++)
    {
        for(int j = 0; j < nodesNumber; j++)
        {
            if(distances[j] == INT_MAX)
                continue;

            auto tempEdge = edgesTable[j];

            while (tempEdge != nullptr)
            {
                if (distances[tempEdge->dest] > distances[tempEdge->src] + tempEdge->cost) {
                    distances[tempEdge->dest] = distances[tempEdge->src] + tempEdge->cost;
                    previous[tempEdge->dest] = tempEdge->src;

                    hasChanged = true;
                }

                if (tempEdge->next != nullptr)
                    tempEdge = tempEdge->next;
                else
                    break;
            }

            if (!hasChanged)
                break;
        }
    }

    // variables for creating Path
    auto resultPath = new Path();
    auto currentIndex = finish;
    auto tempPrevious = previous[currentIndex];

    do
    {
        if(currentIndex == start)
        {
            resultPath->add(currentIndex, 0);
            break;
        }

        if(distances[currentIndex] == INT_MAX)
            break;

        resultPath->add(currentIndex, distances[currentIndex] - distances[tempPrevious]);

        currentIndex = tempPrevious;
        tempPrevious = previous[currentIndex];

    }while(currentIndex != -1);

    return resultPath;
}


int BellmanFord::getMin(const bool* visited, const bool* toRelax, const size_t& size)
{
    for(int i = 0; i < size; i++)
        if(visited[i] && toRelax[i])
            return i;
    return -1;
}