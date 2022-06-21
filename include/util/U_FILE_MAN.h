//
// Created by thero on 20.06.2022.
//

#ifndef SDIZO_PROJ_P2_U_FILE_MAN_H
#define SDIZO_PROJ_P2_U_FILE_MAN_H

#include <cstdlib>
#include <fstream>
#include <iostream>

class FileManager {

    int64_t* tab;
    uint64_t nNodes;
    uint64_t nEdges;

    std::fstream graphFile;
    std::string graphPath;

    std::fstream resFile;
    std::string resPath;

public:

    FileManager();

    ~FileManager();

    void readFromFile();

    void writeToFile(const std::string& alg, const std::string& rep, const uint64_t& nNodes_, const uint64_t & density, const double& time);

    int64_t *getData()
    {
        return this->tab;
    }

    uint64_t getNodesNumber() const
    {
        return this->nNodes;
    }

    uint64_t getEdgesNumber() const
    {
        return this->nEdges;
    }
};

#endif //SDIZO_PROJ_P2_U_FILE_MAN_H
