cmake_minimum_required(VERSION 3.20)
project(SDiZO_proj_p2)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}  src/main.cpp
                                include/structs/G_ADJ_LIST.h
                                include/structs/G_EDGE.h
                                include/structs/G_EDGE_HEAP.h
                                include/structs/G_GRAPH.h
                                include/structs/G_INC_MAT.h
                                include/structs/G_PATH.h

                                include/algs/A_MST_KRUSKAL.h
                                include/algs/A_MST_PRIM.h
                                include/algs/A_SP_BELFOR.h
                                include/algs/A_SP_DIJKSTRA.h

                                include/util/UTILS.hpp

                                src/structs/G_ADJ_LIST.cpp
                                src/structs/G_EDGE_HEAP.cpp
                                src/structs/G_INC_MAT.cpp
                                src/structs/G_PATH.cpp
                                src/util/UTILS.cpp src/algs/A_MST_PRIM.cpp)
