#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "wav.h"

class Processor { 
public: 
    virtual void processBuffer(unsigned char * buffer , int buffersize) = 0;

};

#endif
