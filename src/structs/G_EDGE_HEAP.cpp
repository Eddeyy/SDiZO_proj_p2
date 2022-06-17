//
// Created by thero on 17.06.2022.
//
#include "../../include/structs/G_EDGE_HEAP.h"

Heap::Heap()
{
    this->size = 0;
}

Heap::~Heap()
{
    if(this->size == 0)
    {
        this->tab = nullptr;
        return;
    }

    delete[] this->tab;
    this->tab = nullptr;
    this->size = 0;
}

void Heap::heapify(int i)
{
    int min {i}, left {2*i + 1}, right {2*i + 2};

    if(left < this->size && tab[left]->cost < tab[min]->cost)
        min = left;

    if(right < this->size && tab[right]->cost < tab[min]->cost)
        min = right;

    if(min != i)
    {
        std::swap(tab[i], tab[min]);

        heapify(min);
    }
}


Edge* Heap::operator[](int position)
{
    if(position < 0 || position >= this->size)
        throw new std::out_of_range("You are out of range");

    else
        return *(tab+ position);
}


void Heap::push(Edge* edge)
{
    if(this-> size == 0)
    {
        this->size++;
        this->tab= new Edge* [this->size];
        this->tab[0] = edge;

        return;
    }

    this->size++;

    auto temptab= new Edge * [this->size];

    // rewriting old data to temporary tab
    for(int i = 0; i < this->size - 1; i++)
    {
        temptab[i] = this->tab[i];
    }

    // adding element to the end of tab
    temptab[this->size - 1] = edge;

    // deleting old tab
    delete[] this->tab;

    this->tab= temptab;

    this->buildHeap();
}

Edge* Heap::pop()
{
    if(this->size == 0)
        return nullptr;

    auto returnEdge = this->tab[0];

    if(this->size == 1)
    {
        this->size--;
        delete[] tab;
        return returnEdge;
    }

    std::swap(this->tab[0], this->tab[this->size - 1]);

    this->size--;

    this->tab[this->size] = nullptr;

    buildHeap();

    return returnEdge;
}

void Heap::printHeap()
{
    for(size_t i = 0; i < this->size; i++)
    {
        std::cout << "[" << i << "] -> " << this->tab[i]->cost << "\n";
    }
}

void Heap::buildHeap()
{
    size_t startIndex {(this->size / 2) - 1};

    for(size_t i = startIndex; i >= 0; i--)
        heapify(i);
}