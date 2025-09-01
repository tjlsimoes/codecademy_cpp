#include "functions.hpp"
#include "DataHolder.hpp"

using namespace std;

void	runToolKitDemo()
{
	std::cout << "Midpoint: " << midpoint<int>(100,200) << std::endl;

	std::string	part1 = "chassis";
	std::string	part2 = "engine";

	swapValues<std::string>(part1,part2);
	std::cout
	<< "First word: " << part1 << "\n"
	<< "Second word: " << part2
	<< std::endl;

	DataHolder<float>	specialNumber(2.71, 1.618, 9.8);
	std::cout << "Value: " << specialNumber.getValue() << std::endl;

	DataHolder<std::string>	robotName("Codey the Robot");
	std::cout << "Value: " << robotName.getValue() << std::endl;
}

int main() {
	std::cout << "Midpoint: " << midpoint(10, 20) << std::endl;
	std::cout << "Midpoint: " << midpoint(2.71, 3.14) << std::endl;

	std::cout << "------------------------------" << std::endl;

	int	firstNumber = 5;
	int	secondNumber = 10;

	swapValues(firstNumber, secondNumber);
	std::cout
	<< "First number: " << firstNumber << "\n"
	<< "Second number: " << secondNumber
	<< std::endl;

	std::cout << "------------------------------" << std::endl;


	std::string	greeting = "hello";
	std::string	planet = "world";
	swapValues(greeting, planet);
	std::cout
	<< "Greeting word: " << greeting << "\n"
	<< "Planet word: " << planet
	<< std::endl;

	std::cout << "------------------------------" << std::endl;

	DataHolder<int>	testNumber(42, 0, 100);
	std::cout << "Value: " << testNumber.getValue() << std::endl;

	std::cout << "------------------------------" << std::endl;
	testNumber.setValue(75);
	std::cout << "Value: " << testNumber.getValue() << std::endl;

	std::cout << "------------------------------" << std::endl;
	testNumber.setValue(150);
	std::cout << "Value: " << testNumber.getValue() << std::endl;

	std::cout << "------------------------------" << std::endl;
	DataHolder<std::string>	testString("robotics lab");
	std::cout << "Value: " << testString.getValue() << std::endl;

	std::cout << "------------------------------" << std::endl;
	std::cout << "------------------------------" << std::endl;
	runToolKitDemo();

}
