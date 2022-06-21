//
// Created by thero on 17.06.2022.
//

#ifndef SDIZO_PROJ_P2_G_PATH_H
#define SDIZO_PROJ_P2_G_PATH_H
#include <iostream>

class Path
{
private:

    int64_t * nodes;
    int64_t * costs;

    int64_t cost;

    uint64_t size;
public:

    Path();
    ~Path();

    void add(const int64_t& node, const int64_t& cost);
    void print();
};

#endif //SDIZO_PROJ_P2_G_PATH_H
