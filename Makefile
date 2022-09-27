p7: main.o WNode.o baconFinder.o
	g++ main.o WNode.o baconFinder.o -o p7

main.o: main.cpp
	g++ -c main.cpp

WNode.o: WNode.h WNode.cpp
	g++ -c WNode.cpp

baconFinder.o: baconFinder.h baconFinder.cpp
	g++ -c baconFinder.cpp

clean:
	rm *.o *~ p7