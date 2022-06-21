//
// Created by thero on 20.06.2022.
//

#ifndef SDIZO_PROJ_P2_T_TESTER_H
#define SDIZO_PROJ_P2_T_TESTER_H
#include "T_TIMER.h"
#include "U_GRAPHGEN.h"
#include "U_FILE_MAN.h"

#include "../structs/G_ADJ_LIST.h"
#include "../structs/G_INC_MAT.h"
#include "../structs/G_PATH.h"

#include "../algs/A_SP_BELFOR.h"
#include "../algs/A_SP_DIJKSTRA.h"
#include "../algs/A_MST_KRUSKAL.h"
#include "../algs/A_MST_PRIM.h"

class Tests {

    Timer *timer = nullptr;

    FileManager *fm = nullptr;

    AdjacencyList *listForTests = nullptr;
    AdjacencyList *returnList = nullptr;

    IncidenceMatrix *matrixForTests = nullptr;
    IncidenceMatrix *returnMatrix = nullptr;

    Path *returnPath = nullptr;

    GraphBuilder *gg = nullptr;

    constexpr static const int densities[4] = {25, 50, 75, 99};
    constexpr static const int nodesNumber[5] = {10, 20, 30, 40, 50};

    void MST();
    void shortestPath();

public:

    Tests();
    ~Tests();

    void allTests();

};

#endif //SDIZO_PROJ_P2_T_TESTER_H
