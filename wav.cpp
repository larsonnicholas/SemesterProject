#include "wav.h"
#include <fstream>
#include <iostream>
#include <string>

void Wav::readFile(const std::string &fileName){
    std::ifstream fileReader(fileName, std::ios::binary | std::ios::in);
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
        fileReader.read((char*)buffer, waveHeader.data_bytes);
        fileReader.close();

        
        // // std::cout << waveHeader.riff_header << std::endl;
        // // std::cout << waveHeader.wav_size << std::endl;
        // // std::cout << waveHeader.wave_header << std::endl;
        // // std::cout << waveHeader.fmt_header << std::endl;
        // // std::cout << waveHeader.fmt_chunk_size << std::endl;
        // // std::cout << waveHeader.audio_format << std::endl;
        // // std::cout << waveHeader.num_channels << std::endl;
        // std::cout << "Your sample rate is: " << waveHeader.sample_rate << " Hz" << std::endl;
        // // std::cout << waveHeader.byte_rate << std::endl;
        // // std::cout << waveHeader.sample_alignment << std::endl;
        // std::cout << "Your bits per sample is: " << waveHeader.bit_depth << " bits"<< std::endl;
        // // std::cout << waveHeader.data_header << std::endl;
        // // std::cout << waveHeader.data_bytes << std::endl;
        // if ( waveHeader.num_channels == 1) {
        //     std::cout << "Your audio is in mono" << std::endl;
        // }
        // else if( waveHeader.num_channels == 2){
        //     std::cout << "Your audio is in stereo" << std::endl;
        // }
        
        //test code to ensure the file is being read properly
        //for (int i=0; i<=waveHeader.data_bytes; i++){
        //    printf("|%02hhx|", buffer[i]);
        //}
    }
}

void Wav::printMetaData(const std::string &fileName){
    std::cout << "Your file name is: " << fileName << std::endl;
    std::cout << "Your sample rate is: " << waveHeader.sample_rate << " Hz" << std::endl;
    std::cout << "Your bits per sample is: " << waveHeader.bit_depth << " bits"<< std::endl;
    if ( waveHeader.num_channels == 1) {
            std::cout << "Your audio is in mono" << std::endl;
        }
        else if( waveHeader.num_channels == 2){
            std::cout << "Your audio is in stereo" << std::endl;
        }

}

void Wav::writeFile(const std::string& outFile){
    std::ofstream fileWriter(outFile, std::ios::binary | std::ios::out);
    fileWriter.write((char*) &waveHeader, sizeof(wav_header));
    fileWriter.write((char*)buffer, waveHeader.data_bytes);
    fileWriter.close();
}

unsigned char *Wav::getBuffer(){
    return buffer;
}

int Wav::getBufferSize() const{
    return waveHeader.data_bytes;
}