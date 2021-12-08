main: main.o wav.o
	g++ -o main main.o wav.o
main.o: main.cpp normalization.h echo.h gain.h
	g++ -c main.cpp
wav.o: wav.cpp
	g++ -c wav.cpp
clean:
	rm *.o main