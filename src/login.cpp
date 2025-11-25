#include "../include/login.h"

void hello(){
    Menu intro("intro");
    switch(intro.choose()){
        case 1:
            login();
            break;
        case 2:
            reg();
            break;
        case 3:
            about();
            break;
        case 4:
            exit(0);
            break;
    }
    
}

void login(){
    std::string username;
    std::string password;
    bool exists = false;
    bool err = false;
    int index {};
    InterpretFile accounts("secret_data/accounts");
    std::map<int, std::vector<std::string>> data = accounts.getRecords(3);
    while(!exists){
        std::cout << "\033[H\033[2J" << std::flush;
        std::cout << " ------ " << "login" << " ------\n" << std::endl;
        if(err){
            std::cout << " Wrong username, try again..." << std::endl;
        }
        err = true;
        std::cout << " Enter your login: ";
        std::cin >> username;
        for (auto record : data){
            if(record.second[0] == username){
                index = record.first;
                exists = true;
                err = false;
                break;
            }
        }
    }
    bool correct = false;
    while(!correct){
        std::cout << "\033[H\033[2J" << std::flush;
        std::cout << " ------ Log into " << username << " ------\n" << std::endl;
        if(err){
            std::cout << " Wrong password, Try again..." << std::endl; 
        }
        err = true;
        std::cout << " Enter your password: ";
        disableEcho();
        std::cin >> password;
        restoreEcho();
        if(password==data.at(index)[1]){
            correct = true;
        }
    }
    Session s(username);
    s.dash();
}

void reg(){
    std::cout << "register";
}

void about(){
    std::string r;
    std::cout << "\033[H\033[2J" << std::flush;
    std::cout << " ------ about ------" << std::endl;
    std::cout << "The project allows users to log in to their individual accounts, enabling them to browse and read various poems available in the application." << std::endl;
    std::cin >> r;
    hello();
}

bool checkUsername(std::string username){
    return true;
}