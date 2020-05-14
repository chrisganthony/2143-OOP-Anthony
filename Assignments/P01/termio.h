#pragma once

// Define whether we are using Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)

#define WINDOWS true
#endif

// Include for all platforms
#include <chrono>
#include <codecvt>
#include <iostream>
#include <regex>
#include <string>
#include <thread>
#include <vector>

// Include only for Windows
#if defined(WINDOWS)
#include <fcntl.h>
#include <io.h>
#include <windows.h>
#else

// Include only for *nix
#include <unistd.h>
#endif

namespace Term{

using std::cout;
using std::ostream;
using std::string;
using std::to_string;
using std::vector;
using std::wcout;
using std::wostream;




/* ██████╗ ██████╗ ██████╗ ████████╗ ██████╗ ████████╗██╗ ██╗██████╗ ███████╗███████╗


* ██╔══██╗██╔══██╗██╔═══██╗╚══██╔══╝██╔═══██╗╚══██╔══╝╚██╗ ██╔╝██╔══██╗██╔════╝██╔════╝


* ██████╔╝██████╔╝██║ ██║ ██║ ██║ ██║ ██║ ╚████╔╝ ██████╔╝█████╗ ███████╗


* ██╔═══╝ ██╔══██╗██║ ██║ ██║ ██║ ██║ ██║ ╚██╔╝ ██╔═══╝ ██╔══╝ ╚════██║


* ██║ ██║ ██║╚██████╔╝ ██║ ╚██████╔╝ ██║ ██║ ██║ ███████╗███████║


* ╚═╝ ╚═╝ ╚═╝ ╚═════╝ ╚═╝ ╚═════╝ ╚═╝ ╚═╝ ╚═╝ ╚══════╝╚══════╝


*


* ██╗ ██████╗ ██████╗ ███╗ ██╗███████╗████████╗ █████╗ ███╗ ██╗████████╗███████╗


* ██║ ██╔════╝██╔═══██╗████╗ ██║██╔════╝╚══██╔══╝██╔══██╗████╗ ██║╚══██╔══╝██╔════╝


* ████████╗ ██║ ██║ ██║██╔██╗ ██║███████╗ ██║ ███████║██╔██╗ ██║ ██║ ███████╗


* ██╔═██╔═╝ ██║ ██║ ██║██║╚██╗██║╚════██║ ██║ ██╔══██║██║╚██╗██║ ██║ ╚════██║


* ██████║ ╚██████╗╚██████╔╝██║ ╚████║███████║ ██║ ██║ ██║██║ ╚████║ ██║ ███████║


* ╚═════╝ ╚═════╝ ╚═════╝ ╚═╝ ╚═══╝╚══════╝ ╚═╝ ╚═╝ ╚═╝╚═╝ ╚═══╝ ╚═╝ ╚══════╝
* ANSI Shadow font
*
*/
/**
* TermIO Color codes, used to choose foreground and background
* in the Color object
*/

const unsigned short DEFAULT = 0;
const unsigned short BLACK = 1;
const unsigned short RED = 2;
const unsigned short YELLOW = 3;
const unsigned short GREEN = 4;

}
