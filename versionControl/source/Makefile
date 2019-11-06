main: main.o versionControl.o
	g++ main.o versionControl.o -o main

versionControl.o: versionControl.cc versionControl.h
	g++ -std=c++14 -c versionControl.cc

main.o: main.cc versionControl.h
	g++ -std=c++14 -c main.cc

.PHONY: clean

clean:
	rm *.o main
