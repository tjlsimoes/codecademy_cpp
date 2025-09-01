#define _DEBUG 1
#ifdef _WIN32
	#define PLATFORM "Windows"
#elif defined(__linux__)
	#define PLATFORM "Linux"
#elif defined(__APPLE__)
	#define PLATFORM "macOS"
#else
	#define PLATFORM "Unsupported platform"
	#error "This platform is not supported"
#endif

#define TIME_POINT chrono::high_resolution_clock::time_point
#define NOW chrono::high_resolution_clock::now()
#define DURATION(start, end) chrono::duration_cast<chrono::microseconds>((end) - (start))

using namespace std;