//
// Created by thero on 20.06.2022.
//

#include "../../include/util/T_TESTER.h"

constexpr const int Tests::densities[4];
constexpr const int Tests::nodesNumber[5];

Tests::Tests()
{
    this->timer = new Timer();

    this->fm = new FileManager();
}

Tests::~Tests()
{
    delete this->timer;
    delete this->fm;
}

void Tests::MST()
{
    // tests for Prim - list
    for(int d : densities) {

        for (int j : nodesNumber) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphBuilder(j, d);

                this->listForTests = new AdjacencyList(this->gg->getNodesNumber(),
                                                        this->gg->getEdgesNumber(),
                                                        this->gg->getData());

                this->timer->startTimer();
                this->returnList = Prim::genMST(this->listForTests, rand() % j);
                time += timer->stopTimer();

                delete this->gg;
                delete this->listForTests;
                delete this->returnList;
            }

            time /= (double)100;

            this->fm->writeToFile("Prim", "list", j, d, time);
        }
    }

    // tests for Prim - matrix
    for(int d : densities) {

        for (int j : nodesNumber) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphBuilder(j, d);

                this->matrixForTests = new IncidenceMatrix(this->gg->getNodesNumber(),
                                                           this->gg->getEdgesNumber(),
                                                           this->gg->getData());

                this->timer->startTimer();
                this->returnMatrix = Prim::genMST(this->matrixForTests, rand() % j);
                time += timer->stopTimer();

                delete this->gg;
                delete this->matrixForTests;
                delete this->returnMatrix;
            }

            time /= (double)100;

            this->fm->writeToFile("Prim", "matrix",  j, d, time);
        }
    }

    // tests for Kruskal - list
    for(int d : densities) {

        for (int j : nodesNumber) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphBuilder(j, d);

                this->listForTests = new AdjacencyList(this->gg->getNodesNumber(),
                                                        this->gg->getEdgesNumber(),
                                                        this->gg->getData());

                this->timer->startTimer();

                this->returnList = Kruskal::genMST(this->listForTests);

                time += timer->stopTimer();

                delete this->gg;
                delete this->listForTests;
                delete this->returnList;
            }

            time /= (double)100;

            this->fm->writeToFile("Kruskal", "list", j, d, time);
        }
    }

    // tests for Kruskal - matrix
    for(int d : densities) {

        for (int j : nodesNumber) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphBuilder(j, d);

                this->matrixForTests = new IncidenceMatrix(this->gg->getNodesNumber(),
                                                           this->gg->getEdgesNumber(),
                                                           this->gg->getData());

                this->timer->startTimer();
                this->returnMatrix = Kruskal::genMST(this->matrixForTests);
                time += timer->stopTimer();

                delete this->gg;
                delete this->matrixForTests;
                delete this->returnMatrix;
            }

            time /= (double)100;

            this->fm->writeToFile("Kruskal", "matrix",  j, d, time);
        }
    }

}

void Tests::shortestPath()
{
    // tests for Bellman - list
    for(int d : densities) {

        for (int j : nodesNumber) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphBuilder(j, d);

                this->listForTests = new AdjacencyList(this->gg->getNodesNumber(),
                                                        this->gg->getEdgesNumber(),
                                                        this->gg->getData());

                int source = rand() % j;
                int destination = rand() % j;

                while(source == destination)
                {
                    destination = rand() % j;
                }

                this->timer->startTimer();
                this->returnPath = BellmanFord::getSP(this->listForTests, source, destination);
                time += timer->stopTimer();

                delete this->gg;
                delete this->listForTests;
                delete this->returnPath;
            }

            time /= (double)100;

            this->fm->writeToFile("Bellman", "list", j, d, time);
        }
    }

    // tests for Bellman - matrix
    for(int d : densities) {

        for (int j : nodesNumber) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphBuilder(j, d);

                this->matrixForTests = new IncidenceMatrix(this->gg->getNodesNumber(),
                                                           this->gg->getEdgesNumber(),
                                                           this->gg->getData());

                int source = rand() % j;
                int destination = rand() % j;

                while(source == destination)
                {
                    destination = rand() % j;
                }

                this->timer->startTimer();
                this->returnPath = BellmanFord::getSP(this->matrixForTests, source, destination);
                time += timer->stopTimer();

                delete this->gg;
                delete this->matrixForTests;
                delete this->returnPath;
            }

            time /= (double)100;

            this->fm->writeToFile("Bellman", "matrix", j, d, time);
        }
    }

    // tests for Dijkstra - list
    for(int d : densities) {

        for (int j : nodesNumber) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphBuilder(j, d);

                this->listForTests = new AdjacencyList(this->gg->getNodesNumber(),
                                                        this->gg->getEdgesNumber(),
                                                        this->gg->getData());

                int source = rand() % j;
                int destination = rand() % j;

                while(source == destination)
                {
                    destination = rand() % j;
                }

                this->timer->startTimer();
                this->returnPath = Dijkstra::getSP(this->listForTests, source, destination);
                time += timer->stopTimer();

                delete this->gg;
                delete this->listForTests;
                delete this->returnPath;
            }

            time /= (double)100;

            this->fm->writeToFile("Dijkstra", "list", j, d, time);
        }
    }

    // tests for Dijkstra - matrix
    for(int d : densities) {

        for (int j : nodesNumber) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphBuilder(j, d);

                this->matrixForTests = new IncidenceMatrix(this->gg->getNodesNumber(),
                                                           this->gg->getEdgesNumber(),
                                                           this->gg->getData());

                int source = rand() % j;
                int destination = rand() % j;

                while(source == destination)
                {
                    destination = rand() % j;
                }

                this->timer->startTimer();
                this->returnPath = Dijkstra::getSP(this->matrixForTests, source, destination);
                time += timer->stopTimer();

                delete this->gg;
                delete this->matrixForTests;
                delete this->returnPath;
            }

            time /= (double)100;

            this->fm->writeToFile("Dijkstra", "matrix", j, d, time);
        }
    }
}

void Tests::allTests()
{
    MST();
    shortestPath();
}