#ifndef WAV_H
#define WAV_H

#include "waveheader.h"

class Wav {

    unsigned char* buffer = NULL;
    wav_header waveHeader;
public:
    Wav() = default;
    //virtual ~Wav();
	void readFile(const std::string &fileName);
    void writeFile(const std::string &outFileName);
    //unsigned char *getBuffer();
    //int getBufferSize() const;
};


#endif