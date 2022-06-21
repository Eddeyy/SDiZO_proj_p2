//
// Created by thero on 17.06.2022.
//

#ifndef SDIZO_PROJ_P2_A_MST_KRUSKAL_H
#define SDIZO_PROJ_P2_A_MST_KRUSKAL_H
#include "../structs/G_INC_MAT.h"
#include "../structs/G_ADJ_LIST.h"

class Kruskal
{
private:
    static bool isEmpty(bool* tab, const size_t& size);
public:
    static IncidenceMatrix* genMST(IncidenceMatrix* graph);
    static AdjacencyList* genMST(AdjacencyList* graph);
};

#endif //SDIZO_PROJ_P2_A_MST_KRUSKAL_H
