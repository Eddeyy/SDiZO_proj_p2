//
// Created by thero on 20.06.2022.
//
#include "../../include/util/U_FILE_MAN.h"

FileManager::FileManager()
:tab{nullptr}
{
    this->resPath = "Files/results.csv";
    this->resFile.open(this->resPath.c_str(), std::fstream::out | std::fstream::trunc);

    this->resFile.seekp(0);
    this->resFile.clear();

    if(resFile.good())
    {
        this->resFile << "algorithm;" << "representation;" << "nodesNumber;" << "density;" << "time;" << std::endl;
        this->resFile.flush();
    }
}

FileManager::~FileManager()
{
    this->graphFile.close();

    delete[] this->tab;

    this->nEdges = 0;
    this->nNodes = 0;
}

void FileManager::readFromFile()
{
    std::cout << "Type file name: \n";
    std::cin >> this->graphPath;

    // opening file
    this->graphFile.open(this->graphPath.c_str(), std::fstream::in);

    this->graphFile.clear();
    this->graphFile.seekg(0);

    if(this->graphFile.good())
    {
        this->graphFile >> this->nEdges >> this->nNodes;

        this->tab =  new int64_t [this->nEdges * 3];

        // inserting data into table
        for(int i = 0; i < this->nEdges * 3; i++)
        {
            this->graphFile >> this->tab[i];
        }
    }
}

void FileManager::writeToFile(const std::string& alg, const std::string& rep, const uint64_t& nNodes_, const uint64_t & density_, const double& time_)
{
    if(this->resFile.good())
    {
        this->resFile << alg << ";" << rep << ";" << nNodes_
                          << ";" << density_ << ";" << time_ << ";" << std::endl;
        this->resFile.flush();
    }
}