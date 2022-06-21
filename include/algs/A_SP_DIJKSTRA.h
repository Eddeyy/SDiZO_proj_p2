//
// Created by thero on 17.06.2022.
//

#ifndef SDIZO_PROJ_P2_A_SP_DIJKSTRA_H
#define SDIZO_PROJ_P2_A_SP_DIJKSTRA_H

#include "../structs/G_EDGE_HEAP.h"
#include "../structs/G_INC_MAT.h"
#include "../structs/G_ADJ_LIST.h"
#include "../structs/G_PATH.h"

class Dijkstra
{
private:
    static bool isEmpty(const bool *tab, const size_t& size);
    static int getMin(int64_t *table, bool* visited, bool* toRelax, const size_t& size);
public:
    static Path* getSP(IncidenceMatrix* graph, const int64_t& start, const int64_t& finish);
    static Path* getSP(AdjacencyList* graph, const int64_t& start, const int64_t& finish);
};

#endif //SDIZO_PROJ_P2_A_SP_DIJKSTRA_H
