#include "./ReadFile.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

// #define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define PSAPI_VERSION 1
#include <windows.h>
#include <psapi.h>

bool printOut = false;

using namespace std;