#ifndef INTERPRETFILE_H
#define INTERPRETFILE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

class InterpretFile{
    private:
    std::string pathToFile;
    public:
    InterpretFile(std::string path);
    std::vector<std::string> simpleVector();
    std::map<int, std::vector<std::string>> getRecords(int n);


};

#endif