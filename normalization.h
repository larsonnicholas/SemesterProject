#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include "processor.h"

class Normalization : public Processor{
public:
    Normalization() = default;
    void processBuffer(unsigned char* buffer, int bufferSize) override{
        std::cout << "Normalized" << std::endl;
        std::cout << bufferSize << std::endl;
        std::vector<float> newBuffer;
        std::cout << bufferSize << std::endl;
        std::cout << newBuffer.size() << std::endl;
        for (int i = 0; i<bufferSize; i++){
            newBuffer.push_back((float)buffer[i] / 255); 
         }
        std::cout << newBuffer.size() << std::endl;
        float maxValue;
        for(int i = 0; i<bufferSize; i++){
            if (newBuffer[i] > maxValue) {
                maxValue = newBuffer[i];
            }
        }
        std::cout << "\n" << maxValue << std::endl;
        for (int i = 0; i<bufferSize; i++){
            newBuffer[i] = newBuffer[i] / maxValue;
            newBuffer[i] = newBuffer[i] * 255;
            buffer[i] = (unsigned char)newBuffer[i];
        }
    };
    void process16Buffer(unsigned char* buffer, int bufferSize) override{
        std::cout << "Normalized 16" << std::endl;
        std::vector<float> newBuffer;
        for (int i; i<bufferSize; i++){
            newBuffer.push_back((float)buffer[i]/32657);
        }
    };
};

#endif