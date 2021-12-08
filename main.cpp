//
//
//

#include <iostream>
#include "wav.h"
#include "processor.h"
#include "normalization.h"
#include "echo.h"
#include "gain.h"


int main(){

    int userChoice = 1;
    std::string filename, userfilename;
    while(userChoice != 0) {
    std::cout << "\n\n\nAudio Software Start Menu\n\nPlease type the number of what you wish to select (#)\n0: Exit Program\n1: Audio Processing " << std::endl;
    std::cin >> userChoice;
    while (userChoice != 0 && userChoice != 1){
        std::cout << "Incorrect input! Please type \"0\" for option 0, or \"1\" for option 1 (without \"\" of course): ";
        std::cin >> userChoice;
    }

    if (userChoice == 0) { 
        std::cout << "You chose to exit the file! If you did not chose this option, well that's too bad it's already not my problem anymore..." << std::endl;
        break;
    }
    else {
            std::cout << "Please enter the filename of the .wav file: ";
            std::cin >> filename;

            if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".wav") {
                std::cout << "This is not a .wav file, or you've made a typo!" << std::endl;
                continue;
            } else {
                //Comment out line 41 for final version
                std::cout << "Proper file type!" << std::endl;
                try{
                Wav wav;
                wav.readFile(filename);
                
                } 
                catch(...){
                    continue;
                }
                Wav wav;
                wav.readFile(filename);
                wav.printMetaData(filename);

                std::cout << "\n==Audio Processor Menu==\n0. Exit Program\n1. Echo\n2. Normalization\n3. Gain Adjustment";
                std::cout << "\nPlease enter the option you wish to select: ";
                std::cin >> userChoice;

                while (!(userChoice >=0 && userChoice <=3)){
                    std::cout << "Incorrect input! You must select an option between 0 and 3, try again :";
                    std::cin >> userChoice;
                }

                if(userChoice == 0){
                    std::cout << "You changed your mind, seriously?!" << std::endl;
                }
                else {
                    std::cout << "Please enter the filename you wish to save your new audio to: ";
                    std::cin >> userfilename;
                    
                    //std::cout << "Your output filename is: " << userfilename << std::endl;
                    Processor *processor;
                    
                    switch(userChoice){
                        case 1:
                        std::cout << "Echo!" << std::endl;
                        //Echo
                        if(wav.getBitRate() == 8) {
                        processor = new Echo(10);
                        processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
                        wav.writeFile(userfilename);
                        }
                        else {
                        processor = new Echo(10);
                        processor->process16Buffer(wav.getBuffer(),wav.getBufferSize());
                        wav.writeFile(userfilename);
                        }

                        break;
                       
                        case 2:
                        //Normal
                         std::cout << "Normalization" << std::endl;
                         processor = new Normalization();
                         processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
                         wav.writeFile(userfilename);
                        break;
                        
                        case 3:
                        //Gain
                        std::cout << "Gain Adjustment" << std::endl;
                        //processor = new Gain(1.2);
                        break;
                    }

                    

                    
                }
                continue;
            }
        }
    }
    
            return 0;
    
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
