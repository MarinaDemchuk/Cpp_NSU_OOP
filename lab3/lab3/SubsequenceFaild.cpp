#include "SubsequenceFaild.h" 
namespace Exception {
	std:: string SubsequenceFaild::what() {
		std::string error = "sorry, wrong sequence";
		return error;
	}
}