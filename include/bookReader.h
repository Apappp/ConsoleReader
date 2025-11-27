#ifndef BOOKREADER_H
#define BOOKREADER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <restclient-cpp/restclient.h>
#include "menu.h"

class BookReader{
    private:
    std::string username;
    std::string title;
    std::string lines;
    std::map<std::string, std::string> books;
    public:
    BookReader(std::string username);
    void show();
    bool getBook();
    void searchBook();
    void searching(std::string query);
    void addFavorites();
};

#endif