//
// Created by thero on 20.06.2022.
//

#include "../include/APPLICATION.hpp"

int App::run()
{
    return mMain();
}

int App::mMain()
{
    std::string help = "\n======MAIN======\n"
                       "Type MST to perform MST algorithms.\n"
                       "Type SP to perform shortest path algorithms.\n"
                       "Type LOAD to load a graph.\n"
                       "Type AUTO to perform automatic tests.\n"
                       "Type EXIT to exit program.\n"
                       "Type HELP to show this instruction.\n\n";
    std::string command;

    std::cout << help;
    while(true)
    {
        std::cout << "\nMain : ";
        std::cin >> command;
        for(auto & c : command)
        {
            c = static_cast<char>(toupper(c));
        }

        if(command == "EXIT")
        {
            std::cout << "Bing Chilling\n";
            return EXIT_SUCCESS;
        }
        else if(command =="HELP")
        {
            std::cout << help;
        }
        else if(command == "MST")
        {
            if(mat!=nullptr || list!=nullptr)
                mMST();
            else
                std::cerr << "\nPlease load a graph first";
        }
        else if(command == "SP")
        {
            if(mat!=nullptr || list!=nullptr)
                mSP();
            else
                std::cerr << "\nPlease load a graph first";
        }
        else if(command == "LOAD")
        {
            this->fman.readFromFile();

            if(mat!=nullptr)
                delete mat;
            if(list!=nullptr)
                delete list;

            mat = new IncidenceMatrix(fman.getNodesNumber(),fman.getEdgesNumber(), fman.getData());
            list = new AdjacencyList(fman.getNodesNumber(),fman.getEdgesNumber(), fman.getData());
        }
        else if(command == "AUTO")
        {
            if(mat!=nullptr || list!=nullptr)
            {
                std::cerr << "<<Performing auto tests>>";
                this->tester.allTests();
            }
            else
                std::cerr << "\nPlease load a graph first";
        }
        else
            std::cerr << "\nUnknown command\n";


        fflush(stdin);
    }
}

int App::mMST()
{
    std::string help = "\n======MST======\n"
                       "Type PRIM to get mst from prim algorithm.\n"
                       "Type KRUSKAL to get mst from kruskal algorithm.\n"
                       "Type EXIT to exit program.\n"
                       "Type HELP to show this instruction.\n\n";
    std::string command;
    uint64_t start;

    std::cout << help;
    while(true)
    {
        std::cout << "\nMST : ";
        std::cin >> command;

        for (auto &c: command)
        {
            c = static_cast<char>(toupper(c));
        }

        if (command == "EXIT")
        {
            system("cls");
            return EXIT_SUCCESS;
        }
        else if(command =="HELP")
        {
            std::cout << help;
        }
        else if(command == "PRIM")
        {
            fflush(stdin);
            std::cout << "\nStarting node : ";
            std::cin >> start;

            Prim::genMST(mat,start)->print();
            std::cout << std::endl;
            Prim::genMST(list,start)->print();
        }
        else if(command == "KRUSKAL")
        {
            Kruskal::genMST(mat)->print();
            std::cout << std::endl;
            Kruskal::genMST(list)->print();
        }
        else
            std::cerr << "\nUnknown command\n";


        fflush(stdin);
    }
}

int App::mSP()
{
    std::string help = "\n======SP======\n"
                       "Type DIJKSTRA to get shortest path via dijkstra's algorithm\n"
                       "Type BF to get shortest path via bellman-ford's algorithm\n"
                       "Type EXIT to exit program.\n"
                       "Type HELP to show this instruction.\n\n";
    std::string command;
    uint64_t start;
    uint64_t finish;

    std::cout << help;
    while(true)
    {
        std::cout << "\nShortest path : ";
        std::cin >> command;


        for (auto &c: command)
        {
            c = static_cast<char>(toupper(c));
        }

        if (command == "EXIT")
        {
            system("cls");
            return EXIT_SUCCESS;
        }
        else if(command =="HELP")
        {
            std::cout << help;
        }
        else if(command == "DIJKSTRA")
        {
            std::cout << "\nStarting node : ";
            std::cin >> start;
            std::cout << "\nFinish node : ";
            std::cin >> finish;

            Dijkstra::getSP(mat,start,finish)->print();
            std::cout << std::endl;
            Dijkstra::getSP(list,start,finish)->print();
        }
        else if(command == "BF")
        {
            std::cout << "\nStarting node : ";
            std::cin >> start;
            std::cout << "\nFinish node : ";
            std::cin >> finish;

            BellmanFord::getSP(mat, start, finish)->print();
            std::cout << std::endl;
            BellmanFord::getSP(list, start, finish)->print();
        }
        else
            std::cerr << "\nUnknown command\n";


        fflush(stdin);
    }
}
