#include "../include/menu.h"

Menu::Menu(std::string pathToPreset){
    try{
        InterpretFile file("menus/" + pathToPreset);
        items = file.simpleVector();
        title = items[0];
        items.erase(items.begin());
        n = items.size();
    }
    catch(const std::invalid_argument e){
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void Menu::showList(){
    std::cout << "\033[H\033[2J" << std::flush;
    std::cout << " ------ " << title << " ------\n" << std::endl;
    int i = 1;
    for (auto item : items){
        std::cout << " " << i << ") " << item << std::endl;
        i++;
    }
    if(errorMessage){
        std::cout << "\nOut of range element. Try again.";
    }
    std::cout << "\nChoose from the list:";

}

int Menu::choose(){
    showList();
    errorMessage = false;
    std::string input;
    
    try{
        std::cin >> input;
        int inputi = std::stoi(input);
        if ((inputi <=0)||(inputi > n)){
            errorMessage = true;
            choose();

        }
        return stoi(input);

    }
    catch(const std::invalid_argument e){
        errorMessage = true;
        choose();
    }
    
    return 0;
}

std::vector<std::string> Menu::getItems(){
    return items;
}