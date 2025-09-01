#include "Logger.hpp"
using namespace std;

TIME_POINT Logger::startTime = NOW;

void Logger::logLocation(const std::string& message,
                         const std::string& file,
                         int line,
                         const std::string& function) {
	std::cout << "[LOG]" << file << ":" << line << " "
	<< "(" << function << ")" << " - " << message << std::endl;

}

void Logger::startTimer() {
	startTime = NOW;
}

void Logger::stopTimer(const std::string& function) {
	TIME_POINT endTime = NOW;
	auto duration = DURATION(startTime, endTime);
	std::cout
	<< "[TIMER] (" << function << " - Duration: "
	<< duration.count() << " µs"
	<< std::endl;

}

void Logger::printCompileInfo() {
	std::cout
	<< "Date: " << __DATE__ << "\n"
	<< "Time: " << __TIME__
	<< std::endl;
	#ifdef __GNU__
		std::cout
		<< "Compiler: GCC " 
		<< __GNU__ << "." << __GNUC_MINOR__
		<< std::endl;
	#elif defined(__clang__)
		std:cout
		<< "Compiler: Clang "
		<< __clang_major__ << "." << __clang_minor__
		<< std::endl;
	#elif defined(_MSC_VER)
		std::cout
		<< "Compiler: MSVC " << _MSC_VER
		<< std::endl 	
	#endif
	
	std::cout
	<< "Platform: "	<< PLATFORM
	<< std::endl;
}
