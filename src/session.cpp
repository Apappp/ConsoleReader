#include "../include/session.h"

Session::Session(std::string username) : user(username){
    RestClient::init();
}

void Session::dash(){
    while(true){
        Menu mainMenu("main");
        switch (mainMenu.choose())
        {
        case 1:
            favorites();
            break;
        case 2:
            search();
            break;
        case 3:
            exit(0);
            break;
        case 4:
            hello();
            break;
        }
    }
}

void Session::favorites(){
    std::cout << "\033[H\033[2J" << std::flush;
    std::cout << " ------ Favorites ------ \n" << std::endl;
    getFavorites();
    Menu favMenu("fav_temp");
    int choice = favMenu.choose();
    std::vector<std::string> items = favMenu.getItems();
    if(choice < (items.size()-1)){
        
    }
}

void Session::getFavorites(){
    InterpretFile f("secret_data/favorites");
    std::map<int, std::vector<std::string>> records = f.getRecords(2);
    std::string rawFavs;
    for (auto record : records){
        if(user==record.second[0]){
            rawFavs = record.second[1];
        }
    }
    if(rawFavs == ""){
        std::cout << " You don't have any favorite books.";
    }
    std::ofstream favFile("../menus/fav_temp");
    if(!favFile.is_open()){
        std::cout << " There has occured an error..";
    }
    else{
        favFile << "Favorites" << std::endl;
        for (auto a : rawFavs){
            if(a=='%'){
                favFile << "\n";
            }
            else{
                favFile << a;
            }
        }
        favFile << std::endl << "Return to main menu";
    }
    favFile.close();
}

void Session::search(){
    BookReader req;
    req.searchBook();
}