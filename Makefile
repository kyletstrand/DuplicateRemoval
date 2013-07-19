all: DuplicateRemoval

DuplicateRemoval: DuplicateRemoval.o
	g++ DuplicateRemoval.o -o DuplicateRemoval

DuplicateRemoval.o: DuplicateRemoval.cxx
	g++ -c DuplicateRemoval.cxx

clean:
	rm -rf *o DuplicateRemoval
