#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "wav.h"
#include <vector>

class Processor { 
public: 
    virtual void processBuffer(unsigned char * buffer , int buffersize) = 0;
    virtual void process16Buffer(unsigned char * buffer, int buffersize) = 0;

};

#endif
