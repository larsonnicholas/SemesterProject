wave: main.o wav.o waveheader.o
	g++ -o main main.o
main.o: main.cpp
	g++ -c main.cpp
wav.o: wav.cpp wav.h waveheader.h
	g++ -c wav.cpp
waveheader.o: waveheader.h
	g++ -c waveheader.h
clean:
	rm *.o wave