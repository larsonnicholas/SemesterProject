#include "wav.h"
#include <fstream>
#include <iostream>
#include <string>

void Wav::readFile(const std::string &fileName){
    std::ifstream fileReader(fileName, std::ios::binary);
    if(!fileReader.is_open()){
        std::cout << "There was an error opening file: " << fileName << std::endl;
        throw fileName;
    
    } else {
        // Now we need to get all of the data from the ifstream into something, the easiest
        //way to do this would be using the read method. 
        // https://www.cplusplus.com/reference/istream/istream/read/
        // wavHeader because in wav.h we're given WaveHeader wavHeader
        //casting because read wants char* when we give it waveHeader which is an unsigned * array
        fileReader.read((char*) &waveHeader, sizeof(wav_header));

        buffer = new unsigned char [waveHeader.data_bytes];
        fileReader.read((char*)buffer, sizeof(waveHeader.data_bytes));
        fileReader.close();
    }
}