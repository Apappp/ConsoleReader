#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>
#include "../include/interpretFile.h"
#include <restclient-cpp/restclient.h>


class Menu{
    private:
    std::vector<std::string> items;
    std::string title;
    bool errorMessage = false;
    int n;
    public:
    Menu(std::string pathToPreset);
    void showList();
    int choose();
    std::vector<std::string> getItems();
};

#endif