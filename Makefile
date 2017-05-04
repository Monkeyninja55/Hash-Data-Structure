all: Project5.o SecondHash.o MainHash.o
	g++ -Wall Project5.o SecondHash.o MainHash.o -o Project5.out

SecondHash.o: SecondHash.cpp
	g++ -Wall -c SecondHash.cpp

MainHash.o: MainHash.cpp
	g++ -Wall -c MainHash.cpp

Project5.o: Project5.cpp
	g++ -Wall -c Project5.cpp

run:
	./Project5.out $(FILE)

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#

val:
	valgrind ./Project5.out $(FILE)