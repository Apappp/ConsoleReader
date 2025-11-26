#include "../include/bookReader.h"

BookReader::BookReader(std::string username) : username(username){}

void BookReader::show(){
    std::cout << "\033[H\033[2J" << std::flush;
    std::cout << " ------ " << title << " ------ \n" << std::endl;
    std::string setFavorite;
    if(getBook()){
        std::cout << lines << std::endl;
        std::cout << "\nType f to add poem to favorites, type anything else to exit: ";
        std::cin >> setFavorite;
        if(setFavorite == "f"){
            addFavorites();
        }
    }
    else{
        std::cout << "Something went wrong...";
        std::cin >> setFavorite;
    }
}

void BookReader::addFavorites(){
    InterpretFile f("secret_data/favorites");
    std::vector<std::string> rows = f.simpleVector();
    std::ofstream favFile("../secret_data/favorites");
    bool isFound = false;
    if(favFile.is_open()){
        for(int i = 0; i < rows.size(); i++){
            if(rows[i]==username){
                rows[i+1] = rows[i+1] + "%" + title;
                isFound = true;
                for (std::string row : rows){
                    favFile << row << std::endl;
                }
            }
        }
        if(!isFound){
            rows.push_back(username);
            rows.push_back(title);
        }
    }
}

bool BookReader::getBook(){
    lines = books[title];
    if((lines == "")||(lines[0]=='{')){
        return false;
    }
    else {
        return true;
    }
}

void BookReader::searchBook(){
    std::cout << "\033[H\033[2J" << std::flush;
    std::cout << " ------ Search ------ " << std::endl;
    std::cout << " Your query: ";
    std::string query;
    std::cin >> query;
    searching(query);
    Menu resultsMenu("search_temp");
    std::vector<std::string> items = resultsMenu.getItems();
    int choice = resultsMenu.choose();
    if(choice<(items.size()-1)){
        title = items[choice-1];
        show();
    }
    else if(choice==(items.size()-1)){
        searchBook();
    }
}

void BookReader::searching(std::string query){
    int poemCount = 10;
    RestClient::init();    
    RestClient::Response r2 = RestClient::get("https://poetrydb.org/title,poemcount/" + query + ";" + std::to_string(poemCount) + "/title,lines.text");
    std::ofstream results("../menus/search_temp");
    std::istringstream stream(r2.body);
    std::string line;
    results << "Results" << std::endl;
    bool sw = false;
    
    while(std::getline(stream, line)){
        if(sw){
            if(!((line == "title")||(line == "lines"))){
                title = line;
                results << line << std::endl;
            }
            if(line == "lines"){
                sw = false;
            }
        }
        else{
            if(!((line == "title")||(line == "lines"))){
                lines = lines + "\n" + line;
            }
            if(line == "title"){
                books[title] = lines;
                lines = "";
                sw = true;
            }
        }
        
    }
    books[title] = lines;
    lines = "";
    results << "Search again\nReturn to main Menu";
    results.close();

}