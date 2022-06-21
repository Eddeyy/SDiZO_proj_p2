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
    static int getMin(const bool* visited, const bool* toRelax, const size_t& size);
public:
    static Path* getSP(IncidenceMatrix* graph, const uint64_t& start, const uint64_t& finish);
    static Path* getSP(AdjacencyList* graph, const uint64_t& start, const uint64_t& finish);
};

#endif //SDIZO_PROJ_P2_A_SP_BELFOR_H
