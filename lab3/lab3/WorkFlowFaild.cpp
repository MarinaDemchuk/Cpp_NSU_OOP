#include "WorkFlowFaild.h"
namespace Exception{
	std::string WorkFlowFaild::what() {
		std::string error = "sorry, WorklFlow  fail faild";
		return error;
    }
}