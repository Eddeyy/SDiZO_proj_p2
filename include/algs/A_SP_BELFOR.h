//
// Created by thero on 17.06.2022.
//

#ifndef SDIZO_PROJ_P2_A_SP_BELFOR_H
#define SDIZO_PROJ_P2_A_SP_BELFOR_H

#include "../structs/G_EDGE_HEAP.h"
#include "../structs/G_INC_MAT.h"
#include "../structs/G_ADJ_LIST.h"
#include "../structs/G_PATH.h"

class BellmanFord
{
private:
    static bool isEmpty(bool *tab, const size_t& size);
    static int getMin(size_t *table, bool* visited, bool* toRelax, const size_t& size);
public:
    static Path* getSP(IncidenceMatrix* graph, const uint64_t& start);
    static Path* getSP(AdjacencyList* graph, const uint64_t& start);
};

#endif //SDIZO_PROJ_P2_A_SP_BELFOR_H
