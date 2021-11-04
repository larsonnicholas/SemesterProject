//
//
//

#include <iostream>


int main(){
    int userChoice;
    std::string filename;
    std::cout << "Audio Software Start Menu\n\nPlease type the number of what you wish to select (#)\n1. Audio Processing\n2. Exit Program " << std::endl;
    std::cin >> userChoice;
    while (userChoice != 2 && userChoice != 1){
        std::cout << "Incorrect input! Please type \"1\" for option 1, or \"2\" for option 2!";
        std::cin >> userChoice;
    }
    switch(userChoice) {
        case 1: std::cout << "Please enter the filename of the .wav file: ";
            std::cin >> filename;
            std::cout << "Your filename is: " << filename << std::endl;
            return 0;
        case 2: std::cout << "You chose to close the program! If this is not the option you meant to select, that really sucks but it's no longer my problem." << std::endl;
        return 0;
    }
}