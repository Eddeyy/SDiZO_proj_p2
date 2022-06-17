#include <iostream>
#include "../include/SDIZO_PROJ.hpp"

int main()
{
    int64_t data[] = {0, 1, 5,
                      1, 2, 5,
                      2, 0, 5,
                      0, 2, 13};

    IncidenceMatrix list(3,4, data);


    list.add(2,1,2);

    list.print();


    return 0;
}
