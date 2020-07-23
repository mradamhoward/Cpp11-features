#include "Sample.h"
#include <iostream>
Sample::Sample() {
	std::cout << "Constructor" << "\n";
}

Sample::~Sample() {
	std::cout << "Destructor" << "\n";
}

void Sample::foo() {
	std::cout << "foo function invoked" << "\n";
}