#include <iostream>
#include "values.hpp"
#include "Logger.hpp"
// #include  "mode.hpp"
#include "Algorithms.hpp"
using namespace std;

int main() {
	#ifdef _DEBUG
		COMPILE_INFO();
	#endif

	Algorithms::singleLoop();
	Algorithms::doubleLoop();
	Algorithms::tripleLoop();
	return 0;
}
