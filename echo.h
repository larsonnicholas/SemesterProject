#ifndef ECHO_H
#define ECHO_H
#include "normalization.h"

class Echo : public Normalization {
    int delay;
public:
    Echo() = default;
    Echo(int newDelay) : delay(newDelay) {};
    void processBuffer(unsigned char* buffer, int bufferSize) override{
        std::cout << "Echo 8 bit" << std::endl;
    };
    void process16Buffer(unsigned char * buffer, int bufferSize) override {
        std::cout << "Echo 16 bit" << std::endl;
    };
};

#endif