# Compiler options
CFLAGS = -g -std=c++11 -Wall --pedantic

BigUnsigned.o:	BigUnsigned.hh BigUnsigned.cc NumberlikeArray.hh
	g++ -c $(CFLAGS) BigUnsigned.cc

testBigUnsigned.o:  testBigUnsigned.cpp BigUnsigned.hh
	g++ -c $(CFLAGS) testBigUnsigned.cpp

testBigUnsigned:  testBigUnsigned.o BigUnsigned.o
	g++ -o testBigUnsigned $(CFLAGS) testBigUnsigned.o BigUnsigned.o

# A dependancy-less rule.  Always executes target when invoked.
clean:	
	rm *.o

# A target-less rule.  Used to test and rebuild anything listed
# in the dependency list.
all:	BigUnsigned.o testBigUnsigned.o testBigUnsigned
