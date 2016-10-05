#include <iostream>

#include "BigUnsigned.hh"

int main() {
	BigUnsigned a(100);
	BigUnsigned b(100);
	BigUnsigned c = a * b;
	BigUnsigned d(10000);
	std::cout << (c == d) << std::endl;
        return 0;
}
