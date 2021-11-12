//
//
//

#include <iostream>
//#include "processor.h"
#include "wav.h"


int main(){
    int userChoice;
    std::string filename;
    std::cout << "Audio Software Start Menu\n\nPlease type the number of what you wish to select (#)\n1. Audio Processing\n2. Exit Program " << std::endl;
    std::cin >> userChoice;
    while (userChoice != 2 && userChoice != 1){
        std::cout << "Incorrect input! Please type \"1\" for option 1, or \"2\" for option 2: ";
        std::cin >> userChoice;
    }
    if (userChoice == 2) { 
        std::cout << "You chose to exit the file! If you did not chose this option, well that's too bad it's already not my problem anymore..." << std::endl;
        return 0;
    }
    else {
            std::cout << "Please enter the filename of the .wav file: ";
            std::cin >> filename;
            std::cout << "Your filename is: " << filename << std::endl;
            std::size_t fileTrial = filename.rfind(".wav", 0 );
            std::cout << fileTrial << std::endl;
            if (fileTrial == -1) {
                std::cout << "This is not a .wav file!" << std::endl;
            } else if (fileTrial > 0) {
                std::cout << "Proper file type!" << std::endl;
            }
            else {
                std::cout << "Something is wrong with how this file is formatted..." << std::endl;
            }
            
            return 0;
    }
//const std::string testfile = "testing.wav";
//const std::string limitfile = "limit.wav";
//const std::string noisefile = "noise.wav";
//    Wav wav;
//    wav.readFile(testfile);
//    Processor *processor = new NoiseGate(10);
//    processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
//    wav.writeFile("echos.wav");
//
//    Follow the pattern above to generate the limit and noise files
//    using the filenames provided

}
