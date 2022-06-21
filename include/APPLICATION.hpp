//
// Created by thero on 23.05.2022.
//

#ifndef SDIZO_PROJ_P2_APPLICATION_HPP
#define SDIZO_PROJ_P2_APPLICATION_HPP
#include "../include/SDIZO_PROJ.hpp"

class App
{
private:

    Tests tester;
    FileManager fman;

    IncidenceMatrix *mat = nullptr;
    AdjacencyList *list = nullptr;

    int mMain();
    int mMST();
    int mSP();

    int gLoad();

public:

    int run();
};

#endif //SDIZO_PROJ_P2_APPLICATION_HPP
