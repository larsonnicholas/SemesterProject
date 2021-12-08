#ifndef WAV_H
#define WAV_H

#include "waveheader.h"

class Wav {

    unsigned char* buffer = NULL;
    wav_header waveHeader;
public:
    Wav() = default;
	void readFile(const std::string &fileName);
    void printMetaData(const std::string &fileName);
    int getBitRate(){
        return waveHeader.bit_depth;
    }
    void writeFile(const std::string &outFileName);
    unsigned char *getBuffer();
    int getBufferSize() const;
};


#endif