#include "ReaderException.h"
namespace Exception {
	std::string ReadException::what() {
		std::string error = "sorry, readfile fild";
		return error;
	}
}