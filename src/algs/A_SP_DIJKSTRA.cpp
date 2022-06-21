//
// Created by thero on 20.06.2022.
//
#include "../../include/algs/A_SP_DIJKSTRA.h"


Path* Dijkstra::getSP(AdjacencyList *graph, const int64_t& start, const int64_t& finish)
{
    // initializing necessary variables
    auto nodesNumber = graph->get_nNodes();
    auto edgesNumber = graph->get_nEdges();
    auto edgesTable = graph->get_edgeTab();

    auto heap = new Heap();
    auto returnList = new AdjacencyList(nodesNumber, edgesNumber);

    auto distances = new int64_t [nodesNumber];
    auto previous = new int64_t [nodesNumber];
    auto visitedNodes = new bool [nodesNumber];
    auto nodesToRelax = new bool [nodesNumber];

    // inserting default values to the arrays
    for(int i = 0; i < nodesNumber; i++)
    {
        distances[i] = INT64_MAX;
        previous[i] = -1;
        visitedNodes[i] = false;
        nodesToRelax[i] = true;
    }

    // inserting edge heap
    auto tempEdge = edgesTable[start];

    while(tempEdge != nullptr)
    {
        heap->push(tempEdge);
        tempEdge = tempEdge->next;
    }

    // setting source variables to default
    distances[start] = 0;
    visitedNodes[start] = true;
    nodesToRelax[start] = false;
    int64_t currentNode = start;

    Edge *minNode = nullptr;

    // main algorithm
    while(isEmpty(visitedNodes, nodesNumber))
    {
        if(heap->getSize() != 0)
        {
            // poping min current node edge
            minNode = heap->pop();

            // dijsktra condition
            if(distances[minNode->dest] > distances[minNode->src] + minNode->cost)
            {
                distances[minNode->dest] = distances[minNode->src] + minNode->cost;
                previous[minNode->dest] = minNode->src;
            }

            continue;
        }

        // setting current node flags
        nodesToRelax[currentNode] = false;
        visitedNodes[currentNode] = true;

        // getting new node to dheck
        currentNode = getMin(distances, visitedNodes, nodesToRelax, nodesNumber);

        // if there is no right node, the algorithm will end
        if(currentNode == -1)
            break;

        // pushing into heap edges of current node
        tempEdge = edgesTable[currentNode];
        while(tempEdge != nullptr)
        {
            heap->push(tempEdge);
            tempEdge = tempEdge->next;
        }

    }

    // variables for creating Path
    auto resultPath = new Path();
    auto currentIndex = finish;
    auto tempPrevious = previous[currentIndex];

    // creating path
    do
    {
        if(currentIndex == start)
        {
            resultPath->add(currentIndex, 0);
            break;
        }

        if(distances[currentIndex] == INT64_MAX)
            break;

        resultPath->add(currentIndex, distances[currentIndex] - distances[tempPrevious]);

        currentIndex = tempPrevious;
        tempPrevious = previous[currentIndex];

    }while(currentIndex != -1);

    // clearing and realeasing memory
    minNode = nullptr;
    tempEdge = nullptr;

    delete heap;
    delete[] previous;
    delete[] distances;
    delete[] nodesToRelax;

    return resultPath;
}

Path* Dijkstra::getSP(IncidenceMatrix* graph, const int64_t& start, const int64_t& finish)
{
    // inserting needed data
    auto nodesNumber = graph->get_nNodes();
    auto edgesNumber = graph->get_nEdges();
    auto matrix = graph->getMatrix();
    auto edgeValues =  graph->getEVals();

    // creating min heap to sort
    // edges that can be used to create path
    auto heap = new Heap();

    // creating needed tables
    auto distances = new int64_t [nodesNumber];
    auto previous = new int64_t [nodesNumber];
    auto visitedNodes = new bool [nodesNumber];
    auto nodesToRelax = new bool [nodesNumber];

    // filling them with startup value
    for(int i = 0; i < nodesNumber; i++)
    {
        distances[i] = INT_MAX;
        previous[i] = -1;
        visitedNodes[i] = false;
        nodesToRelax[i] = true;
    }

    // inserting edge heap with edges
    // from visited nodes
    for(int i = 0; i < edgesNumber; i++)
    {
        size_t source, destination;

        if(matrix[start][i] == -1)
        {
            source = start;

            for(int j = 0; j < nodesNumber; j++)
                if(matrix[j][i] == 1)
                {
                    destination = j;
                    break;
                }


            heap->push(new Edge(source, destination, edgeValues[i]));
        }
    }

    // setting values for start node
    distances[start] = 0;
    visitedNodes[start] = true;
    nodesToRelax[start] = false;
    int currentNode = start;

    Edge *minEdge = nullptr;

    // main algorith
    while(isEmpty(visitedNodes, nodesNumber))
    {
        // if heap !=0 then there are still edges to check
        if(heap->getSize() != 0)
        {
            // poping min edge
            minEdge = heap->pop();

            // dijsktra condition
            if(distances[minEdge->dest] > distances[minEdge->src] + minEdge->cost)
            {
                distances[minEdge->dest] = distances[minEdge->src] + minEdge->cost;
                previous[minEdge->dest] = minEdge->src;
            }

            continue;
        }

        // setting current node flags
        nodesToRelax[currentNode] = false;
        visitedNodes[currentNode] = true;

        // getting new node to dheck
        currentNode = getMin(distances, visitedNodes, nodesToRelax, nodesNumber);

        // if there is no right node, the algorithm will end
        if(currentNode == -1)
            break;

        // pushing into heap edges of current node
        for(int i = 0; i < edgesNumber; i++)
        {
            size_t source, destination;

            if(matrix[currentNode][i] == -1)
            {
                source = currentNode;

                for(int j = 0; j < nodesNumber; j++)
                {
                    if(matrix[j][i] == 1)
                    {
                        destination = j;
                        break;
                    }
                }

                heap->push(new Edge(source, destination, edgeValues[i]));
            }
        }

    }

    // variables for creating Path
    auto resultPath = new Path();
    auto currentIndex = finish;
    auto tempPrevious = previous[currentIndex];

    // creating path
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

    // clearing and realeasing memory
    minEdge = nullptr;

    delete heap;
    delete[] previous;
    delete[] distances;
    delete[] nodesToRelax;

    return resultPath;
}

bool Dijkstra::isEmpty(const bool *table, const size_t& size)
{
    for(int i = 0; i < size; i++)
        if(!table[i])
            return true;
    return false;
}

int Dijkstra::getMin(int64_t *table, bool* visited, bool *toRelax, const size_t& size)
{
    int64_t min = INT64_MAX;
    int index =  -1;

    for(int i = 0; i < size; i++)
    {
        if(table[i] < min && !visited[i] && toRelax[i])
        {
            index = i;
            min = table[i];
        }
    }

    return index;
}