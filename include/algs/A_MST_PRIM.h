//
// Created by thero on 17.06.2022.
//

#ifndef SDIZO_PROJ_P2_A_MST_PRIM_H
#define SDIZO_PROJ_P2_A_MST_PRIM_H
#include "../structs/G_INC_MAT.h"
#include "../structs/G_ADJ_LIST.h"


class Prim
{
private:
    static bool isEmpty(bool* table, size_t size);
public:
    static IncidenceMatrix* genMST(IncidenceMatrix* mat, const uint64_t& start);
    static AdjacencyList* genMST(AdjacencyList* list, const uint64_t& start);
};

#endif //SDIZO_PROJ_P2_A_MST_PRIM_H
