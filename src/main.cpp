#include <iostream>
#include "../include/SDIZO_PROJ.hpp"

int main()
{
    int64_t data[] = {0, 1, 5,
                      1, 2, 5,
                      2, 0, 5,
                      0, 2, 13};

    AdjacencyList list(3,4, data);

    list.print();

    std::cout << "\n";

    Prim::genMST(&list, 0)->print();

    return 0;
}
