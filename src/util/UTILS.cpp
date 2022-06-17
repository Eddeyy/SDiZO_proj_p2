//
// Created by thero on 19.03.2022.
//
#include "../../include/util/UTILS.hpp"

/*
* Checks if given path in the windows format style exists and is reachable.
*/
bool ut::is_path_exists(const std::string& s)
{
    struct stat buffer;
    return (stat(s.c_str(), &buffer) == 0);
}

/*
* Uses the direct.h libraries' _mkdir(const char*) function to create given directory
* starting from the executable file folder.
*/
void ut::make_directory(const std::string& s)
{
    if (_mkdir(s.c_str()) != 0)
    {
        throw ut::utilityException("Unable to create directory \"" + s + "\"");
    }
}

/*
* Looks for given file within a directory and checks it's existance.
* Returns the according bool value.
*/
bool ut::file_exists(const std::string& fileName, const std::string& dir)
{
    std::ifstream infile(dir + fileName);
    return infile.good();
}

/*
* A basic console logging function.
*/
void ut::to_console(const std::string &message)
{
    std::cout << "\t" << message << std::endl;
}

ut::utilityException::utilityException(const std::string& msg)
: error_message{msg}
{};

