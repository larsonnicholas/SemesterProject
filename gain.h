#ifndef GAIN_H
#define GAIN_H
#include "normalization.h"

class Gain : public Normalization {
    double gain;
public:
    Gain() = default;
    Gain(double gainAdjust) : gain(gainAdjust) {};
    
    void processBuffer(unsigned char* buffer, int bufferSize) override{
        std::cout << "Gain processor" << std::endl;
    };
    void process16Buffer(unsigned char * buffer, int bufferSize) override {
        std::cout << "Gain 16 bit" << std::endl;
    };
};

#endif