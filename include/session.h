#ifndef SESSION_H
#define SESSION_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <restclient-cpp/restclient.h>
#include "menu.h"
#include "login.h"
#include "interpretFile.h"
#include "bookReader.h"

class Session{
    private:
    std::string user;

    public:
    Session(std::string username);
    void dash();
    void favorites();
    void getFavorites();
    void search();
};


#endif 