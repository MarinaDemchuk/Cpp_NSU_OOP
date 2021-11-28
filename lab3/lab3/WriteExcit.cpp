#include "WriteFaild.h"
namespace Exception{
std::string  WriteExceptionFaild::what() {
	std::string error = "writefail faild!";
	return error;
}
}