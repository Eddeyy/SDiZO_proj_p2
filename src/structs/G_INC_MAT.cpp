#include "../../include/structs/G_INC_MAT.h"

//
// Created by thero on 17.06.2022.
//
IncidenceMatrix::IncidenceMatrix(const uint64_t& nNodes, const uint64_t& nEdges)
        :   Graph(nNodes, nEdges)
{
    this->matrix = new int64_t *[nNodes];

    for(size_t i = 0; i < nNodes; i++)
    {
        matrix[i] = new int64_t[nEdges];

        for(size_t j = 0; j < nEdges; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

IncidenceMatrix::IncidenceMatrix(const uint64_t& nNodes, const uint64_t& nEdges, const int64_t *data)
: IncidenceMatrix(nNodes, nEdges)
{
       eVals = new uint64_t[nEdges];

       for(size_t i = 0, dat_i = 0, eVal_i = 0 ;
            i < nEdges ;
            i++, eVal_i++, dat_i++)
       {
           matrix[data[dat_i]][i] = -1;
           dat_i++;
           matrix[data[dat_i]][i] = 1;
           dat_i++;
           eVals[eVal_i] = data[dat_i];
       }
}

IncidenceMatrix::~IncidenceMatrix()
{
    if(this->matrix != nullptr)
    {
        for(int i = 0; i < this->nNodes; i++)
        {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;

        delete[] this->eVals;

        nEdges = 0;
        nNodes = 0;
    }
}

void IncidenceMatrix::add(const uint64_t &src, const uint64_t &dest, const uint64_t &cost)
{
    this->matrix[src][this->usedEdges] = -1;
    this->matrix[dest][this->usedEdges] = 1;
    this->eVals[this->usedEdges] = cost;

    this->usedEdges++;

    densityCalc();
}

void IncidenceMatrix::print()
{
    std::cout << "  E    ";

    for(size_t i = 0; i < this->nEdges; i++)
    {
        std::cout << i << "      ";
    }

    std::cout << "\nV\n";

    for(size_t i = 0; i < this->nNodes; i++)
    {
        std::cout << i << "     ";
        for(size_t j = 0; j < this->nEdges; j++)
        {
            std::cout << std::setw(2) << this->matrix[i][j] << "  |  ";
        }
        std::cout << "\n";
    }
    std::cout << "\nv     ";

    for(size_t i = 0; i < this->nEdges; i++)
    {
        std::cout << std::setw(2) << this->eVals[i] << "  |  ";
    }

    std::cout << "\n";
}

int64_t **IncidenceMatrix::getMatrix()
{
    return this->matrix;
}

uint64_t *IncidenceMatrix::getEVals()
{
    return this->eVals;
}




