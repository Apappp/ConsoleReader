#include "../include/interpretFile.h"

InterpretFile::InterpretFile(std::string path):pathToFile(path){};

std::vector<std::string> InterpretFile::simpleVector(){
    std::ifstream file("../" + pathToFile);
    if(!file.is_open()){
        throw std::invalid_argument("Wrong path");
    }
    std::vector<std::string> lines;
    std::string line;
    while(getline(file, line)){
        lines.push_back(line);
    }
    file.close();
    return lines;
}

std::map<int, std::vector<std::string>> InterpretFile::getRecords(int n){
    std::vector<std::string> lines = simpleVector();
    int h = lines.size()/n;
    std::map<int, std::vector<std::string>> records;
    std::vector<std::string> record;
    for (int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            record.push_back(lines[n*i+j]);
        }
        records[i] = record;
        record.clear();
    }
    return records;
}