//
// Created by thero on 13.06.2022.
//

#ifndef SDIZO_PROJ_P2_G_EDGE_H
#define SDIZO_PROJ_P2_G_EDGE_H
#include<iostream>

struct Edge
{
    Edge(const uint64_t& _src, const uint64_t & _dest, const int64_t& _cost)
        : src{_src}, dest{_dest}, cost{_cost}, next{nullptr}
    {};

    int64_t cost;
    uint64_t src;
    uint64_t dest;

    Edge * next;
};

#endif //SDIZO_PROJ_P2_G_EDGE_H
